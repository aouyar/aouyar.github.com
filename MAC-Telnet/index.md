---
baseptr: ..
layout: project
description: |
             Open source MAC Telnet client and server for connecting to 
             Mikrotik RouterOS routers and Linux machines via MAC address. 
             Based on the original work of haakonnessjoen (Håkon Nessjøen); 
             added forwarding mode to tunnel a TCP connection through MAC-Telnet 
             protocol, and implemented MAC SSH client and server functionality 
             for tunneling SSH protocol instead of implementing shell interface 
             directly. Use cases include initial provisioning of servers and 
             embedded systems and recovery from IP Stack configuration errors.
keywords: |
          MAC Address, Telnet, SSH, Client, Server, TCP, Forward, Tunnel, Shell,  
          Mikrotik, RouterOS, Linux, provisioning, recovery.
prjname: MAC-Telnet
prjdesc: MAC-Telnet / MAC-SSH  Client & Server for connecting to 
         Mikrotik RouterOS and Linux Boxes via MAC Address
prjpypi: false
license_file: LICENSE

hnav:
    - About
    - Differences
    - Use Cases
    - Download
    - Installation
    - Configuration
    - Usage
    - Troubleshooting
    - Credits
    - License
	
---


About
-----

Open source MAC Telnet client and server for connecting to Mikrotik RouterOS 
routers and Linux machines via MAC address. 
             
