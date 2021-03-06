********************************************************* 42Cursus *********************************************************


------------------------------------Second Project - NetWhat-----------------------------------

Sources:
https://github.com/edithturn/42-silicon-valley-netwhat
https://github.com/adblanc/netwhat42-train
https://github.com/appinha/42cursus/tree/master/01-netwhat
http://jodies.de/ipcalc?host=131.213.131.254&mask1=25&mask2=

vim modifications: vim ~/.vimrc


X------------------Question 01------------------X

If an Ethernet port on a router were assigned an IP address of 21.121.54.71/15, which host address would be able to communicate with it?

(a) 166.121.177.233
(b) 95.199.103.46
(c) 21.121.241.69 "<<< Correct Answer!"
(d) 244.28.220.100
(e) 198.58.153.142
(f) 79.46.141.190
(g) 167.232.175.162

On a computer network, all devices that are connected to the same local network can talk directly with each other, 
as long as they have IP addresses that belong to the same IP network. If the computers belong to different IP networks 
then they have to communicate with each other via a router. The main purpose of a router is to be able to forward traffic 
to different destinations. Within computer networking, those destinations are different IP networks.


✏️ Answer: 21.121.241.69 would be able to communicate with 21.121.54.71/15.

🎆 Reference: https://www.homenethowto.com/basics/ip-addresses/

X------------------Question 02------------------X

Which of the following services use UDP?

(a) DHCP "<<< Correct Answer!"
(b) SMTP
(c) FTP
(d) HTTP
(e) All of the above

UDP:	(User Datagram Protocol) is a communication protocol that is primarily used for establishing low-latency and 
		loss-tolerating connections between application on the internet.

DHCP:	The DHCP (Dynamc Host Confguration Protocol) is a network management protocol used to automate the process of
		configuring devices on IP network. Employs a connectionless services model, using the User Datagram Protocol (UDP). 
		it is implemented with two UDP port numbers for its operations which are the same as the BOOTP protocol. UDP port 
		number 67 is the destination port of a server, and UDP port number 68 is used by the client.

SMTP:	(Simple Mail Transfer Protocol), is a mail transport protocol, and in mail every single packagt is important. 
		If you lose some package in the transmision of the message the recipient might not even receive the message and 
		they might be missing key information. TCP is more appropieate in this case because ensures that every package is delivered.

FTP:	(File Transfer Protocol) Is a way to transfer file online (between a client and server on a computer network), 
		uses the TCP protocol because the file transfer has to be correct.

HTTP:	(Hipertext Transfer Protocol) is a protocol used by the World Wide Web, and this protocol defines how messages are 
		formated and transmitted, and what actions Web servers and browsers should take in response to several commands. 
		Uses TCP instead of UDP because it guarantees delivery via a three-way handshake and re-transmission of lost packets.

✏️ Answer: DHCP use UDP

X------------------Question 03------------------X

Which of the following is the valid host range for the subnet on which the IP address 120.2.67.128/15 resides?

(a) 120.2.0.1-120.3.255.251
(b) 120.2.0.1-120.3.255.254 "<<< Correct Answer!"
(c) 120.2.0.1-120.3.255.253
(d) 120.2.0.1-120.4.0.3

First of all we need to convert our Subnet Mask in Binary Format. The quantity of ones, depends on what the MASK /15 indicates. 

The range can be calculated manually by following the steps below: 

https://github.com/edithturn/42-silicon-valley-netwhat/tree/master/03_valid_host_range

Images:

https://raw.githubusercontent.com/edithturn/42-silicon-valley-netwhat/master/03_valid_host_range/first_valid_host.png
https://raw.githubusercontent.com/edithturn/42-silicon-valley-netwhat/master/03_valid_host_range/last_valid_host.png

Or by using the Subnet calculator below:

http://www.aboutmyip.com/AboutMyXApp/SubnetCalculator.jsp?ipAddress=120.2.67.128&cidr=15

✏️ Answer: [ 120.2.0.1 - 120.3.255.254 ]

🎆 Reference: https://www.youtube.com/watch?v=uyRtYUg6bnw%2F

X------------------Question 04------------------X

DHCP is used for _____________

(a) Both IPv6 and IPv4  "<<< Correct Answer!"
(b) None of the mentioned
(c) IPv4
(d) IPv6

The original and most comprehensive implementation of the DHCP service is offered by the Internet System Consorttium, 
supporting IPv4 and IPv6.

