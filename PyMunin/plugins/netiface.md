---
baseptr: ../../..
layout: munin_plugin
description: PyMunin Munin Multigraph Monitoring Plugin for Network Interfaces in Python.
keywords: PyMunin, Munin, Plugin, Python, Multigraph, Monitoring, 
          Network Interfaces, Traffic, Errors
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins
munin_plugin_name: netifacestats
munin_plugin_short: Network Interfaces Plugin
munin_plugin_long: PyMunin Multigraph Munin Plugin for monitoring Network Interfaces.
munin_plugin_note: The plugin permits the generation of the traffic and error 
                   graphs for multiple network interfaces by running the script 
                   only once instead of executing plugin scripts for each graph 
                   for every interface. All interfaces except _lo_ are graphed 
                   by default. 
hnav:
    - About
    - Graphs
    - Samples
    - Configuration
    - Credits
    - License
                   
munin_plugin_graphs:
    - netiface_traffic
    - netiface_errors
    
munin_plugin_samples:
    - src: netiface_traffic_eth0-day.png
      alt: Network Interface Traffic
    - src: netiface_errors_eth0-day.png
      alt: Network Interface Errors

munin_plugin_vars:
    - name: include_ifaces
      desc: |
            Comma separated list of network interfaces to include in graphs.
            (All Network Interfaces are monitored by default.)
    - name: exclude_ifaces
      desc: Comma separated list of network interfaces to exclude from graphs.
    - name: include_graphs
      desc: |
            Comma separated list of enabled graphs.
            (All graphs enabled by default.)
    - name: exclude_graphs
      desc: Comma separated list of disabled graphs.


    
---

{% include munin_plugin_content.inc %}
