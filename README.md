# What's Reverse Shells
* A reverse shell, also known as a remote shell or “connect-back shell,” takes advantage of the target system’s vulnerabilities to initiate a shell session and then access the victim’s computer. The goal is to connect to a remote computer and redirect the input and output connections of the target system’s shell so the attacker can access it remotely.
# TECHNICAL DETAILS
* Init a socket library via WSAStartup call
* Create socket
* Connect to the socket a remote host:port
* start cmd.exe
