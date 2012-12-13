---
layout: post
title: Redis Server Plugin Released 
category: PyMunin
prjname: PyMunin
keywords: PyMunin, Munin, Plugin, Redis, Server
excerpt: |
         A Multigraph Munin Plugin has been implemented for Redis Server.
         
nopage: false
---

Redis Server Multigraph Munin Plugin has been released. The plugin currently 
implements the following graphs:
* redis_ping
* redis_conn_client
* redis_conn_rate
* redis_cmd_rate
* redis_memory
* redis_memory_fragmentation
* redis_cpu_util
* redis_hits_misses
* redis_keys_expired
* redis_keys_evicted
* redis_subscriptions

You can check the [Plugin Documentation](/PyMunin/plugins/redis.html) for more
information on the plugin.

I would be implementing some additional graphs within a few weeks. In the mean 
time I would be glad to have feedback from anyone that would be using the plugin.
Plus it could be great to have some sample graphs to publish on the website.

