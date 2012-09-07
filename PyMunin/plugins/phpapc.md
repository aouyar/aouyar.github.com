---
baseptr: ../../..
layout: munin_plugin
description: PyMunin Munin Multigraph Monitoring Plugin for APC PHP Accelaration Cache in Python.
keywords: PyMunin, Munin, Plugin, Python, Multigraph, Monitoring, APC, PHP, Cache, Accelarator
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins
munin_plugin_name: phpapcstats
munin_plugin_short: APC PHP Cache Plugin
munin_plugin_long: PyMunin Munin Multigraph Monitoring Plugin for APC PHP
                   Accelaration Cache.
munin_plugin_multigraph: true
munin_plugin_multiinstance: true
munin_plugin_note: The PHP script _apcinfo.php_ must be placed somewhere in the 
                   _document root_ and have access permissions from localhost 
                   to permit retrieval of stats from _APC_. The script can be 
                   found int the external utilities folder _ext_ folder of 
                   _PyMunin_ distribution.

hnav:
    - About
    - Graphs
    - Samples
    - Configuration
    - Credits
    - License
                   
munin_plugin_graphs:
   - php_apc_memory
   - php_apc_items
   - php_apc_reqs_filecache
   - php_apc_reqs_usercache
   - php_apc_expunge

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
      desc: "User in case authentication is required for access to PHP APC Status page."
    - name: password
      desc: "Password in case authentication is required for access to PHP APC Status page."
    - name: statuspath
      desc: |
            PHP APC status script path relative to Document Root.
            (Default: apcinfo.php)
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
