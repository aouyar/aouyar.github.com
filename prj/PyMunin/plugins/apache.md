---
baseptr: ../../..
layout: munin_plugin
description: PyMunin Munin Multigraph Monitoring Plugin for Apache in Python.
             
keywords: PyMunin, Munin, Plugin, Python, Multigraph, Monitoring, Apache
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins
munin_plugin_name: apachestats
munin_plugin_short: Apache Web Server Plugin
munin_plugin_long: PyMunin Multigraph Munin Plugin for monitoring Apache Web 
                   Server.

hnav:
    - About
    - Graphs
    - Samples
    - Configuration
    - Credits
    - License
                   
munin_plugin_graphs:
    - apache_access
    - apache_bytes
    - apache_workers
    
munin_plugin_samples:
    - src: apache_access-day.png
      alt: Apache Access
    - src: apache_bytes-day.png
      alt: Apache Traffic
    - src: apache_workers-day.png
      alt: Apache Workers

munin_plugin_vars:
    - name: host
      desc: |
            Apache Web Server Host.
            (Default: 127.0.0.1)
    - name: port
      desc: |
            Apache Web Server Port
            (Default: 80, SSL: 443)
    - name: user
      desc: "User in case authentication is required for access to server-status page."
    - name: password
      desc: "Password in case authentication is required for access to server-status page."
    - name: statuspath
      desc: "Path for Apache Web Server Status Page.\n(Default: server-status)"
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
