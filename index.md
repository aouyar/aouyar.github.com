---
baseptr: .
layout: profile
description: Playground for Free Software Projects
keywords: Ali Onur Uyar, GitHub, Free Software, Collaboration

hnav:
    - Updates
    - About
    - Projects
    - Contact

projects:
    - name: PyMunin
      shortdesc: Python Module for developing Munin Multigraph Monitoring Plugins
      longdesc: |
                Implements a framework for implementing Munin Plugins.
                Multigraph Plugins are provided for Apache Web Server, 
                Apache Tomcat, APC PHP Cache, PHP FPM (Fast Process Manager), 
                Asterisk, FreeSWITCH, Lighttpd, Memcached, MySQL Database, Nginx, 
                NTP, PostgreSQL Database, Varnish Cache, CPU Utilization, 
                Memory Utilization, Disk Usage, Disk I/O, Network Interfaces, 
                Network Connections, Processes and Threads, etc.
      prjpage: true
    - name: pybackup
      shortdesc: Python Module for implementing backup scripts.
      longdesc: |
                Backups scripts in _Python_, being developed as an alternative 
                to backup task specific custom shell scripts.
                Backup jobs are defined in a configuration file and different 
                backup methods are implemented by plugins, that improve on error 
                checking and reporting.
      prjpage: true
    - name: MAC-Telnet
      shortdesc: Telnet / SSH via MAC Address (Client and Server)
      longdesc: |
                Open source MAC Telnet client and server for connecting to 
                Mikrotik RouterOS routers and Linux machines via MAC address. 
                Based on the original work of 
                [haakonnessjoen](https://github.com/haakonnessjoen) 
                (Håkon Nessjøen); forked the upstream version to add forwarding 
                mode for tunneling a TCP connection through MAC-Telnet protocol, 
                and implemented MAC-SSH client and server functionality for 
                tunneling SSH protocol instead of implementing shell interface 
                directly. Use cases include initial provisioning of servers and 
                embedded systems and recovery from IP Stack configuration errors.
      prjpage: True
	
---


Updates
-------

<table class="">
<col width="0"/>
<col width="*"/>
<tbody>
{% for post in site.posts limit: 5 %}
{% capture post_title %}
{% if post.prjname %}
{{ post.prjname }} -
{% endif %}
{{ post.title }}
{% endcapture %}
<tr>
	<td>
		<div class="postdate">{{ post.date | date_to_string }}</div>
	</td>
	<td>
	   <div class="posttitle">
{% if post.nopage %}     
            {{ post_title }}
{% else %}
            <a href="{{ post.url }}">{{ post_title }}</a>
{% endif %}
        </div>
        <div>
		{{ post.excerpt | markdownify }}
		</div>
	</td>
</tr>
{% endfor %}
</tbody>
</table>


About
-----

I am an Electrical and Electronics Engineer who has been working with Free 
Software since 1997. I started working a Software Developer on Solaris Platform,
then went on to work in IT Security, System Administrator for UNIX Platforms
(GNU/Linux, Solaris, AIX and HP/UX), IT Infrastructure Specialist and 
IP Telephony Specialist.

Here you can find information on some side projects published as Free Software.


Projects
--------

{% for project in page.projects %}
{% if project.prjpage %}
* [{{ project.name }}] (./{{ project.name }}/)
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