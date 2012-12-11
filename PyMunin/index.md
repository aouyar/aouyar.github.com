---
baseptr: ..
layout: project
description: |
             PyMunin - Python Module for Munin Multigraph Monitoring Plugins. 
             Plugins for Apache, Tomcat, Asterisk, Disk I/O, Disk Usage, 
             FreeSWITCH, Lighttpd, Memcached, MySQL, Network Interfaces, 
             Network Connections, Nginx, NTP, PHP APC, PHP FPM, PostgreSQL,
             Rackspace Cloudfiles, Redis Server, Varnish Cache, 
             System CPU and Memory Utilization, VM Paging and Swapping, etc.
keywords: |
          PyMunin, Munin, Plugin, Python, Multigraph, Monitoring, Apache, 
          Tomcat, PHP, APC, FPM, Asterisk, FreeSWITCH, Lighttpd, Memcached, 
          MySQL, Network, Interfaces, Connections, Nginx, NTP, PostgreSQL,
          Rackspace, Cloud, Redis, Varnish, Cache, System, CPU, Memory, 
          Disk Usage, Disk I/O, Processes, Forks, Interrupts
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins
prjpypi: true

hnav:
    - Updates
    - About
    - Plugins
    - Download
    - Installation
    - Configuration
    - Troubleshooting
    - Collaboration
    - Development
    - Credits
    - License
	
---

Updates
-------

{% assign post_list = site.categories.PyMunin %}
{% include prj_posts.inc %}


About
-----

