---
baseptr: ../../..
layout: munin_plugin
description: PyMunin Munin Multigraph Monitoring Plugin for Varnish Cache in Python.
keywords: PyMunin, Munin, Plugin, Python, Multigraph, Monitoring, Varnish, Cache, Proxy, Reverse
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins
munin_plugin_name: varnishstats
munin_plugin_short: Varnish Cache Plugin
munin_plugin_long: PyMunin Multigraph Munin Plugin for monitoring Varnish Cache
                   Web Application Accelerator.
munin_plugin_note: The plugin must be run with a user with sufficient privileges
                   to execute varnishstat utility.

hnav:
    - About
    - Graphs
    - Samples
    - Configuration
    - Credits
    - License
                   
munin_plugin_graphs:
    - varnish_client_conn
    - varnish_client_requests
    - varnish_backend_conn
    - varnish_backend_requests
    - varnish_traffic
    - varnish_workers
    - varnish_hits

munin_plugin_vars:
    - name: instance 
      desc: |
            Name  of the Varnish Cache instance.
            (Defaults to hostname.) 
    - name: include_graphs
      desc: |
            Comma separated list of enabled graphs.
            (All graphs enabled by default.)
    - name: exclude_graphs
      desc: Comma separated list of disabled graphs.


    
---

{% include munin_plugin_content.inc %}
