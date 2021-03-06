---
baseptr: ../../..
layout: munin_plugin
description: PyMunin Munin Multigraph Monitoring Plugin for Lighttpd Web Server in Python.
keywords: PyMunin, Munin, Plugin, Python, Multigraph, Monitoring, Lighttpd, Web Server
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins
munin_plugin_name: lighttpdstats
munin_plugin_short: Lighttpd Web Server Plugin
munin_plugin_long: PyMunin Multigraph Munin Plugin for monitoring Lighttpd Web 
                   Server.
munin_plugin_multigraph: true
munin_plugin_multiinstance: true
munin_plugin_note: The web server _status_ page handler must be configured 
                   and it must be accesible through the web server.

hnav:
    - About
    - Graphs
    - Samples
    - Configuration
    - Credits
    - License
                   
munin_plugin_graphs:
   - lighttpd_access
   - lighttpd_bytes
   - lighttpd_servers

munin_plugin_vars:
    - name: host
      desc: |
            Lighttpd Web Server Host.
            (Default: 127.0.0.1)
    - name: port
      desc: |
            Lighttpd Web Server Port
            (Default: 80, SSL: 443)
    - name: user
      desc: "User in case authentication is required for access to server-status page."
    - name: password
      desc: "Password in case authentication is required for access to server-status page."
    - name: statuspath
      desc: "Path for Lighttpd Web Server Status Page.\n(Default: server-status)"
    - name: ssl
      desc: "Use SSL if yes.\n(Default: no)"
    - name: include_graphs
      desc: |
            Comma separated list of enabled graphs.
            (All graphs enabled by default.)
    - name: exclude_graphs
      desc: Comma separated list of disabled graphs.


    
---

{% include munin_plugin_content.inc %}
