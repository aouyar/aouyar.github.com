---
baseptr: ../../..
layout: munin_plugin
description: PyMunin Munin Multigraph Monitoring Plugin for Disk Space and Inode Usage..
keywords: PyMunin, Munin, Plugin, Python, Multigraph, Monitoring, Disk, Disc, Usage, Utilization, Free, Space, Inode
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins
munin_plugin_name: diskusagestats
munin_plugin_short: Disk Space Utilization Plugin
munin_plugin_long: PyMunin Multigraph Munin Plugin for Monitoring Disk Space and 
                   Inode Usage of Filesystems.
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
   - diskspace
   - diskinode
    
    
munin_plugin_samples:
    - src: diskspace-day.png
      alt: Disk Space Usage
    - src: diskinode-day.png
      alt: Disk Inode Usage

munin_plugin_vars:
    - name: include_fspaths
      desc: |
            Comma separated list of filesystems to include in monitoring.
            (All enabled by default.)
    - name: exclude_fspaths
      desc: Comma separated list of filesystems to exclude from monitoring.
    - name: include_fstypes
      desc: |
            Comma separated list of filesystem types to include in monitoring.
            (All enabled by default.)
      name: exclude_fstypes
      desc: Comma separated list of filesystem types to exclude from monitoring.
    - name: include_graphs
      desc: |
            Comma separated list of enabled graphs.
            (All graphs enabled by default.)
    - name: exclude_graphs
      desc: Comma separated list of disabled graphs.


    
---

{% include munin_plugin_content.inc %}
