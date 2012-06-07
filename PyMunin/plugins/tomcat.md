---
baseptr: ../../..
layout: munin_plugin
description: PyMunin Munin Multigraph Monitoring Plugin for Apache Tomcat Server in Python.
keywords: PyMunin, Munin, Plugin, Python, Multigraph, Monitoring, Apache, Tomcat, Application Server
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins
munin_plugin_name: tomcatstats
munin_plugin_short: Apache Tomcat Server Plugin
munin_plugin_long: PyMunin Multigraph Munin Plugin for monitoring Apache Tomcat 
                   Server.
munin_plugin_note: |
                   The _Apache Tomcat_ _status_ page must be configured and it 
                   must be accesible using credentials registered in 
                   _Plugin Configuration_.
                   
                   Configuration example from _tomcat-users.xml_ for _Tomcat 6_:
                   
                       <user username="munin" password="********" roles="standard,manager"/>
                   
                   Configuration example from _tomcat-users.xml_ for _Tomcat 7_, 
                   with minimum level of privileges; access to Status Page only:
                   
                       <user username="munin" password="********" roles="manager-status"/>
    
                   Configuration example from _tomcat-users.xml_ for _Tomcat 7_ 
                   with privileges to access to Manager GUI and Status Page:
                   
                       <user username="munin" password="********" roles="manager-gui,manager-status"/>

hnav:
    - About
    - Graphs
    - Samples
    - Configuration
    - Credits
    - License
                   
munin_plugin_graphs:
    - tomcat_memory
    - tomcat_threads
    - tomcat_access
    - tomcat_error
    - tomcat_traffic
    
munin_plugin_samples:
    - src: tomcat_access_8080-day.png
      alt: Tomcat Access
    - src: tomcat_traffic_8080-day.png
      alt: Tomcat Traffic
    - src: tomcat_threads_8080-day.png
      alt: Tomcat Threads
    - src: tomcat_error_8080-day.png
      alt: Tomcat Errors
    - src: tomcat_memory-day.png
      alt: Tomcat Memory

munin_plugin_vars:
    - name: host
      desc: |
            Apache Tomcat Host.
            (Default: 127.0.0.1)
    - name: port
      desc: |
            Apache Tomcat Port
            (Default: 80, SSL: 443)
    - name: user
      desc: Apache Tomcat Manager User.
    - name: password
      desc: Apache Tomcat Manager User.
    - name: ssl
      desc: "Use SSL if yes.\n(Default: no)"
    - name: include_ports
      desc: |
            Comma separated list of connector ports to include in graphs.
            (All included by default.)
    - name: exclude_ports
      desc: Comma separated list of connector ports to include in graphs.
    - name: include_graphs
      desc: |
            Comma separated list of enabled graphs.
            (All graphs enabled by default.)
    - name: exclude_graphs
      desc: Comma separated list of disabled graphs.


    
---

{% include munin_plugin_content.inc %}
