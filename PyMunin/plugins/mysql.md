---
baseptr: ../../..
layout: munin_plugin
description: PyMunin Munin Multigraph Monitoring Plugin for MySQL Database Server in Python.
keywords: PyMunin, Munin, Plugin, Python, Multigraph, Monitoring, MySQL, Database, MyISAM, InnoDB
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins
munin_plugin_name: mysqlstats
munin_plugin_short: MySQL Database Server Plugin
munin_plugin_long: PyMunin Multigraph Munin Plugin for monitoring MySQL 
                   Database Server.
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
    - mysql_connections
    - mysql_traffic
    - mysql_slowqueries
    - mysql_rowmodifications
    - mysql_rowreads
    - mysql_tablelocks
    - mysql_threads
    - mysql_proc_states
    - mysql_proc_db
    - mysql_commits_rollbacks
    - mysql_qcache_memory
    - mysql_qcache_hits
    - mysql_qcache_prunes
    - mysql_myisam_key_buffer_util
    - mysql_myisam_key_read_reqs
    - mysql_innodb_buffer_pool_util
    - mysql_innodb_buffer_pool_activity
    - mysql_innodb_buffer_pool_read_reqs
    - mysql_innodb_row_ops

munin_plugin_vars:
    - name: host
      desc: |
            MySQL Server IP
            (Defaults to UNIX socket if not provided.)
    - name: port
      desc: | 
            MySQL Server Port
            (Defaults to 3306 for network connections.)
    - name: database
      desc: MySQL Database
            (NULL by default.)
    - name: user
      desc: |
            Database User Name
            (The default is the login of OS user for UNIX sockets.
            Must be specified for network connections.)
    - name: password
      desc: |
            Database User Password
            (Attempt login without password by default.)
    - name: include_db
      desc: |
            Comma separated list of databases to include in detail graphs.
            (All enabled by default.)
    - name: exclude_db
      desc: Comma separated list of databases to exclude from detail graphs.
    - name: detail_graphs
      desc: | 
            Enable (on) / disable (off) detail graphs.
            (Disabled by default.)
    - name: include_engine
      desc: Comma separated list of storage engines to include graphs.
            (All enabled by default.)
    - name: exclude_engine
      desc: Comma separated list of storage engines to exclude from graphs.
    - name: include_graphs
      desc: |
            Comma separated list of enabled graphs.
            (All graphs enabled by default.)
    - name: exclude_graphs
      desc: Comma separated list of disabled graphs.


    
---

{% include munin_plugin_content.inc %}
