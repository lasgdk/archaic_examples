#Python example of simple network socket.
#
#If nothing listens on port 12345, start a netcat for it:
#"nc -l -p 12345"
#when running the script, nc receives the string.

import socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(('localhost', 12345))
s.send('Hello networld!')
data = s.recv(1024)
s.close()
print 'Received', `data`