Based on [MAC-Telnet](https://github.com/haakonnessjoen/MAC-Telnet) 
the original work of 
[haakonnessjoen](https://github.com/haakonnessjoen) (_Håkon Nessjøen_);
forked the upstream version to add forwarding mode for tunneling a TCP 
connection through MAC-Telnet protocol, and implemented MAC-SSH client and 
server functionality for tunneling SSH protocol instead of implementing shell 
interface directly. 

Unless you will be using any of the additional functionalities, I recommend 
using the [Original Version](https://github.com/haakonnessjoen/MAC-Telnet) from
[haakonnessjoen](https://github.com/haakonnessjoen) (_Håkon Nessjøen_) instead.

For information on other projects you can check 
my [GitHub Personal Page](http://aouyar.github.com)
and [GitHub Profile](https://github.com/aouyar).


Differences
-----------

The original version implements the following:

* A _Linux_ console tool for connecting to _MikroTik RouterOS_ devices via their
  _Ethernet_ address.
* _Linux_ daemon that implements the _MAC-Telnet_ server to permit connecting
  to _Linux machines_ via their ethernet address.

The forked version implements additional functionality for forwarding a 
TCP connection through the _MAC Telnet_ protocol. The main use case 
is connecting to _Linux_ machines via their _Ethernet_ address using the _SSH_ 
protocol for security. Take note that the clients and servers running in the
forwarding mode are not compatible with existing _MAC-Telnet_ clients  and 
servers implementing the standard mode of operation. 

The forked version of the server supports two modes of operation:
* Standard MAC-Telnet Server Mode
* TCP Connection Forwarding Mode: Tunnels a TCP connection to a local port on 
  the client to a specific local port on the server side through MAC-Telnet 
  protocol. This mode of operation is used for forwarding SSH connections 
  through the MAC-Telnet protocol.

The client supports three modes of operation:
* Standard MAC-Telnet Client Mode
* TCP Connection Forwarding Mode: Tunnels a specific local port on the client to 
  the serverthrough MAC-Telnet protocol.
* SSH Forwarding Mode: Apart from setting up the tunnel, the client takes care 
  of launching the SSH client.

The _SSH Forwarding Mode_ has the following advantages in comparison to standard
_MAC-Telnet_:

* The_mactelnet.users_ configuration file is not needed. Instead of maintaining 
  another set of user passwords for _MAC-Telnet_, the authentication mechanisms 
  implemented ssh are used.
* _Public Key Authentication_ works seamlessly permiting passwordless logins.
* The communication between client and server is encrypyted by _SSH_.
* The daemon does not require root privileges and can be run by a non-privileged 
  user for additional security. In case the _-n_ option is used, the server
  or client must be launched as _root_ user, but the_-U_ option can be used to 
  drop privileges once the initial setup phase ends.
* The server relies on the security model of _SSH_, instead of creating a shell
  environment itself.


Use Cases
---------


### Embedded Systems ###

It can be used for initial provisioning and for maintenance purposes in 
situations where a valid IP configuration is not available. 

Might be a useful addition to the rescue mode especially of embedded systems 
without screens; connecting  using MAC-Telnet / MAC-SSH is much more convenient 
then fetching and connecting a serial cable.


### The Datacenter ###

It can be used for initial provisioning of physical and virtual servers and 
might serve as a rescue system, when the IP configuration of a server gets 
messed up for any reason.


Download
--------


### Binary Packages ###

The original version of the _MAC-Telnet_ has been packaged for _Debian GNU/Linux_
by the original author [haakonnessjoen](https://github.com/haakonnessjoen) (_Håkon Nessjøen_).
You can download the _deb_ packages for the original version from the 
[Downloads Page](https://github.com/haakonnessjoen/MAC-Telnet/downloads) 
of the [Upstream Project](https://github.com/haakonnessjoen/MAC-Telnet/). 


### Source Packages ###

The original version of the _MAC-Telnet_ 
by [haakonnessjoen](https://github.com/haakonnessjoen) (_Håkon Nessjøen_) can
be download from the project page of the 
[Upstream Project](https://github.com/haakonnessjoen/MAC-Telnet/). 

{% include download.inc %}


Installation
------------
	    
The binary packages of the original version of the code can be installed using 
the packaging tools of the distribution.

Once the source code is cloned or downloaded it can be installed as follows:

	$ make all install


Configuration
-------------

Sample _upstart_ configuration files can be found in the _config_ directory of
the distribution:

* Use _mactelnetd.init_ for starting / stopping _MAC-Telnet_ in standard mode.
* Use _macsshd.init_ for starting / stopping _MAC-Telnet_ in _MAC-SSH_ mode.


Usage
-----

###mactelnet###

	$ mactelnet -h
	
	Usage: mactelnet <MAC|identity> [-v] [-h] [-q] [-n] [-l] [-S] [-P <port>]
	       [-t <timeout>] [-u <user>] [-p <pass>] [-c <path>] [-U <user>]
	
	Parameters:
	  MAC           MAC-Address of the RouterOS/mactelnetd device. Use mndp to 
	                discover it.
	  identity      The identity/name of your destination device. Uses MNDP 
	                protocol to find it.
	  -l            List/Search for routers nearby. (using MNDP)
	  -n            Do not use broadcast packets. Less insecure but requires root 
	                privileges.
	  -t <timeout>  Amount of seconds to wait for a response on each interface.
	  -u <user>     Specify username on command line.
	  -p <pass>     Specify password on command line.
	  -U <user>     Drop privileges by switching to user, when the command is
	                run as a privileged user in conjunction with -n option.
	  -S            Use MAC-SSH instead of MAC-Telnet. (Implies -F)
	                Forward SSH connection through MAC-Telnet and launch SSH client.
	  -F            Forward connection through of MAC-Telnet without launching the 
	                SSH Client.
	  -P <port>     Local TCP port for forwarding SSH connection.
	                (If not specified, port 2222 by default.)
	  -c <path>     Path for ssh client executable. (Default: /usr/bin/ssh)
	  -q            Quiet mode.
	  -v            Print version and exit.
	  -h            Print help and exit.
	
	All arguments after '--' will be passed to the ssh client command.


### mactelnetd ###

	$ mactelnetd -h
	
	Usage: mactelnetd [-v] [-h] [-n] [-f] [-S] [-P <port>] [-U <user>]
	
	Parameters:
	  -f         Run process in foreground.
	  -n         Do not use broadcast packets. Just a tad less insecure.
	  -S / -F    Tunneling of TCP connections through  MAC-Telnet protocol,
	             instead of standard MAC-Telnet use.
	  -P <port>  Local TCP port for SSH Server.
	             (If not specified, port 22 by default.)
	  -U <user>  Drop privileges by switching to user, when the command is
	             run as a privileged user in conjunction with -n option.
	             Standard MAC-Telnet is not compatible with this option.
	  -v         Print version and exit.
	  -h         Print help and exit.


### macping ###

	$ macping -h
	
	Usage: ./macping <MAC> [-h] [-f] [-c <count>] [-s <packet size>]
	
	Parameters:
	  MAC       MAC-Address of the RouterOS/mactelnetd device.
	  -f        Fast mode, do not wait before sending next ping request.
	  -s        Specify size of ping packet.
	  -c        Number of packets to send. (0 = unlimited)
	  -h        This help.


### mndp ###

	$ mndp


Troubleshooting
---------------

Disable _firewalls_ both on the client and server side for testing. _Firewalls_ 
can block the forwarding of packets with broadcast addresses even when they are
not blocking any ports.

The server can be run in the foreground (commanline option: -f) for testing.


Credits
-------

[MAC-Telnet](https://github.com/haakonnessjoen/MAC-Telnet) has originally been 
developed by [haakonnessjoen](https://github.com/haakonnessjoen) (_Håkon Nessjøen_).

The code published on this page is a fork with some experimental features for
establishing _SSH_ connections via _MAC Address_. The additional features have 
been implemented  
by [Ali Onur Uyar]({{ page.baseptr}}/) 
([{{ site.user }} @ GitHub] (https://github.com/{{ site.user }})).


License
-------

{% include license_gpl.inc %}