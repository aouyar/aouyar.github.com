---
baseptr: ../../..
layout: munin_plugin
description: PyMunin Multigraph Munin Plugin in Python for monitoring 
             NTP Time Sychronization state of active sincronization peer.
keywords: PyMunin, Munin, Plugin, Python, Multigraph, Monitoring, NTP,
          Time Synchronization, Offset, Delay, Jitter
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins
munin_plugin_name: ntpstats
munin_plugin_short: NTP Time Sychronization State Plugin
munin_plugin_long: PyMunin Multigraph Munin Plugin for monitoring 
                   NTP Time Sychronization state of active sincronization peer
                   using _ntpq_.
munin_plugin_note: The plugin permits monitoring the stratum of the active peer 
                   and the estimated time offset, network delay and jitter.

hnav:
    - About
    - Graphs
    - Samples
    - Configuration
    - Credits
    - License
                   
munin_plugin_graphs:
    - ntp_peer_stratum
    - ntp_peer_stats
    
munin_plugin_samples:
    - src: ntp_peer_stratum-day.png
      alt: NTP Peer Stratum
    - src: ntp_peer_stats-day.png
      alt: NTP Peer Stats

munin_plugin_vars:
    - name: include_graphs
      desc: |
            Comma separated list of enabled graphs.
            (All graphs enabled by default.)
    - name: exclude_graphs
      desc: Comma separated list of disabled graphs.

    
---

{% include munin_plugin_content.inc %}
