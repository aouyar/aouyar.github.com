---
baseptr: ../../..
layout: munin_plugin
description: PyMunin Munin Multigraph Monitoring Plugin for Redis Server in Python.
keywords: PyMunin, Munin, Plugin, Python, Multigraph, Monitoring, Redis
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins
munin_plugin_name: redisstats
munin_plugin_short: Redis Server Plugin
munin_plugin_long: PyMunin Multigraph Munin Plugin for monitoring Redis Server.
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
    - redis_ping
    - redis_conn_client
    - redis_conn_rate
    - redis_cmd_rate
    - redis_memory
    - redis_memory_fragmentation
    - redis_cpu_util
    - redis_hits_misses
    - redis_keys_expired
    - redis_keys_evicted
    - redis_subscriptions

munin_plugin_vars:
    - name: host
      desc: |
            Redis Server Host.
            (127.0.0.1 by default.)
    - name: port
    - desc: |
            Redis Server Port.
            (6379  by default.)
    - name: db
      desc: |
            Redis DB ID.
            (0 by default.)
    - name: password
      desc: Redis Password (Optional)
    - name: socket_timeout
      desc: |
            Redis Socket Timeout
            (Default: OS Default.)
    - name: unix_socket_path
      desc: |
            Socket File Path for UNIX Socket connections.
            (Not required unless connection to Redis is through named socket.)
    - name: include_graphs
      desc: |
            Comma separated list of enabled graphs.
            (All graphs enabled by default.)
    - name: exclude_graphs
      desc: Comma separated list of disabled graphs.   


    
---

{% include munin_plugin_content.inc %}
