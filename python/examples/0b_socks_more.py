import socket
net=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
net.connect(('192.168.1.1', 25))
welcome=net.recv(1024)
print welcome
