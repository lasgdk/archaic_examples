import socket
net = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
i = 1
net.connect(('192.168.1.117', 22))
while i:
	net.send('ye\n\r')
net.close()
