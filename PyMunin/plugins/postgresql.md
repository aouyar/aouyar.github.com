---
baseptr: ../../..
layout: munin_plugin
description: PyMunin Munin Multigraph Monitoring Plugin for PostgreSQL Database Server in Python.
keywords: PyMunin, Munin, Plugin, Python, Multigraph, Monitoring, PostgreSQL, Database
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins
munin_plugin_name: pgstats
munin_plugin_short: PostgreSQL Database Server Plugin
munin_plugin_long: PyMunin Multigraph Munin Plugin for monitoring PostgreSQL 
                   Database Server.

hnav:
    - About
    - Graphs
    - Samples
    - Configuration
    - Credits
    - License
                   
munin_plugin_graphs:
    - pg_connections
    - pg_diskspace
    - pg_blockreads
    - pg_xact
    - pg_checkpoints
    - pg_bgwriter
    - pg_tup_read
    - pg_tup_write
    - pg_blockreads_detail
    - pg_xact_commit_detail
    - pg_xact_rollback_detail
    - pg_tup_return_detail
    - pg_tup_fetch_detail
    - pg_tup_delete_detail
    - pg_tup_update_detail
    - pg_tup_insert_detail
    - pg_locks_all
    - pg_locks_wait
    
munin_plugin_samples:
    - src: pg_connections-day.png
      alt: PostgreSQL Connections
    - src: pg_diskspace-day.png
      alt: PostgreSQL Disk Space
    - src: pg_blockreads-day
      alt: PostgreSQL Block Reads
    - src: pg_xact-day.png
      alt: PostgreSQL Transactions
    - src: pg_tup_read-day.png
      alt: PostgreSQL Tuple Reads
    - src: pg_tup_write-day.png
      alt: PostgreSQL Tuple Writes
    - src: pg_bgwriter-day.png
      alt: PostgreSQL BgWriter Stats
    - src: pg_checkpoints-day.png
      alt: PostgreSQL Checkpoints

munin_plugin_vars:
    - name: host
      desc: |
            PostgreSQL Server IP
            (Defaults to UNIX socket if not provided.)
    - name: port
      desc: | 
            PostgreSQL Server Port
            (Defaults to 5432 for network connections.)
    - name: database
      desc: |
            PostgreSQL Database for monitoring connection
            (The default is the login the for connecting user.)
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
    - name: include_graphs
      desc: |
            Comma separated list of enabled graphs.
            (All graphs enabled by default.)
    - name: exclude_graphs
      desc: Comma separated list of disabled graphs.


    
---

{% include munin_plugin_content.inc %}
