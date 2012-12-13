---
layout: post
title: Persistence Graphs Added to Redis Server Plugin
category: PyMunin
prjname: PyMunin
keywords: PyMunin, Munin, Plugin, Redis, Server
excerpt: |
         RDB and AOF persistence monitoring graphs added to Multigraph Munin 
         Plugin for Redis Server.
         
nopage: false
---

The following graphs have been added to Redis Server Multigraph Munin Plugin 
for monitoring RDB Snapshots and AOF Logging:
* redis_rdb_changes
* redis_rdb_dumptime
* redis_aof_filesize
* redis_aof_bufflen
* redis_aof_rewrite_bufflen
* redis_aof_rewritetime

You can check the [Plugin Documentation](/PyMunin/plugins/redis.html) for more
information on the plugin.

I would be implementing some additional graphs within a few weeks. In the mean 
time I would be glad to have feedback from anyone that would be using the plugin.
Plus it could be great to have some sample graphs to publish on the website.