DHCP is the standard way network adminstrator assign IP addresses in IPv4 networks, but eventually organizations will 
have to pick between two protocols created specifically for IPv6 as the use of this newer IP protocol grows.

✏️ Answer: Both IPv6 and IPv4

X------------------Question 05------------------X

How long is an IPv4 address?

(a) 64 bits
(b) 128 bits
(c) 128 bytes
(d) 32 bits "<<< Correct Answer!"

What is a IPv4?

IPv4 was the first version of IP. It was deployed for production in the ARPANET in 1983. Today it is most used IP version. It is used to identify devices on a network using an addressing system.

The IPc4 uses a 32-bits address scheme allowing to store 2^32 address which is more than billion addresses. Till date, is it consider the primary internet Protocol and carries 94% of the internet traffic.

What is a IPv6?

Is the most recent version of the Internet Protocol. Internet Engineer Taskforce initiated it in early 1994. The design and development of that suite is now called IPv6.

This new IP address version is being deployed to fulfill the need for more Internet addreess. It was aimed to reolve issues which are associated with IPv4. With 128-bit address space, it allows 340 undecillion unique address space. IPv6 also called IPng (Internet Protocol next generation)

✏️ Answer: 32-bits

🎆 Reference: https://www.guru99.com/difference-ipv4-vs-ipv6.html

X------------------Question 06------------------

What is the Network address of a host with an IP address of 250.160.111.191/18?

(a) 250.160.64.0 "<<< Correct Answer!"
(b) 250.160.0.0
(c) 250.160.111.176
(d) 224.0.0.0
(e) 250.160.108.0
(f) 250.160.111.128

✏️ Answer: 250.160.64.0

🎆 References:

http://www.aboutmyip.com/AboutMyXApp/SubnetCalculator.jsp?ipAddress=120.2.67.128&cidr=15
https://www.youtube.com/watch?v=hb2yTNT2rBU&feature=emb_logo

X------------------Question 07------------------

What is the maximun number of IP addresses that can be assigned to host on a local subnet that uses the 255.240.0.0 subnet mask?

(a) 1048576
(b) 524284
(c) 2097154
(d) 1048574 "<<< Correct Answer!"
(e) 2097150
(f) 52488

Subnet Mask: 255.240.0.0

11111111.11110000.00000000.00000000
            |<---------20--------->

(2^20) - 2 = 1048574

✏️ Answer: 1048574

X------------------Question 08------------------X

Which of this is not true?

(a) UDP supports Broadcasting:
	UDP supports multcast, it is sutable for broadcast informaton such as in many kinds of service discovery and 
	shared information such as Precision Time Protocol and Routing Information Protocol.

(b) There is no sequencing of data in UDP. If ordering is requiered, it has to be managed by the application layer:
	UDP does not provide subsequent data to the application while it is requesting re-sending of the missing data.

(c) UDP is a datagram-oriented protocol: With UDP, computer applications can send messages, in this case referred to as datagrams, 
	to other hosts on an Internet Protocol (IP) network.

(d) The delivery of data to the destination cannot be guaranteed in UDP. 
	There is no guarantee of delivery, ordering, or duplicate protection.

(e) UDP has only the basic error checking mechanism using checksums: UDP provides checksums for data integrity, 
	and port numbers for addressing different functions at the source and destination of the datagram.

(f) UDP is comparatively slower than TCP "<<< Correct Answer!"


-----------Services----------- |  SCTP  ||  TCP  ||  UDP  |
-------------------------------|--------||-------||-------|
Multi-homing				   |  YES   ||  NO   ||  NO   |
Multi-streaming				   |  YES   ||  NO   ||  NO   |
Ordered Data delivery          |  YES   ||  YES  ||  NO   |
Allow half-closed connections  |  NO    ||  YES  ||  N/A  |
Application PDU bundling       |  YES   ||  YES  ||  NO   |
Application PDU fragmentation  |  YES   ||  YES  ||  NO   |
Congestion control             |  YES   ||  YES  ||  NO   |
Partial-reliable data transfer |OPTIONAL||  NO   ||  NO   |
Preserve message boundaries    |  YES   ||  NO   ||  YES  |


✏️ Answer: "UDP is comparatively slower than TCP" is NOT TRUE


X------------------Question 09------------------X

Which protocol does DHCP use at the Transport layer?

(a) IP
(b) ARP
(c) UDP "<<< Correct Answer!"
(d) TCP

UDP: User Datagram Protocol is used, and it is a connection network service at the Transport layer, and DHCP uses 
this connectionless service.

✏️ Answer: UDP

