---
baseptr: ../../..
layout: munin_plugin
description: PyMunin Munin Multigraph Monitoring Plugin for Process and Thread 
             Stats in Python.
keywords: PyMunin, Munin, Plugin, Python, Multigraph, Monitoring, Process, Thread
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins
munin_plugin_name: procstats
munin_plugin_short: Process and Thread Stats Plugin
munin_plugin_long: PyMunin Munin Multigraph Monitoring Plugin for Process and 
                   Thread Stats.

hnav:
    - About
    - Graphs
    - Samples
    - Configuration
    - Credits
    - License
                   
munin_plugin_graphs:
    - proc_status
    - proc_priority
    - thread_status
    - thread_priority

munin_plugin_vars:
    - name: include_graphs
      desc: |
            Comma separated list of enabled graphs.
            (All graphs enabled by default.)
    - name: exclude_graphs
      desc: Comma separated list of disabled graphs.


    
---

{% include munin_plugin_content.inc %}
