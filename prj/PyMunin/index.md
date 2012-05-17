---
baseptr: ../..
layout: project
description: |
             PyMunin - Python Module for Munin Multigraph Monitoring Plugins. 
             Plugins for Apache, Tomcat, Asterisk, Disk I/O, Disk Usage, 
             FreeSWITCH, Lighttpd, Memcached, MySQL, Network Interfaces, 
             Network Connections, Nginx, NTP, PHP APC, PHP FPM, PostgreSQL, 
             Varnish Cache, System CPU and Memory Utilization, VM Paging and 
             Swapping, etc.
keywords: |
          PyMunin, Munin, Plugin, Python, Multigraph, Monitoring, Apache, 
          Tomcat, PHP, APC, FPM, Asterisk, FreeSWITCH, Lighttpd, Memcached, 
          MySQL, Network, Interfaces, Connections, Nginx, NTP, PostgreSQL, 
          Varnish, Cache, System, CPU, Memory, Disk Usage, Disk I/O, Processes, 
          Forks, Interrupts
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins

hnav:
    - About
    - Credits
    - License
	
---


About
-----

Regular Munin Plugins employ one-plugin one-graph logic and require the 
execution of a script for data retrieval for each graph. Multigraph plugins 
permit the retrieval of data for multiple graphs in one execution run 
(one-plugin many-graphs), reducing the processing time and delay for the fetch 
cycle significantly. More information on Multigraph Plugins can be found in the 
[Munin Wiki](http://munin-monitoring.org/wiki/):

* [Multigraph Plugins](http://munin-monitoring.org/wiki/MultigraphSampleOutput)
* [Multigraph Plugin Protocol](http://munin-monitoring.org/wiki/protocol-multigraph)
	    
_PyMunin_ has been developed for implementing _Multigraph Plugins_ using 
_Python_, but simple single graph plugins are also supported.
		
The code for retrieval of data is totally separated from _Munin_ specific code. 
The modules for data retrieval in _./pysysinfo_ can be used independently of 
_Munin_ in other monitoring solutions.

* Test 1
* Test 2
* Test 3


License
-------

{% include license_gpl.inc %}