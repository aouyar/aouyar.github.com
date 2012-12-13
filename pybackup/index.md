---
baseptr: ..
layout: project
description: Python Module for implementing backup scripts.
keywords: python, backup, script, mysql, postgresql, archive, tar
prjname: pybackup
prjdesc: Python Module for Implementing Backup Scripts
prjpypi: false

hnav:
    - About
    - Download
    - Installation
    - Usage
    - License
    
---


About
-----

Backups scripts in _Python_, being developed as an alternative to backup task 
specific custom shell scripts. Backup jobs are defined in a configuration file 
and different backup methods are implemented by plugins, that improve on error 
checking and reporting.

Development started, when I was fed up with developing custom shell scripts for 
each backup task, and needed something with better error checking and reporting.

Backup methods are implemented by plugins that can be loaded at startup. The 
following plugins have been implemented for the time being:
* Archive: Generation of TAR archives from directories.
* PostgreSQL: Generation of dumps of PostgreSQL databases.
* MySQL: Generation of dumps of MySQL databases.
* Rsync: Replication of directory hierarchies using rsync.

*WARNING*: This is still alpha software.

{% include prj_link_home.inc %}


Download
--------

{% include download.inc %}


Installation
------------

{% include install_pip.inc %}

The application depends on _PyMunin_ and the dependency will automatically be
installed as long as there is a Internet connection, but you may have to install
_PyMunin_ manually if you do not have access to [PyPI](http://pypi.python.org).    


Usage
-----

Commandline Help:

    $ pybackup -h
    Usage: jobmgr.py [options]
    
    Options:
      -h, --help            show this help message and exit
      -c CONFPATH, --conf=CONFPATH
                            Path for configuration file.
      -q, --quiet           Minimal logging on console. Only print errors.
      -d, --debug           Activate debugging mode.
      -t, --trace           Activate tracing of errors.
      -n, --dry-run         Execute test run without executing the backup.
      -a, --all             Run all jobs listed in configuration file.
      -l, --list-jobs       List jobs defined in configuration file.
      -p, --list-plugins    List jobs defined in configuration file.
      -m, --list-methods    List available backup methods in loaded plugins.
      -g, --help-job        Print help text for general job options.
      -i, --help-method     Print help text for plugin method.
      

List Jobs:

    $ pybackup -c conf/pybackup.conf --list-jobs
    Job Name: syncbackup   Active: True    Method: rsync_backupdir
    Job Name: db_postgresql_export   Active: True    Method: pg_dump_full
    Job Name: db_mysql_export   Active: False    Method: mysql_dump_full
    Job Name: backupsrc   Active: True    Method: archive
    
    
List Plugins:

    $ pybackup -c conf/pybackup.conf --list-plugins
    Plugin: rsync   Module: pybackup.plugins.rsync
    Plugin for backups using rsync.
    
    Plugin: postgresql   Module: pybackup.plugins.postgresql
    Plugin for backups of PostgreSQL Database.
    
    Plugin: archive   Module: pybackup.plugins.archive
    Plugin for backups using tar archives.
    
    Plugin: mysql   Module: pybackup.plugins.mysql
    Plugin for backups of MySQL Database.


List Methods:

    $ pybackup -c conf/pybackup.conf --list-methods
    Plugin: archive
        Method: archive
    
    Plugin: mysql
        Method: mysql_dump_databases
        Method: mysql_dump_full
    
    Plugin: postgresql
        Method: pg_dump_databases
        Method: pg_dump_full
        Method: pg_dump_globals
    
    Plugin: rsync
        Method: rsync_backupdir
        Method: rsync_dirs


Help for Backup Methods:

    $ pybackup -c conf/pybackup.conf --help-method pg_dump_full
    General Job Options
    backup_root             : Root directory for storing backups.
    console_loglevel        : Logging level for console.
    filename_logfile        : Filename for log file.
    hostname_dir            : Create subdirectory for each hostname. (yes/no)
    logfile_loglevel        : Logging level for log file.
    post_exec               : Script to be executed after finishing running jobs.
    pre_exec                : Script to be executed before starting running jobs.
    umask                   : Umask for file and directory creation.
    user                    : If defined, check if script is being run by user.
    
    Plugin Generic Options
    active                  : Enable / disable backups job. (yes / no)
    job_name                : Job name.
    job_path                : Backup path for job.
    job_post_exec           : Script to be executed after backup job.
    job_pre_exec            : Script to be executed before backup job.
    method                  : Backup plugin method name.
    user                    : If defined, check if script is being run by user.
    
    Plugin Specific Options
    db_database             : Postgres Database for initial connection.
    db_host                 : PostgresSQL Database Server Name or IP.
    db_list                 : List of databases. (All databases by default.)
    db_password             : Postgres Database Server Password.
    db_port                 : Postgres Database Server Port.
    db_user                 : Postgres Database Server User.
    filename_dump_db        : Filename prefix for database dumps.
    filename_dump_globals   : Filename prefix for globals dump.


License
-------

{% include license_gpl.inc %}
