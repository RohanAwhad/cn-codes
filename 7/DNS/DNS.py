import socket

print 'Welcome to DNS Lookup'
print 'Enter your option 1. URL to IP 2. IP to URL'
op=raw_input('Enter Option')
var=raw_input('Enter URL/IP')
addr1 = socket.gethostbyname(var)
addr6=socket.gethostbyaddr(var)
if op==1:	
	print(addr1)

else:
	print(addr6)
