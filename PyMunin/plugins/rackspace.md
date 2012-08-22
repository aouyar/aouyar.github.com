---
baseptr: ../../..
layout: munin_plugin
description: PyMunin Munin Multigraph Monitoring Plugin for Rackspace Cloud in Python.
keywords: PyMunin, Munin, Plugin, Python, Multigraph, Monitoring, Rackspace, Cloud, Files
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins
munin_plugin_name: rackspacestats
munin_plugin_short: Rackspace Cloud Plugin
munin_plugin_long: PyMunin Multigraph Munin Plugin for monitoring Rackspace 
                   Cloud Services.
contributor: Rackspace Cloud Plugin (rackspacestats) 
             has been contributed
             by [palewire](https://github.com/palewire) (Ben Welsh).
updates: |
         * Plotting of stats for multiple containers in one graph.
         * Permit choosing auth servers (US vs. UK).
         * Permit using the Rackspace ServiceNet for accesing the cloud.
                   
hnav:
    - About
    - Graphs
    - Samples
    - Configuration
    - Credits
    - License
                   
munin_plugin_graphs:
    - rackspace_cloudfiles_container_size
    - rackspace_cloudfiles_container_count

munin_plugin_vars:
    - name: username
      desc: Rackspace Cloud username.
    - name: api_key
      desc: Rackspace Cloud api_key.
    - name: region
      desc: |
            Rackspace Auth Server Region.
            (US Auth Server is used by default.)
            Examples:
            - us: USA
            - uk: United Kingdom.
    - name: servicenet
      desc: |
            Enable (on) / disable (off) using the Rackspace ServiceNet for
            accessing the cloud. 
            (Disabled by default.)
    - name: include_container
      desc: Comma separated list of containers to include in graphs.
            (All enabled by default.)
    - name: exclude_container
      desc: Comma separated list of containers to exclude from graphs.
    - name: include_graphs
    - desc: |
            Comma separated list of enabled graphs.
            (All graphs enabled by default.)
    - name: exclude_graphs
      desc: Comma separated list of disabled graphs.   


    
---

{% include munin_plugin_content.inc %}
