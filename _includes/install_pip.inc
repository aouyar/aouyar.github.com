The code can be downloaded and installed automatically 
using [pip](http://www.pip-installer.org/): 

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
	    	
The other option is to download and uncompress the code manually and 
execute the  included _setup.py_ script to start installation:

	./setup.py install
