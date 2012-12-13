---
baseptr: ../../..
layout: munin_plugin
description: PyMunin Munin Multigraph Monitoring Plugin for Sangoma Wanpipe 
             Telephony Interfaces in Python.
keywords: PyMunin, Munin, Plugin, Python, Multigraph, Monitoring, 
          Sangoma, Wanpipe, Wanrouter, Telephony, Interfaces, Traffic, Errors
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins
munin_plugin_name: wanpipestats
munin_plugin_short: Sangoma Wanpipe Telephony Interfaces Plugin
munin_plugin_long: PyMunin Munin Multigraph Monitoring Plugin for Sangoma Wanpipe 
                   Digital Telephony Interfaces.
munin_plugin_note: The plugin permits the generation of multiple graphs for 
                   multiple Wanpipe Telephony Interfaces by running the script 
                   only once instead of executing plugin scripts for each graph 
                   for every interface. All wanpipe interfaces except are 
                   graphed by default. 
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
    - wanpipe_traffic
    - wanpipe_errors
    - wanpipe_pri_errors    
    - wanpipe_pri_rxlevel

munin_plugin_vars:
    - name: include_ifaces
      desc: |
            Comma separated list of wanpipe interfaces to include in graphs.
            (All Wanpipe Interfaces are monitored by default.)
    - name: exclude_ifaces
      desc: Comma separated list of wanpipe interfaces to exclude from graphs.
    - name: include_graphs
      desc: |
            Comma separated list of enabled graphs.
            (All graphs enabled by default.)
    - name: exclude_graphs
      desc: Comma separated list of disabled graphs.

  
---

{% include munin_plugin_content.inc %}
