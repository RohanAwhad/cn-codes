import sys
from math import log, ceil

ip = list(map(int, raw_input("Enter IP address: ").split('.')))
for x in ip:
	if x > 255:
		print("Wrong IP.\nQuitting...")
		sys.exit()
ip_bin = [bin(x) for x in ip]
ip_class = ''
if (ip[0] < 127): ip_class = 'A'
elif (ip[0] < 192): ip_class = 'B'
elif (ip[0] < 224): ip_class = 'C'
elif (ip[0] < 240): ip_class = 'D'
elif (ip[0] < 256): ip_class = 'E'

subnet_mask = [255]
if ip_class == 'A': subnet_mask.extend([0,0,0])
elif ip_class == 'B': subnet_mask.extend([255,0,0])
elif ip_class == 'C': subnet_mask.extend([255,255,0])
else:
	print("Cannot subnet class {} IPs\nQuitting".format(ip_class))
	sys.exit()

subnet_mask_bin = ["{0:08b}".format(x) for x in subnet_mask]
no_of_address = int(raw_input("Enter no of subnets: "))
no_of_bits_to_change = int(ceil(log(no_of_address)/log(2)))
print("No bits changed: " + str(no_of_bits_to_change))
index = 0
if ip_class == 'A': 
	index = 1
	#if no_of_bits_to_change > 24:
	#	print("")
elif ip_class == 'B': index = 2
elif ip_class == 'C': index = 3

num = no_of_bits_to_change
subnet_mask_bin[index] = subnet_mask_bin[index].replace('0', '1', num)
'''rangex = ceil(no_of_bits_to_change / 8)
print(rangex)
rangex = int(rangex)
print(rangex)
for _ in range(rangex):
	if num < 8:
		print(subnet_mask_bin[index + _])
		subnet_mask_bin[index + _].replace('0', '1', num)
		print(subnet_mask_bin[index + _])
		break
	else:
		subnet_mask_bin[index + _].replace('0', '1', 8)'''

#print("Subnet Mask: " + ".".join(x for x in subnet_mask_bin))
del subnet_mask
subnet_mask = [int(x,2) for x in subnet_mask_bin]
print("Subnet Mask: " + ".".join(str(x) for x in subnet_mask))

subnet_address_bin = []
for i in range(4):
	subnet_address_bin.append(bin(subnet_mask[i] & ip[i])[2:].zfill(8))
	
subnet_addr = [int(x,2) for x in subnet_address_bin]
print("Subnet Address: " + '.'.join(str(x) for x in subnet_addr))

# BROADCAST ADDRESS

negative_subnet_mask_bin = []
for i in subnet_mask_bin:
	temp1 = ""
	for j in range(len(i)):
		if i[j] == '0': temp1 += '1'
		else: temp1 += '0'
	negative_subnet_mask_bin.append(temp1)
	
	
#print(negative_subnet_mask_bin)
negative_subnet_mask = [int(x,2) for x in negative_subnet_mask_bin]
#print(negative_subnet_mask)
#print(ip)


broadcast_address_bin = []
for i in range(4):
	broadcast_address_bin.append(bin(negative_subnet_mask[i] | ip[i])[2:].zfill(8))
	
broadcast_addr = [int(x,2) for x in broadcast_address_bin]
print("Broadcast Address: " + '.'.join(str(x) for x in broadcast_addr))































