---
layout: post
title: Support for running Multiple Instances of Plugins added to Core  
category: PyMunin
prjname: PyMunin
keywords: PyMunin, Munin, Plugin, multiple, instances, core, Apache, Asterisk,
          FreeSWITCH, Lighttpd, Memcached, MySQL, Nginx, NTP, PostgreSQL, PHP,
          APC, FPM, Rackspace, Tomcat, Varnish.
excerpt: |
         Support for running multiple instances of plugins has been added to 
         core. Apache, Lighttpd and Nginx Web Server, 
         Apache Tomcat Application Server, Varnish Web Cache, PHP APC and FPM,
         MySQL and PostgreSQL Database Server, Memcached, NTP Time Server 
         Asterisk and FreeSWITCH Telephony Server and Rackspace Cloud plugins
         have been converted into multi-instance plugins.
         
nopage: false
---

Support for running multiple instances of plugins has been added to the 
PyMunin Plugin Framework Core.

Implementing multi-instance support in the core permits converting any compliant
plugin to a multi-instance plugin without requiring any significant change to 
the plugin script itself; multi-instance support can be activated in any plugin 
by adding a single line to the plugin class definition to set the 
_isMultiInstance_ attribute to _True_.

The following plugins have been updated to add multi-instance support:

* Apache, Lighttpd and Nginx Web Server Plugins
* Apache Tomcat Application Server Plugin
* Varnish Web Cache Plugin
* PHP APC Cache and PHP FPM Plugins
* MySQL and PostgreSQL Database Server Plugins
* Memcached Plugin
* NTP Time Synchronization Plugins
* Asterisk and FreeSWITCH Telephony Server Plugins
* Rackspace Cloud Plugin

With this change multiple instances of web servers, application servers, 
database servers, etc. can be monitored from one node.

You can check the [PyMunin Project Documentation](/PyMunin/#configuration) for
more information of configuration of multiple instances of plugins.