Regular _Munin Plugins_ employ one-plugin one-graph logic and require the 
execution of a script for data retrieval for each graph. _Multigraph_ plugins 
permit the retrieval of data for multiple graphs in one execution run 
(one-plugin many-graphs), reducing the processing time and delay for the fetch 
cycle significantly. More information on _Multigraph Plugins_ can be found in the 
[Munin Wiki](http://munin-monitoring.org/wiki/):

* [Multigraph Plugins] (http://munin-monitoring.org/wiki/MultigraphSampleOutput)
* [Multigraph Plugin Protocol] (http://munin-monitoring.org/wiki/protocol-multigraph)

	    
_PyMunin_ has been developed for implementing _Multigraph Plugins_ using 
_Python_, but simple single graph plugins are also supported.
		
The code for retrieval of data is totally separated from _Munin_ specific code. 
The modules for data retrieval in _pysysinfo_ can be used independently of 
_Munin_ in other monitoring solutions.

{% include prj_link_home.inc %}


Plugins
-------
	    
_PyMunin_ has been used in developing many _Multigraph Munin Plugins_. 
The following is a list of plugins that are included the base distribution of 
_PyMunin_:
* [Apache Tomcat Server](./plugins/tomcat.html)
* [Apache Web Server](./plugins/apache.html)
* [Asterisk Telephony Server](./plugins/asterisk.html)
* [Disk Space Usage](./plugins/diskusage.html)
* [Disk I/O](./plugins/diskio.html)
* [FreeSWITCH Soft Switch](./plugins/freeswitch.html)
* [Lighttpd Web Server](./plugins/lighttpd.html)
* [Memcached Cache Server](./plugins/memcached.html)
* [MySQL Database Server](./plugins/mysql.html)
* [Network Interfaces](./plugins/netiface.html)
* [Network Connections](./plugins/netstats.html)
* [Nginx Web Server](./plugins/nginx.html)
* NTP - Time Synchronization Server
   * NTP [Synchronization State](./plugins/ntpstats.html)
   * NTP [Remote Host Offset](./plugins/ntpremote.html)
   * NTP [Remote Host Offsets](./plugins/ntpremotes.html)
* [PHP APC (PHP Cache)](./plugins/phpapc.html)
* [PHP FPM (FastCGI Process Manager)](./plugins/phpfpm.html)
* [PostgreSQL Database Server](./plugins/postgresql.html)
* [Processes and Threads](./plugins/process.html)
* [Rackspace Cloud](./plugins/rackspace.html)
* [Redis Server](./plugins/redis.html)
* [System Resources](./plugins/system.html)
* [Sangoma Wanpipe Telephony Interfaces](./plugins/wanpipe.html)
* [Varnish Cache Web Application Accelerator](./plugins/varnish.html)


Download
--------


### Binary Packages ###

_PyMunin_ has been packaged for [Fedora](http://fedoraproject.org/) and is also
included in the [EPEL Repository](http://fedoraproject.org/wiki/EPEL) for
[Red Hat Enterprise Linux](http://www.redhat.com), [CentOS](http://www.centos.org),
[Scientific Linux](http://www.scientificlinux.org/), etc. You can check the 
latest updates to the packages distributed by _Fedora Project_ here:

[https://admin.fedoraproject.org/updates/PyMunin](https://admin.fedoraproject.org/updates/PyMunin)

Please take not that the binary packages might take a long time to get updated
between distribution releases, so check the source packages to get the latest
and greatest.

Anyone that is interested in packaging _PyMunin_ for other distributions can 
contact me directly for assistance.


### Source Packages ###

{% include download.inc %}



Installation
------------
	    
### Binary Packages ###

_PyMunin_ is included in the latest versions of _Fedora Linux_, aand starting 
with _EL6_,_PyMunin_ can be installed in 
[Red Hat Enterprise Linux](http://www.redhat.com), [CentOS](http://www.centos.org),
[Scientific Linux](http://www.scientificlinux.org/), etc. using the
[EPEL Repository](http://fedoraproject.org/wiki/EPEL).

In the supported distributions, once the software repositories are configured
correctly, _PyMunin_ can be installed using _yum_:

<pre>
yum install PyMunin
</pre>


### Source Packages ###
	    
#### Automated Installation ####
	    
{% include install_pip.inc %}
					
This will install _pymunin_ and _pysysinfo_ in <i>Python</i> site packages.
The plugins will be unpacked as console scripts into the install _bin_ directory. 
Each of the scripts will be prefixed with _pymunin-_ (ex. _pymunin-apachestats_ ) 
to avoid name collisions with other binaries.
The location will be _/usr/local/bin/_ if installed globally or 
$VIRTUAL_ENV/bin if installed 
with [virtualenv](http://www.virtualenv.org/).

The plugins will automatically be installed in _Munin Plugins_ directory 
(ex. _/usr/share/munin/plugins_ ), if the installation process is executed with a 
privileged user and the _pymunin-_ prefix will be dropped in the process.

If the installation process fails while copying the plugin scripts 
to _Munin Plugin Directory_ because of permissions problems _pymunin-install_ 
script will be  created for copying the plugins from the _bin_ directory to 
_/usr/share/munin/plugins_.

In certain cases the install script might fail to determine the path for 
installing the _Munin Plugins_ (ex. _/usr/share/munin/plugins_ ). 
The _MUNIN_PLUGIN_DIR_  environment variable could be set before executing the 
setup script to force the installation of plugins in a specific directory.


#### Manual Installation ####

* The _pymunin_ and _pysysinfo_ directories should be placed in _Python_ 
  search path or in the _Munin Plugins_ directory (ex. /usr/share/munin/plugins_ ).
* Copy the plugin scripts in the directory _pymunin/plugins_ to 
  the _Munin Plugins_ directory (ex. _/usr/share/munin/plugins_ ) after removing 
  the file extension '_py_'.



Configuration
-------------

### Activation the Plugins ###

Enable the plugins just like the standard plugins by creating 
symbolic links in the _Munin Plugins Configuration Directory_ 
( _/etc/munin/plugins_ ) pointing to actual plugins scripts
in _/usr/share/munin/plugins_.

### Configuration of the Plugins ###

Configuration files for plugins can be created in the 
_Munin Plugins Configuration Directory_ 
( _/etc/munin/plugin-conf.d_ ).

The environment variables used by the plugin scripts are documented in the 
individual web pages for the plugins and in the header part of the plugin 
modules in _pymunin/plugins_.

### Configuration of Multiple Instances of Plugins ###

The configuration of multiple instances of plugins will be illustrated with a 
simple example for monitoring two instances of _Apache Web Servers_ from the 
same node.

Multiple symbolic links with different names pointing to the same plugin script 
in are created in _/usr/share/munin/plugins_ is created in the 
_Munin Plugins Configuration Directory_ ( _/etc/munin/plugins_ ).

Example:

    /etc/munin/plugins/apachestats_web1 -> /usr/share/munin/plugins/apachestats
    /etc/munin/plugins/apachestats_web2 -> /usr/share/munin/plugins/apachestats

Independent configuration files ( _/etc/munin/plugin-conf.d/apachestats\_web1_ 
and _/etc/munin/plugin-conf.d/apachestats\_web2_ ) are created for the two 
instances.

_/etc/munin/plugin-conf.d/apachestats\_web1_ :

    [apachestats_web1]
      env.host 192.168.0.1
      env.port 80
      env.instance_name web1
      env.instance_label WebSrv1

_/etc/munin/plugin-conf.d/apachestats\_web2_ :

    [apachestats_web2]
      env.host 192.168.0.2
      env.port 80
      env.instance_name web2
      env.instance_label WebSrv2


Troubleshooting
---------------

On error plugins return short error messages by default. Plugin debugging must 
be enabled to return full trace for exceptions. Use _munin-run_ with the 
_--pidebug_ option to enable plugin debugging.



		

Collaboration
-------------

I would be happy to receive suggestions on improving the code for developing 
_Munin Plugins_. You can use the _Issues_ functionality of _GitHub_ to 
document problems and to propose improvements. Alternatively you can use the 
internal messaging system of _GitHub_ or my e-mail address to contact me directly,
but the _Issues_ system is the preferred medium for reporting errors or 
proposing improvements.

I hope that by sharing the code, the existing plugins will get more testing and 
receive improvements, and many more _Multigraph Munin Plugins_ will be developed 
collaboratively.

I would be glad to receive some sample graphs from anyone using the plugins.



Development
-----------


### Design ###

The plugins consist of the following components:

* The _pymunin_ module ( _plugins/pymunin_ ) implements the base classes for 
developing Munin plugins.
	* Munin Plugins can be created by subclassing the _MuninPlugin_ class.
	* Each plugin contains one or more graphs implemented by _MuninGraph_ class 
	  instances.
	* The _muninMain_ function implements the entry point for _Munin Plugins_.
* The plugin logic is implemented in the plugin scripts in _pymunin/plugins_.
* The actual data retrieval logic is separated from the plugins to facilitate 
  code reuse. Individual modules in the directory _pysysinfo_ implement classes 
  for getting the monitoring data and returning them as dictionary objects. The 
  separation of the data retrieval logic should facilitate the use of the code 
  in other monitoring solutions.
* Common utility classes and methods used by various data retrieval modules are 
  placed in the _util_ module in _pysysinfo_. 


### Plugin Development ###

The first step for implementing a new _Multigraph Munin Plugin_ is developing a 
new module in _pysysinfo_ for retrieving the monitoring data.

The steps for developing the actual plugin script are as follows:

* Plugin scripts are placed in _pymunin/plugins_ by default.
* New plugins are implemented by extending the _MuninPlugin_ class in 
  _pymunin_. You can check the plugin scripts in _pymunin/plugins_ for 
  working examples.
* The _plugin_name_ property of _MuninPlugin_ class must be set to the name of 
  the plugin.
* Graph Objects are registered to the plugin in the constructor of the plugin 
  class.
* Code for creating graph objects which are instances of the _MuninGraph_ class 
  are placed in the constructor of the plugin class.
* Code for adding fields to the graph using the _addField_ method of the
  _MuninGraph_ class is placed in the constructor of the plugin class.
* Code for registering the graphs to plugin using the _appendGraph_ method of 
  the _MuninPlugin_ class is placed in the constructor of the plugin class.
* The _retrieveVals_ method of the plugin class is overwritten to retrieve data 
  points and to associate values with the graph fields using the _setGraphVal_ 
  method of the _MuninPlugin_ class.
* The _muninMain_ function in _/plugins/pymunin_ is called with the plugin 
  class as argument for initializing the main method of plugin.



Credits
-------

{% include credits.inc %}

Some of the people that have knowingly or unknowingly contributed to the 
development are:

* Initial packaging of the code was done by [mlavin] (https://github.com/mlavin) 
  (Mark Lavin). _PyMunin_ is installable _pip_ or _easy_install_ thanks to Mark. :-)
* _PyMunin_ has been packaged for _Fedora_ and _Red Hat Enterprise Linux_ by 
  [Matthias Runge](www.matthias-runge.de).
* The initial design of the solution was inspired 
  by [python-munin](https://github.com/samuel/python-munin) 
  by [samuel](https://github.com/samuel) (Samuel Stauffer).
* The Rackspace Cloud plugin was initially developed
  by [palewire](https://github.com/palewire) (Brian Welsh)
  and it is the first plugin that has been contributed to the project. 
* Many plugins were inspired by existing _Munin Plugins_developed by other 
  people. (Before developing any plugins, I always try to check existing 
  solutions.)
* Many people have contributed by testing the plugins and identifying issues.


I hope that more people will be using _{{page.prjname}}_ for developing 
plugins in the future.



License
-------

{% include license_gpl.inc %}