X------------------Question 10------------------X

You have an interface on a router with the IP address of 248.137.150.138/25. 
Including the router interface, how many hosts can have IP addresses on the LAN attached to the router interface?

(a) 64
(b) 126 "<<< Correct Answer!"
(c) 250 
(d) 62 
(e) 256 
(f) 252 
(g) 254

IP ADDRESS: 248.137.150.138/25 
Subnet Mask: 11111111.11111111.11111111.10000000
										 <-----> 7 number of host bits, all the zeroes 

(2 ^ 7 - 2 = 126)

✏️ Answer: 126

🎆 Reference: https://github.com/edithturn/42-silicon-valley-netwhat/tree/master/10_how_many_hosts

X------------------Question 11------------------

What are the different layers of the OSI model?


(a) Application -> Presentation -> Session -> Transport -> Network -> Data Link -> Physical "<<< Correct Answer!"
(b) Application -> Mediation -> Session -> Transport -> Network -> Data Link -> Physical 
(c) Presentation -> Session -> Transport -> Network -> Data Link -> Application -> Real
(d) Relation -> Transport -> Session -> Data Link -> Mediation -> Presentation -> Application

1. Application:
- End user Layer
- HTTP, FTP, IRC, SSH, DNS

2. Presentation:
- Syntax layer
- SSL, SSH, IMAP, FTP, JPEG

3. Session:
- Synch & send to port
- APIs, Socets, WinSock

4. Transport:
- End-to-end connections
- TCP, UDP

5. Network:
- Packets
- IP, ICMP, IPSec, IGMP

6. Data Link
- Frames
- Ethernet, PPP, Switch, Bridge

7. Physical
- Physical structure
- Coax, Fiber, Wireless, Hubs, Repeaters

✏️ Answer:

Application ->Presentation->Session->Transport->Network->Data Link->Physical

X------------------Question 12------------------X

What is the maximum number of IP addresses that can be assigned to host on a local subnet that uses the 255.255.255.248 subnet mask?

(a) 0
(b) -2
(c) 10
(d) 2
(e) 6 "<<< Correct Answer!"
(f) 4

IP ADDRESS: 255.255.248.0 
			 <-255--> <-255--> <-255--> <-248-->
Subnet Mask: 11111111.11111111.11111111.11111000
										 	 <-> 3 zeroes 

(2 ^ 3) - 2 = 6

✏️ Answer: maximun number of IP addresses : 6

🎆 References: https://github.com/edithturn/42-silicon-valley-netwhat/tree/master/12_max_number_ip_address

X------------------Question 13------------------X

Which of this is not a class of IP address?

(a) Class D
(b) Class C
(c) Class E
(d) Class F "<<< Correct Answer!"

IP:

The IP (Internet Protocol) is the fundamental protocol for communications on the Internet.

IP ADDRESS:

An IP address is a number identifying of a computer or another device on the Internet.

Classes of IP addresses

Class   |   Address Range
--------|---------------------------------
A 		|	1.0.0.1 to 126.255.255.254	
B 		|	128.1.0.1 to 191.255.255.254
C       |	192.0.1.1 to 223.255.254.254
D 		|	224.0.0.0 to 239.255.255.255

✏️ Answer: Class F is not a class of IP address

X------------------Question 14------------------X

Which of the following is private IP address?

(a) 18.187.149.135
(b) 192.168.108.121 "<<< Correct Answer!"
(c) 81.0.182.194
(d) 130.41.89.219

Whats a Private IP address?

Home routers have their local address set to a default, private IP address number.

Thats the point: Your private address is just for your router, your network and you. The private address ranges in a network dont have to be synchronized with the rest of the world and Internet.

-----Private IP Address Space-----
From 		|	To
------------|---------------------
10.0.0.0	|	10.255.255.255
172.16.0.0	|	172.31.255.255
192.168.0.0	|	192.168.255.255

✏️ Answer: 192.168.108.121 is private IP address.

X------------------Question 15------------------X

Which class of IP address has the most host addresses available by default?

(a) B
(b) C
(c) A and B
(d) A "<<< Correct Answer!"

Class   |         Address Range 		  |					Supports
--------|---------------------------------|-----------------------------------------------------------------
A 		|	1.0.0.1 to 126.255.255.254	  | Supports 16 million hosts on each of 127 networks
B 		|	128.1.0.1 to 191.255.255.254  | Supports 65000 hosts on each of 16000 networks
C       |	192.0.1.1 to 223.255.254.254  | Supports 254 hosts on each of 2 million networks
D 		|	224.0.0.0 to 239.255.255.255  | Reserverd for multicast groups
E 		|	240.0.0.0 to 254.255.255.254  | Reserverd for future use, or research and development purposes


