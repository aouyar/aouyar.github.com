---
baseptr: ../../..
layout: munin_plugin
description: PyMunin Multigraph Munin Plugin in Python for monitoring 
             the synchronization status of a single remote host.
keywords: PyMunin, Munin, Plugin, Python, Multigraph, Monitoring, NTP,
          Time Synchronization, Offset, Delay.
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins
munin_plugin_name: ntphostoffset
munin_plugin_short: NTP Host Offset Plugin
munin_plugin_long: PyMunin Multigraph Munin Plugin for monitoring the 
                   synchronization status (stratum, offset, network delay) of 
                   a single remote host using _ntpdate_.
munin_plugin_multigraph: true
munin_plugin_multiinstance: true
munin_plugin_note: This a _wild card_ plugin and the name of the plugin must be 
                   suffixed with the _IP_ of the host to be monitored, when 
                   linking the plugin script to the _Munin Plugins Directory_ 
                   ( _/etc/munin/plugins_ ).

hnav:
    - About
    - Graphs
    - Samples
    - Configuration
    - Credits
    - License
                   
munin_plugin_graphs:
   - ntp_host_stratum
   - ntp_host_stat

munin_plugin_vars:
    - name: include_graphs
      desc: |
            Comma separated list of enabled graphs.
            (All graphs enabled by default.)
    - name: exclude_graphs
      desc: Comma separated list of disabled graphs.

    
---

{% include munin_plugin_content.inc %}
