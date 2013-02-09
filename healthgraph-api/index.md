---
baseptr: ..
layout: project
description: |
             The Python Client Library for 
             [Health Graph API](http://developer.runkeeper.com/healthgraph) 
             can be used for accessing [RunKeeper](http://runkeeper.com) for 
             retrieving, updating, deleting and uploading Fitness Activity 
             and Health Measurement Information.
keywords: |
          Health Graph, healthgraph-api, runkeeper, API, Python, Health, Fitness,
          Training, Running, Measurement
prjname: healthgraph-api
prjdesc: Python Client Library for Health Graph API
prjpypi: true

hnav:
    - Updates
    - About
    - Download
    - Installation
    - Configuration
    - Samples
    - License
    
---

Updates
-------

{% assign post_list = site.categories.healthgraph-api %}
{% include prj_posts.inc %}


About
-----

Python Client Library for 
[Health Graph API](http://developer.runkeeper.com/healthgraph). 
The API can be used for accessing [RunKeeper](http://runkeeper.com) for retrieving, 
updating, deleting and uploading Fitness Activity and Health Measurement Information.

{% include prj_link_home.inc %}


Download
--------

{% include download.inc %}


Installation
------------
        
{% include install_pip.inc %}


Configuration
-------------

The Health Graph API uses OAuth 2.0 for security. Every application must be registered 
with the [Applications Portal of Health Graph](http://runkeeper.com/partner). 
Once registered, the application will be assigned a unique _Client Identifier_ 
and the _Client Secret_ for use with the Health Graph API.


Samples
-------

The distribution includes a sample basic web application based on the 
[Bottle Micro Web Framework](http://bottlepy.org/) for demonstrating how to use
the library.


### Installation and Configuration of the Sample Application ###

You can find the sample application in the following folder of the 
_healthgraph-api_ distribution: _./samples/bottle_.

Before running the sample application the prerequisite packages listed in 
_requirements.txt_ must be installed. The prerequisite packages can easily 
installed using [pip](http://www.pip-installer.org/):

	pip install -r requirements.txt
	
Note: The sample application requires fairly updated versions of the prerequisite
packages. Using [virtualenv](http://www.virtualenv.org/) is highly recommended 
for installing the application in a sandboxed environment with the latest versions
of the packages.

The _Client Identifier_ and the _Client Secret_ must be placed in the configuration
file for the sample application: *runkeeper_demo.conf*

The application can be run by executing:

	python runkeeper_demo.py -c runkeeper_demo.conf
	
The web interface could be reached at _localhost_ port _8000_ by default:
[http://127.0.0.1:8000](http://127.0.0.1:8000)


### Retrieval of the Access Token ###

The _Access Token_ for the 
[Health Graph API](http://developer.runkeeper.com/healthgraph)
can be retrieved by accesing the following _URL_ from *local_host*:
[http://127.0.0.1:8000/view_access_token](http://127.0.0.1:8000/view_access_token)

<p class="box error">
Sending the Access Token to the client to be displayed in a web browser is a 
security risk. This page is provided just for testing. Normally, the _Access Token_ 
must never be sent to the client.
</p>


License
-------

{% include license_gpl.inc %}