✏️ Answer: Class A supports 16 million hosts on each 127 networks.

X------------------Question 16------------------X

The_____________translates internet domain and host names to IP adddress.

(a) Internet Relay Chat
(b) Network Time Protocol
(c) Routing Information Protocol
(d) Domain Name System "<<< Correct Answer!"
(e) The Domain Name System (DNS) is the phonebook of the Internet. Humans access information online through domain names, like nytimes.com or espn.com. Web browsers interact through Internet Protocol (IP) addresses. DNS translates domain names to IP addresses so browsers can load Internet resources.

✏️ Answer: Domain Name System (DNS)

X------------------Question 17------------------X

Which of this is not true?

(a) TC is reliable as it guarantees delivery of data to the destination router.
(b) TCP provides extensive error checking mechanisms. It is because it provides flow control and acknowledgment of data.
(c) TCP is comparatively slower than UDP
(d) TCP doesnt supports Broadcasting
(e) There is not sequencing of data in TCP. If ordering is requiered, it has to be managed by the application layer. "<<< Correct Answer!"
(f) TCP is a connection-oriented protocol.

✏️ Answer:

"There is not sequencing of data in TCP. If ordering is requiered, it has to be managed by the application layer." is not TRUE.


X------------------Question 18------------------X

You want to implement a mechanism that automates the IP configuration, including IP address, subnet mask, default gateway, and DNS information. Which protocol will you see to accomplish this?

(a) DHCP "<<< Correct Answer!"
(b) ARP
(c) SNMP
(d) SMTP

DHCP: The DHCP (Dynamc Host Confguration Protocol) is a network management protocol used to automate the process of configuring devices on IP network. Employs a connectionless services model, using the User Datagram Protocol (UDP). it is implemented with two UDP port numbers for its operations which are the same as the BOOTP protocol. UDP port number 67 is the destination port of a server, and UDP port number 68 is used by the client.

✏️ Answer: DHCP

X------------------Question 19------------------

Which protocol does Ping use?

(a) TCP
(b) BootP
(b) ARP
(b) ICMP "<<< Correct Answer!"

What is ping:

Ping is a computer network administration software utility used to test the reachability of a host on an Internet Protocol (IP) network.

Ping operates by sending Internet Control Message Protocol (ICMP) echo request packets to the target host and waiting for an ICMP echo reply.

✏️ Answer: ICMP

X------------------Question 20------------------X

How long is an IPv6 address?

(b) 64 bits
(b) 128 bytes
(b) 32 bits
(b) 128 bits "<<< Correct Answer!"

IPv6 addresses are 128 bits in length and are made up of hexadecimal characters.

Basic IPv6 Address

X : X : X : X : X : X : X : X 
--------- --- ---------------
	|	   |			|
  Prefix   |			|
  		 Subnet ID 		|
  					InterfaceID

2001 : 0db8 : 3c4d : 0015 : 0000 : 0000 : 1a2f : 1a2b 
------------------ ------ 	--------------------------
		|	  		 |				|
  	  Prefix   		 |				|
  		 		 Subnet ID 			|
  								InterfaceID


✏️ Answer: 128 bits



submit test

6741414141414267513378597751694b5559796d305776466a474f505a585f6366565f4c644442624876637578454d4f3253506d794e41376e624337384f4f443045784f4c7458736a36336a702d316c796a4c3674747964754d586e78706571524c59775770646e6a784331654372775344556e7079374b3752437a3748473538764b7a7636417164665a646e4c464330716364776b4e356d6474683472537751466377546d4c3050367a583877394b596e4e7a56583831612d444b5f33474a6d6f757174354d7675497933494f724179717658505461414175713257525a423546714a69776463636e547135576174666e525a3037674d5f6373654b427a6379756a672d6378723538354b4d416137744c305877366641433447432d30526e7254775264624d6e36564f7a46654558455647516e6e464c794b413854756938477a623853624569584c716935774444694e304274707353364e6c526434766e5777756256466f426d646a626e30624a44744c5763357478667a5f746354686c786837626e4c6e766a4e64457157736c44673242794b59654974466e333778753072732d743070544f43384d6f6646375f64706d6b656d4b4b6e776d3646534f5a703938333456597075596d437971537844644e744c4b72627059455a77686b62513d3d
