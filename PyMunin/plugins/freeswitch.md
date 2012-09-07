---
baseptr: ../../..
layout: munin_plugin
description: PyMunin Munin Multigraph Monitoring Plugin for FreeSWITCH Soft 
             Switch in Python.        
keywords: PyMunin, Munin, Plugin, Python, Multigraph, Monitoring, FreeSWITCH, 
          Soft Switch, Telephony
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins
munin_plugin_name: fsstats
munin_plugin_short: FreeSWITCH Telephony Server Plugin
munin_plugin_long: PyMunin Multigraph Munin Plugin for monitoring FreeSWITCH 
                   Soft Switch.
munin_plugin_multigraph: true
munin_plugin_multiinstance: true

hnav:
    - About
    - Graphs
    - Samples
    - Configuration
    - Credits
    - License
                   
munin_plugin_graphs:
    - fs_calls
    - fs_channels

munin_plugin_samples:
    - src: fs_calls-day.png
      alt: Active Calls
    - src: fs_channels-day.png
      alt: Active Channels

munin_plugin_vars:
    - name: fshost
      desc: |
            FreeSWITCH Server
            (Default: 127.0.0.1)
    - name: fsport
      desc: |
            FreeSWITCH Event Socket Port
            (Default: 8021)
    - name: fspass
      desc: FreeSWITCH Event Socket Password
    - name: include_graphs
      desc: |
            Comma separated list of enabled graphs.
            (All graphs enabled by default.)
    - name: exclude_graphs
      desc: Comma separated list of disabled graphs.


    
---

{% include munin_plugin_content.inc %}
