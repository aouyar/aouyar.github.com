About
-----

{{ page.munin_plugin_long }}

{% if page.munin_plugin_note %}

{{ page.munin_plugin_note }}

{% endif %}

<table class="fitwidth">
	<tr>
		<td>Multigraph Plugin:</td>
		<td>
			{%if page.munin_plugin_multigraph %}
				Yes
			{% else %}
			    No
			{% endif %}
		</td>
	</tr>
	<tr>
		<td>Multi-instance Plugin:</td>
		<td>
			{%if page.munin_plugin_multiinstance %}
				Yes
			{% else %}
			    No
			{% endif %}
		</td>
	</tr>
</table>

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

<table>
{% for img in page.munin_plugin_samples %}
{% cycle '<tr>', '' %}
	<td>
		<img src="./img/{{ img.src }}" alt="{{ img.alt }}" class="float-left bordered">
	</td>
{% if forloop.last %}
</tr>
{% else %}
{% cycle '', '</tr>' %}
{% endif %}
{% endfor %}
</table>

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

{% if page.munin_plugin_multiinstance %}

Additionally the following configuration variables are implemented by the plugin 
for _Multi Instance_ support:

<div class="ym-contain-dt">

<table>
	<thead>
	<tr>
		<th>Variable</th>
		<th>Description</th>
	</tr>
	</thead>
	<tbody>
	<tr>
		<td>instance_name</td>
		<td>Name of instance.</td>
	</tr>
	<tr>
		<td>instance_label</td>
		<td>Graph title label for instance.
            (Default is the same as instance name.)</td>
	</tr>
	<tr>
		<td>instance_label_format</td>
		<td>
			Controls how the instance label will be added to the graph title:
			<ul>
				<li>suffix (Default)</li>
                <li>prefix</li>
                <li>none</li>
			</ul>
		</td>
	</tr>
    </tbody>
</table>

</div>

{% endif %}

{% endif %}



Credits
-------

{% if page.contributor %}
{{ page.contributor | markdownify }}
  {% if page.contributor %}
  The following improvements have been implemented
  by [{{ site.username }}]({{ page.baseptr}}/) ([{{ site.user }} @ GitHub] (https://github.com/{{ site.user }})):
  
  {{ page.updates | markdownify }}
  
  {% endif %}
{% else %}
_{{ page.munin_plugin_short }}_ ( _{{ page.munin_plugin_name }}_ ) 
has been developed 
by [{{ site.username }}]({{ page.baseptr}}/) ([{{ site.user }} @ GitHub] (https://github.com/{{ site.user }})).
{% endif %}


License
-------

_{{page.munin_plugin_short}}_ ( _{{ page.munin_plugin_name }}_ ) is copyrighted 
free software made available under the terms of the _GPL License Version 3_ or 
later.

See the file _COPYING_ that acompanies the code for full licensing information.