---
layout: post
title: Experiments with PyMunin - Config and Fetch in JSON Format
category: PyMunin
prjname: PyMunin
keywords: PyMunin, Munin, Plugin, Framework, Experiment, Fetch, Config, JSON
excerpt: |
         Created experimental branch _json_ for implementing _Config_ 
         ( _json\_config_ ) and _Fetch_ ( _json\_fetch_ ) operations that return 
         configuration and values in JSON format. This simple exercise proves 
         that the _Munin Multigraph Plugin Framework_ is quite flexible; new
         output formats can be added without any modifications to the plugin
         scripts.
         
nopage: false
---

In my humble opinion _Munin Plugins_ provide a very flexible approach to 
gathering metrics and a trivial process for developing new plugins, but the 
backend for storing metrics and plotting graphs could be improved greatly by
supporting storage backends like [OpenTSDB] (http://opentsdb.net/) for
scalibility and _Javascript_ graphing libraries like 
[Flot] (http://code.google.com/p/flot/) for interactive graphs on the client 
side.

In case of using alternative backends it might be beneficial to use a standard 
data interchange format instead of parsing the textual plugin output. I created 
an experimental branch _json_ for implementing _Config_ ( _json\_config_ ) and 
_Fetch_ ( _json\_fetch_ ) operations that return configuration and values in 
JSON format. This simple exercise proves that the 
_Munin Multigraph Plugin Framework_ is quite flexible; newoutput formats can be 
added without any modifications to the plugin scripts themselves. You can try
the new operations by executing the plugin scripts directly with _json\_config_
or _json\_fetch_ parameter. You might have to set certain environment variables
manually as _munin-run_ does not recognize json\_config_ or _json\_fetch_ as 
valid operations.

