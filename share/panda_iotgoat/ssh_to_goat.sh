#ssh to iotgoat as root (requires ssh and sshpass):
ssh-keygen -R "[localhost]:2222"
sshpass -p "iotgoathardcodedpassword" ssh -o StrictHostKeyChecking=no root@localhost -p 2222
