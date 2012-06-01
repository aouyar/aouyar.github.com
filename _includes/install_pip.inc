The code can be downloaded and installed automatically 
using [pip](http://www.pip-installer.org/) or the user can download and 
uncompress the code and execute the the included _setup.py_ script to start
installation.

{% if page.prjpypi %}
To install the latest version published 
in [PyPI](http://pypi.python.org/pypi/{{ page.prjname }})
using [pip](http://www.pip-installer.org/) execute:

    pip install {{ page.prjname }}
	
{% endif %}

To install the latest development version directly 
from [GitHub](https://github.com/{{ site.user }}/{{ page.prjname }})
using [pip](http://www.pip-installer.org/) execute:

    pip install git+https://github.com/aouyar/{{ page.prjname }}.git#egg={{ page.prjname }}
	    	
To install using the <i>setup.py</i> script included in the distribution once 
the code is downloaded
from [GitHub](https://github.com/{{ site.user }}/{{ page.prjname }})
and uncompressed manually:

<pre>./setup.py install</pre>
