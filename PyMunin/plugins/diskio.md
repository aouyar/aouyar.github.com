---
baseptr: ../../..
layout: munin_plugin
description: PyMunin Munin Multigraph Monitoring Plugin for Disk I/O.
keywords: PyMunin, Munin, Plugin, Python, Multigraph, Monitoring, I/O, Disk, Disc, LVM
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins
munin_plugin_name: diskiostats
munin_plugin_short: Disk I/O Plugin
munin_plugin_long: PyMunin Multigraph Munin Plugin for Monitoring Disk I/O Stats.
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
    - diskio_disk_requests
    - diskio_disk_bytes
    - diskio_disk_active
    - diskio_part_requests
    - diskio_part_bytes
    - diskio_part_active
    - diskio_md_requests
    - diskio_md_bytes
    - diskio_md_active
    - diskio_lv_requests
    - diskio_lv_bytes
    - diskio_lv_active
    - diskio_fs_requests
    - diskio_fs_bytes
    - diskio_fs_active
    
    
munin_plugin_samples:
     - src: diskio_disk_requests-day.png
       alt: Disk I/O - Disk - Requests
     - src: diskio_disk_bytes-day.png
       alt: Disk I/O - Disk - Throughput
     - src: diskio_part_requests-day.png
       alt: Disk I/O - Partition - Requests
     - src: diskio_part_bytes-day.png
       alt: Disk I/O - Partition - Throughput
     - src: diskio_lv_requests-day.png
       alt: Disk I/O - LV - Requests
     - src: diskio_lv_bytes-day.png
       alt: Disk I/O - LV - Throughput
     - src: diskio_disk_active-day.png
       alt: Disk I/O - Disk - Queue Length

munin_plugin_vars:
    - name: include_graphs
      desc: |
            Comma separated list of enabled graphs.
            (All graphs enabled by default.)
    - name: exclude_graphs
      desc: Comma separated list of disabled graphs.


    
---

{% include munin_plugin_content.inc %}
