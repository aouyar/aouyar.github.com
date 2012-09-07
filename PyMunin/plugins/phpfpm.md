---
baseptr: ../../..
layout: munin_plugin
description: PyMunin Munin Multigraph Monitoring Plugin for PHP FPM (FastCGI Process Manager) in Python.
keywords: PyMunin, Munin, Plugin, Python, Multigraph, Monitoring, Web Server, PHP, FPM, FastCGI
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins
munin_plugin_name: phpfpmstats
munin_plugin_short: PHP FPM Plugin
munin_plugin_long: PyMunin Munin Multigraph Monitoring Plugin for 
                   PHP FPM (FastCGI Process Manager)
munin_plugin_multigraph: true
munin_plugin_multiinstance: true
munin_plugin_note: The _PHP FPM_ status page must be configured and it must be 
                   accesible through the web server.

hnav:
    - About
    - Graphs
    - Samples
    - Configuration
    - Credits
    - License
                   
munin_plugin_graphs:
    - php_fpm_connections
    - php_fpm_processes

munin_plugin_vars:
    - name: host
      desc: |
            Web Server Host.
            (Default: 127.0.0.1)
    - name: port
      desc: |
            Web Server Port
            (Default: 80, SSL: 443)
    - name: user
      desc: "User in case authentication is required for access to PHP FPM Status page."
    - name: password
      desc: "Password in case authentication is required for access to PHP FPM Status page."
    - name: statuspath
      desc: |
            PHP FPM status page path relative to Document Root.
            (Default: fpm_status.php)
    - name: ssl
      desc: "Use SSL if yes.\n(Default: no)"
    - name: include_graphs
      desc: |
            Comma separated list of enabled graphs.
            (All graphs enabled by default.)
    - name: exclude_graphs
      desc: Comma separated list of disabled graphs.



    
---

{% include munin_plugin_content.inc %}
