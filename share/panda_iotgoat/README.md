# Whole-System Analysis

## References:

* https://panda.re
* https://github.com/panda-re/panda/tree/dev/panda/python/examples


## Activity

If you read the IoTGoat challenges page from yesterday, you may have noticed
that there is a backdoor in the firmware.  We can observe this backdoor start up
with PANDA.

Write a callback to output all processes that listen on a TCP port and list that
port.  You can use `@panda.ppp("syscalls2", "on_sys_bind_return")` to do this.

Some helpful tips:
    * The "filename" of a socket will indicate whether it is a TCP or UDP socket.
    * If you get stuck, you can `import IPython; IPython.embed()` to drop into
      an interactive shell and explore the data structures.

    * The port numbers are stored in the `sockaddr_in` structure. They are annoyingly stored in network byte order.  You can use `socket.ntohs` to convert them to host byte order.

    * `panda.virtual_memory_read(cpu,address,size,fmt='int')` will read memory from the virtual address space of the process.  This is useful for reading the `sockaddr_in` structure.


Note that you could find this backdoor via port-scanning or if we have a shell
we could use `netstat`.  However, we are using QEMU-user networking so we would
want to know which ports to open up.
