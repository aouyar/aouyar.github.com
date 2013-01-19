---
layout: post
title: Release of Python Library for Healh Graph API
category: healthgraph-api
prjname: healthgraph-api
keywords: Health Graph, healthgraph-api, runkeeper, API, Python, release
excerpt: |
         The first usable version of the Python Client Library for 
         [Health Graph API](http://developer.runkeeper.com/healthgraph) 
         was released. The current version can be used for accessing 
         [RunKeeper](http://runkeeper.com) to retrieve Fitness Activity 
         and Health Measurement Information.
         
nopage: false
---

I just published the first usable version of the Python Client Library for 
accessing [RunKeeper](http://runkeeper.com) using 
[Health Graph API](http://developer.runkeeper.com/healthgraph) on
[PyPI](http://pypi.python.org/pypi/healthgraph-api).
The current version does not implement uploading, modifying or deleting 
Fitness Activities or Health Measurements. It can only be used for retrieving 
Fitness Activity and Health Measurement Information.

You can check the [Project Documentation](/healthgraph-api/index.html) for more
information on using the library.

The distribution includes a sample basic web application based on the 
[Bottle Micro Web Framework](http://bottlepy.org/) for demonstrating how to use
the library.

I am planning to implement significant changes in the library, so the current
code should only be used for testing.
