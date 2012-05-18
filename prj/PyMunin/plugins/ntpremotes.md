---
baseptr: ../../..
layout: munin_plugin
description: PyMunin Multigraph Munin Plugin in Python for monitoring and 
             comparing the synchronization status of multiple remote hosts.
keywords: PyMunin, Munin, Plugin, Python, Multigraph, Monitoring, NTP,
          Time Synchronization, Offset, Delay
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins
munin_plugin_name: ntphostoffsets
munin_plugin_short: NTP Host Offsets Plugin
munin_plugin_long: PyMunin Multigraph Munin Plugin for monitoring and 
                   comparing the synchronization status (stratum, offset, 
                   network delay) of multiple remote hosts using _ntpdate_.
munin_plugin_note: The list of remote hosts to be monitored must be passed to 
                   the plugin using the _ntphosts_ environment variable.

hnav:
    - About
    - Graphs
    - Samples
    - Configuration
    - Credits
    - License
                   
munin_plugin_graphs:
   - ntp_host_stratums
   - ntp_host_offsets
   - ntp_host_delays

munin_plugin_vars:
    - name: ntphosts
      desc: Comma separated list of IP addresses of hosts to be monitored.
    - name: include_graphs
      desc: |
            Comma separated list of enabled graphs.
            (All graphs enabled by default.)
    - name: exclude_graphs
      desc: Comma separated list of disabled graphs.

    
---

{% include munin_plugin_content.inc %}
