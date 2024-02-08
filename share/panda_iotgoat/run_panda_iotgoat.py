#!/usr/bin/env python3

from pandare import Panda

#Get directory of this file
import os
dir_path = os.path.dirname(os.path.realpath(__file__))
kernel_dir = f"{dir_path}/kernels"

ARCH="arm"
MEM="1G"
IMAGE=f"{dir_path}/IoTGoat-raspberry-pi2.img"
KERNEL=f"{kernel_dir}/zImage.armel"
NIMAGE=f"{dir_path}/final-image.img"

qemu_args = [
    '-M', 'virt',
    '-kernel', KERNEL,
    '-device',
    'virtio-blk-pci,drive=drive-virtio-disk0,id=virtio-disk0,bootindex=0',
    '-drive', 'file=%s,format=raw,if=none,id=drive-virtio-disk0' % NIMAGE,
    '-append', 'root=/dev/vda console=ttyS0,115200',
    '-display', 'none',
    '-serial', 'file:console.log',
    '-netdev',
    'user,id=net0,hostfwd=tcp::4433-:443,hostfwd=tcp::2222-:22',
    '-device' ,'virtio-net-device,netdev=net0',
    '-no-reboot',
]

panda = Panda(ARCH, mem=MEM, os="linux", extra_args=qemu_args)

# Set up Operating System Introspection
panda.set_os_name("linux-32-generic")
panda.load_plugin("syscalls2", args = {"load-info": True})
panda.load_plugin("osi", args = {"disable-autoload": True})
panda.load_plugin("osi_linux", args = {
                                "kconf_file": f"{kernel_dir}/osi_profiles.conf",
                                "kconf_group": "armel"})

# What the heck is this? https://lwn.net/Articles/519085/
@panda.ppp("proc_start_linux", "on_rec_auxv")
def rec_auxv(cpu, tb, auxv):
    prog_name = panda.ffi.string(auxv.execfn).decode()
    print(prog_name, end="")
    for i in range(auxv.argc):
        print(" "+panda.ffi.string(auxv.argv[i]).decode(), end="")
    print() #newline

try:
    panda.run()
except KeyboardInterrupt:
    print("Got Ctrl-C, exiting")
finally:
    panda.panda_finish()
