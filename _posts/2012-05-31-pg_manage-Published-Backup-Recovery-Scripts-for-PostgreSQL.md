---
layout: post
title: Published code for Backup / Recovery Scripts for PostgreSQL
category: pg_manage
prjname: pg_manage
keywords: pg_manage, postgresql, database, backup, restore, recovery, 
          archive logs, initialization, hot backups, dump, export, import, 
          replication, streaming
excerpt: |
         Just published a new project, 
         [pg_manage] (/pg_manage/) 
         at [GitHub] (https://github.com/aouyar/pg_manage/), which provides
         scripts for automating automating backup and recovery tasks for 
         _PostgreSQL Database Server_.
         
nopage: false
---

Just published a new project, [pg_manage] (/pg_manage/) 
at [GitHub] (https://github.com/aouyar/pg_manage/), which provides scripts for 
automating automating backup and recovery tasks for PostgreSQL Database Server.
The following operations have been implemented:

* Sending archive logs to backup server.
* Retrieval of archive logs from backup server.
* Initialization of the database.
* Generation of hot backups with archive logging.
* Recovery from hot backup.
* Dump (export) and restore (import) of databases.
* Initial synchronization of database servers for setting up replication.
* checking the replication between the primary and secondary 
  _PostgreSQL Servers_ in a _Streaming Replication_ setup.
  
Sample configuration files have been provided for configuring the 
_PostgreSQL Database Server_ for archive logging, recovery using archive logs
and _Streaming Replication_.



