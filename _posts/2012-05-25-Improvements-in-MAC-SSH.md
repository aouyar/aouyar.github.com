---
layout: post
title: New features for MAC-SSH
category: MAC-Telnet
prjname: MAC-Telnet
excerpt: |
         Permit running _mactelnetd_ as unprivileged user in forwarding mode.
         New commandline options for _MAC-SSH_ mode, to permit setting of the 
         path for the _SSH_ client executable and for dropping privileges. 
         Permit passing additional parameters to _SSH_ client.
         
nopage: false
---

The following new features were implemented for the MAC-SSH mode:

* New commandline option ( _-c_ ) for setting the path for _SSH_ client
  executable.
* Permit passing of additional parameters to _SSH_ client executable
  on commandline. All parameters after -- are ignored by _MAC-Telnet_ client and
  passed directly to the _SSH_ client.
* Permit running _mactelnetd_ as unprivileged user, when forwarding 
  mode or _SSH_ mode is used. 
* New command line option ( _-U_ )for dropping privileges as soon as possible, when the
  client or server requieres privileged user, because of _-n_ option.
