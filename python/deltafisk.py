#Example of IRC bot in python. 
#Throw this away, and take a look at my perl bot instead
import socket
net = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
net.connect(('irc.prison.net', 6667))
net.send('PASS su\r\n')
net.send('NICK %s\r\n' % "deltafisk")
net.send('USER deltafisk 0 * : deltafisk\r\n')
net.send('JOIN %s\r\n' % '#gammelgaard')	

while 1:
	data = net.recv(1024)				

	if data.startswith("PING"):
		net.send('PONG %s\r\n' % data.split(":")[1])

	if "!say" in data and data.split(" :")[1].startswith("!say"):
		if data.startswith(":kh"):
			net.send('PRIVMSG %s :%s\r\n' %('#gammelgaard', data.split("!say",2)[1]) )
	
	if data.endswith("!die\r\n"):
		if data.startswith(":kh!~HOSTNAMETOBEHERE"):
			net.send('QUIT :Leaving..\r\n')
			import sys
			sys.exit()
			socket.close()
