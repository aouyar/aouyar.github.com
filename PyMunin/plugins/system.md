---
baseptr: ../../..
layout: munin_plugin
description: PyMunin Munin Multigraph Monitoring Plugin for System Resources 
             (Load, CPU, Memory, Processes, Interrupts, etc.) in Python.
keywords: PyMunin, Munin, Plugin, Python, Multigraph, Monitoring,
          System, Resources, Load, CPU, Processor, Memory, Paging, Swapping,
          Processes, Interrupts
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins
munin_plugin_name: sysstats
munin_plugin_short: System Resources Plugin
munin_plugin_long: PyMunin Multigraph Munin Plugin for monitoring System 
                   Resources; Load Average, CPU and Memory Utilization, 
                   Processes, Forks, Interrupts, Context Switches, Paging and 
                   Swapping etc.
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
    - sys_loadavg
    - sys_cpu_util
    - sys_memory_util
    - sys_memory_avail
    - sys_processes
    - sys_forks
    - sys_intr_ctxt
    - sys_vm_paging
    - sys_vm_swapping
    
munin_plugin_samples:
    - src: sys_cpu_util-day.png
      alt: CPU Utilization
    - src: sys_loadavg-day.png
      alt: Load Average
    - src: sys_mem_avail-day.png
      alt: Memory Active/Inactive
    - src: sys_mem_util-day.png
      alt: Memory Utilization
    - src: sys_vm_paging-day.png
      alt: VM Paging
    - src: sys_vm_swapping-day.png
      alt: VM Swapping

munin_plugin_vars:
    - name: include_graphs
      desc: |
            Comma separated list of enabled graphs.
            (All graphs enabled by default.)
    - name: exclude_graphs
      desc: Comma separated list of disabled graphs.


    
---

{% include munin_plugin_content.inc %}
