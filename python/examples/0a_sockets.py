#Network sockets in python

#We need a library for this (note that we havent included any stdio-like
# things before..)
import socket

#We create an socket object with some options:
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#Now we can connect to someone, ('hostname', port):
sock.connect(('localhost', 12345))

#And send something:
sock.send('Hello networld!')

#Like files, we always close after done work:
sock.close()

#You can test the "Hello networld" by starting a netcat-session, which
# listens on port 12345.
#This command "nc -l -p 12345", will make NetCat (nc) listen (-l) on
# port (-p) 12345.
