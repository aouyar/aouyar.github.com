---
baseptr: ../../..
layout: munin_plugin
description: PyMunin Munin Multigraph Monitoring Plugin for Asterisk in Python.        
keywords: PyMunin, Munin, Plugin, Python, Multigraph, Monitoring, Asterisk, Telephony
prjname: PyMunin
prjdesc: Python Module for developing Munin Multigraph Monitoring Plugins
munin_plugin_name: asteriskstats
munin_plugin_short: Asterisk Telephony Server Plugin
munin_plugin_long: PyMunin Multigraph Munin Plugin for monitoring Asterisk 
                   Telephony Server.

hnav:
    - About
    - Graphs
    - Samples
    - Configuration
    - Credits
    - License
                   
munin_plugin_graphs:
    - asterisk_calls
    - asterisk_channels
    - asterisk_peers_sip
    - asterisk_peers_iax2
    - asterisk_voip_codecs
    - asterisk_conferences
    - asterisk_voicemail
    - asterisk_trunks
    - asterisk_queue_len
    - asterisk_queue_avg_hold
    - asterisk_queue_avg_talk
    - asterisk_queue_calls
    - asterisk_queue_abandon_pcent
    - asterisk_fax_attempts
    
munin_plugin_samples:
    - src: asterisk_calls-day.png
      alt: Asterisk Calls
    - src: asterisk_trunks-day.png
      alt: Asterisk Trunks
    - src: asterisk_peers_sip-day.png
      alt: Asterisk SIP Peers
    - src: asterisk_peers_iax2-day.png
      alt: Asterisk IAX2 Peers
    - src: asterisk_channels-day.png
      alt: Asterisk Channels
    - src: asterisk_voip_codecs-day.png
      alt: Asterisk VoIP Codecs

munin_plugin_vars:
    - name: amihost
      desc: |
            IP of Asterisk Server.
            (Default: 127.0.0.1)
    - name: amiport
      desc: |
            Asterisk Manager Interface Port.
            (Default: 5038)
    - name: amiuser
      desc: |
            Asterisk Manager Interface User.
    - name: amipass
      desc: Asterisk Manager Interface Password.
    - name: list_channels
      desc: |
            List of channels that will be shown in channel stats.
            (Default: dahdi,zap,sip',iax2,local)
            Note: Channel expressions are case insensitive.
    - name: list_codecs
      desc: |
            List of codecs that will be shown in VoIP channel stats.
            Any codec that is not in the list will be counted as 'other'.
            (Default: alaw,ulaw,gsm,g729)
            Note: Channel expressions are case insensitive.
    - name: list_trunks
      desc: "Comma separated search expressions of the following formats:\n    - \"Trunk Name\"=\"Regular Expr\"\n    - \"Trunk Name\"=\"Regular Expr with Named Group 'num'\"=\"MIN\"-\"MAX\"\nCheck Python Regular Expressions docs for help on writing regular expressions: http://docs.python.org/library/re.html\nNote: Trunk expressions are case insensitive."
    - name: include_queues
      desc: |
            Comma separated list of queues to include in  graphs.
            (All queues included by default.)
    - name: exclude_queues
      desc: Comma separated list of queues to exclude from graphs.
    - name: include_graphs
      desc: |
            Comma separated list of enabled graphs.
            (All graphs enabled by default.)
    - name: exclude_graphs
      desc: Comma separated list of disabled graphs.


    
---

{% include munin_plugin_content.inc %}
