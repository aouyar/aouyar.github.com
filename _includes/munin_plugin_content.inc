About
-----

{{ page.munin_plugin_long }}


Graphs
------

The plugin implements the following graphs:

{% for graph in page.munin_plugin_graphs %}

* {{ graph }}

{% endfor %}


{% if page.munin_plugin_samples %}

Samples
-------

Sample graphs for plugin:

<div class="ym-contain-dt">
{% for img in page.munin_plugin_samples %}
<img src="./img/{{ img.src }}" alt="{{ img.alt }}" class="float-left bordered">
{% endfor %}
</div>

{% endif %}



{% if page.munin_plugin_vars %}

Configuration
-------------

Configuration variables are passed to the _Munin Plugins_ using
_environment variables_. The environment variables for plugins are usually set 
in the plugin configuration files in the folder: _/etc/munin/plugin-conf.d_ 

The configuration variables implemented by the plugin are listed in the
following table:

<div class="ym-contain-dt">

<table>
	<thead>
	<tr>
		<th>Variable</th>
		<th>Description</th>
	</tr>
	</thead>
	<tbody>
{% for var in page.munin_plugin_vars %}
	<tr>
		<td>{{ var.name }}</td>
		<td>{{ var.desc | newline_to_br }}</td>
	</tr>
{% endfor %}
    </tbody>
</table>

</div>

{% endif %}



Credits
-------

_{{page.munin_plugin_short}}_ ( _{{ page.munin_plugin_name }}_ ) 
has been developed 
by [Ali Onur Uyar]({{ page.baseptr}}/) ([{{ site.user }} @ GitHub] (https://github.com/{{ site.user }})).



License
-------

_{{page.munin_plugin_short}}_ ( _{{ page.munin_plugin_name }}_ ) is copyrighted 
free software made available under the terms of the _GPL License Version 3_ or 
later.

See the file _COPYING_ that acompanies the code for full licensing information.