---
baseptr: .
layout: profile
description: Playground for Free Software Projects.
keywords: Ali Onur Uyar, GitHub, Free Software, Collaboration

projects:
    - name: PyMunin
      shortdesc: Python Module for developing Munin Multigraph Monitoring Plugins
      longdesc: Implements a framework for implementing Munin Plugins.
                Multigraph Plugins are provided for Apache Web Server, 
                Apache Tomcat, APC PHP Cache, PHP FPM (Fast Process Manager), 
                Asterisk, FreeSWITCH, Lighttpd, Memcached, MySQL Database, Nginx, 
                NTP, PostgreSQL Database, Varnish Cache, CPU Utilization, 
                Memory Utilization, Disk Usage, Disk I/O, Network Interfaces, 
                Network Connections, Processes and Threads, etc.
      prjpage: true
    - name: pybackup
      shortdesc: Python Module for implementing backup scripts.
      longdesc: Being developed as an alternative to custom shell scripts
                that improves on error checking and reporting.
      prjpage: true
    - name: MAC-Telnet
      shortdesc: Telnet / SSH using MAC Address (Client and Server)
      longdesc: Based on the original work of 
                [haakonnessjoen](https://github.com/haakonnessjoen) 
                (Håkon Nessjøen); Open source MAC Telnet client and server for 
                connecting to Microtik RouterOS routers and Linux machines via 
                MAC address. Added MAC SSH client and server functionality for 
                tunneling SSH protocol instead of implementing shell interface 
                directly. It is great to be able to SSH into a box, which has
                no IP address. Facilitates initial provisioning of servers and 
                embedded systems and might save the day if the network 
                configuration gets messed up.
      prjpage: false
	
---

Projects
--------

{% for project in page.projects %}
{% if project.prjpage %}
* [{{ project.name }}] (./prj/{{ project.name }}/)
  @ [GitHub] (https://github.com/{{ site.user }}/{{ project.name }}/) - {{ project.shortdesc }}
  <br>{{ project.longdesc }}
{% else %}
* {{ project.name }}
  @ [GitHub] (https://github.com/{{ site.user }}/{{ project.name }}/) - {{ project.shortdesc }}
  <br>{{ project.longdesc }}
{% endif %}
{% endfor %}


Contact
-------

aouyar at gmail.com