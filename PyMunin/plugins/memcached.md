---
baseptr: ../../..
layout: munin_plugin
description: PyMunin Munin Multigraph Monitoring Plugin for Memcached Cacher Server 
             in Python.
keywords: PyMunin, Munin, Plugin, Python, Multigraph, Monitoring, Memcached, Cache
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins
munin_plugin_name: memcachedstats
munin_plugin_short: Memcached Cache Server Plugin
munin_plugin_long: PyMunin Munin Multigraph Monitoring Plugin for Memcached  
                   Distributed Memory Object Caching System.
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
    - memcached_connections
    - memcached_items
    - memcached_memory
    - memcached_traffic
    - memcached_connrate
    - memcached_reqrate
    - memcached_statget
    - memcached_statset
    - memcached_statdel
    - memcached_statcas
    - memcached_statincrdecr
    - memcached_statevict
    - memcached_statauth
    - memcached_hitpct
    
munin_plugin_samples:
    - src: memcached_connections-day.png
      alt: Memcached - Active Connections
    - src: memcached_items-day.png
      alt: Memcached - Items
    - src: memcached_memory-day.png
      alt: Memcached - Memory Usage
    - src: memcached_traffic-day.png
      alt: Memcached - Throughput - Network
    - src: memcached_connrate-day.png
      alt: Memcached - Throughput - Connections
    - src: memcached_reqrate-day.png
      alt: Memcached - Throughput - Request Rate
    - src: memcached_statget-day.png
      alt: Memcached - Stats - Get
    - src: memcached_statset-day.png
      alt: Memcached - Stats - Set
    - src: memcached_statevict-day.png
      alt: Memcached - Stats - Evictions
    - src: memcached_hitpct-day.png
      alt: Memcached - Hit Percent

munin_plugin_vars:
    - name: host
      desc: |
            Memcached Server IP.
            (127.0.0.1 by default.)
    - name: port
      desc: |
            Memcached Server Port
            (11211 by default.)
    - name: include_graphs
      desc: |
            Comma separated list of enabled graphs.
            (All graphs enabled by default.)
    - name: exclude_graphs
      desc: Comma separated list of disabled graphs.


---

{% include munin_plugin_content.inc %}
