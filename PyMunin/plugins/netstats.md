---
baseptr: ../../..
layout: munin_plugin
description: PyMunin Munin Multigraph Monitoring Plugin for Network Connection 
             Stats in Python.
keywords: PyMunin, Munin, Plugin, Python, Multigraph, Monitoring, Network, 
          Connection, Netstat
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins
munin_plugin_name: netstats
munin_plugin_short: Network Connection Stats Plugin
munin_plugin_long: PyMunin Munin Multigraph Monitoring Plugin for Network 
                   Connection Stats obtained from _netstat_.
munin_plugin_multigraph: true
munin_plugin_multiinstance: false

hnav:
    - About
    - Graphs
    - Samples
    - Configuration
    - Credits
    - License
                   
munin_plugin_graphs:
    - netstat_conn_status
    - netstat_conn_server

munin_plugin_vars:
    - name: list_server_ports
      desc: Comma separated list of Name:PortNumber tuples for services that 
            are to be monitored in the netstat_server_conn graph.
            A service can be associated to multiple port numbers separated by 
            colon.
    - name: include_graphs
      desc: |
            Comma separated list of enabled graphs.
            (All graphs enabled by default.)
    - name: exclude_graphs
      desc: Comma separated list of disabled graphs.


    
---

{% include munin_plugin_content.inc %}
