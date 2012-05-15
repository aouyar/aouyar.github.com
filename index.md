---
layout: user
description: Playground for Free Software Projects
user: aouyar
username: Ali Onur Uyar
keywords: Ali Onur Uyar, GitHub, Free Software, Collaboration

projects:
    - name: PyMunin
      shortdesc: Python Module for developing Munin Multigraph Monitoring Plugins
      longdesc: Multigraph Plugins for Apache Web Server, Apache Tomcat, 
                APC PHP Cache, PHP FPM (Fast Process Manager), Asterisk, 
                FreeSWITCH, Lighttpd, Memcached, MySQL Database, Nginx, NTP, 
                PostgreSQL Database, Varnish Cache, CPU Utilization, 
                Memory Utilization, Disk Usage, Disk I/O, Network Interfaces, 
                Network Connections, Processes and Threads, etc.
    - name: pybackup
      shortdesc: Python Module for implementing backup scripts.
      longdesc: Being developed as an alternative to custom shell scripts
                that improves on error checking and reporting.
    - name: MAC-Telnet
      shortdesc: Telnet / SSH using MAC Address (Client and Server)
      longdesc: Based on the original work of 
                [haakonnessjoen](https://github.com/haakonnessjoen) 
                (Håkon Nessjøen); Open source MAC Telnet client and server for 
                connecting to Microtik RouterOS routers and Linux machines via 
                MAC address. Added MAC SSH client and server functionality for 
                tunneling SSH protocol instead of implementing shell interface directly.
	
---

Projects
--------

{% for project in page.projects %}
* [{{ project.name }}] (http://{{page.user}}.github.com/{{project.name}}/)
  @ [GitHub] (https://github.com/{{page.user}}/{project.name}/) - {{project.shortdesc}}
  <br>{{project.longdesc}}
{% endfor %}


Contact
-------

aouyar at gmail.com