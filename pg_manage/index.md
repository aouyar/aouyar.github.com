---
baseptr: ..
layout: project
description: Backup / Recovery Scripts for PostgreSQL Database.
keywords: pg_manage, postgresql, database, backup, restore, recovery, 
          archive logs, initialization, hot backups, dump, export, import, 
          replication, streaming
prjname: pg_manage
prjdesc: Backup / Recovery Scripts for PostgreSQL Database
prjpypi: false

hnav:
    - About
    - Download
    - Prerrequisites
    - Installation
    - Configuration
    - Usage
    - License
    - TODO
	
---


About
-----

Scripts for automating automating backup and recovery tasks for 
_PostgreSQL Database Server_. The following operations have been implemented:

* Sending archive logs to backup server.
* Retrieval of archive logs from backup server.
* Initialization of the database.
* Generation of hot backups with archive logging.
* Recovery from hot backup.
* Dump (export) and restore (import) of databases.
* Initial synchronization of database servers for setting up replication.
* checking the replication between the primary and secondary 
  _PostgreSQL Servers_ in a _Streaming Replication_ setup.
  
Sample configuration files have been provided for configuring the 
_PostgreSQL Database Server_ for archive logging, recovery using archive logs
and _Streaming Replication_.

The scripts were tested using _PostgreSQL 9.0_ on _CentOS 5_ and the scripts
and the sample configuration files will probably require some adjustment for
other _Operating Systems_ or _Linux Distributions_ and _PostgreSQL_ versions.

{% include prj_link_home.inc %}


Download
--------

{% include download.inc %}


Prerrequisites
--------------


### Servers ###

This document asumes two _PostgreSQL Database_ servers; the _primary_ server and
the _secondary_ (_standby_) server:

<table class="fitwidth">
<tr>
	<th>Role</th>
	<th>Hostname</th>
	<th>IP</th>
</tr>
<tr>
	<td>Primary</td>
	<td>node1</td>
	<td>10.0.0.1</td>
</tr>
<tr>
	<td>Secondary</td>
	<td>node2</td>
	<td>10.0.0.2</td>
</tr>
</table>


### User ###

The scripts must be executed by the user that is the owner of the _PostgreSQL_
installation, which is _postgres_ by default.


### Passwordless Login Between Servers ###

_SSH Public Key Authentication_ must be configured for passwordless logins
between the user accounts for _postgres_ in the two _PostgreSQL Servers_.

In case the _SSH_ protocol will be used to transfer backups to and from the 
_Backup Server_, passwordles login from _postgres_ user account in the two
_PostgreSQL Servers_ to the _Backup Server_.


### Directory Hierarchy on the Backup Server ###

The backups of the _database_ and the _archive logs_ are stored on the 
_Backup Server_. A separate directory is required for storing:

* Archive Logs (Default: pg_archlog)
* Hot Backups (Default: pg_hotbackup)
* Exports / Dumps (Default: pg_export)

Each of these directories must have a subdirectory for each _PostgreSQL Server_
and the name of the subdirectories must match the _hostnames_ of the servers:

    +---backup---+---pg_archlog-----+---node1
                 |                  |
                 |                  +---node2
                 |
                 +---pg_hotbackup---+---node1
                 |                  |
                 |                  +---node2
                 |
                 +---pg_export------+---node1
                                    |
                                    +---node2


### Database Permissions ###

The _postgres_ database user in each _PostgreSQL Server_ must be configured with 
a password and must have _replication_ privileges on the other server. Example
entries for _pg\_hba.conf_ configuration file:

	# Streaming Replication
	host    replication     postgres        10.0.0.1/32             md5
	host    replication     postgres        10.0.0.2/32             md5


You can check the sample _pg\_hba.conf_ file in the _conf_ folder for a sample
configuration file.


Installation
------------

The scripts _pg\_manage.pl_ and _pg\_check\_replication.sh_ must be copied to 
_/usr/local/sbin_ or _/usr/local/bin_ and must have permissions for execution.


Configuration
-------------

### Configuration File ###

The configuration for the backup / recovery scripts are defined in the file
_pg\_manage.conf_. This configuration file must be placed in the base directory
for _PostgreSQL_ database, which is _/var/lib/pgsql/9.0_ for _PostgreSQL 9.0_ on
_CentOS 5_.


### Configuration File Options ###

<table>
<tr>
	<th>Option</th>
	<th>Description</th>
</tr>
<tr>
	<td>SERVERTYPE</td>
	<td>
		Server type: <i>PRIMARY</i> for primary server, <i>SECONDARY</i> for 
		secondary (standby) server.
	</td>
</tr>
<tr>
	<td>PRIMARYHOST</td>
	<td>IP Address of primary server.</td>
</tr>
<tr>
	<td>SECONDARYHOST</td>
	<td>IP Address of secondary server.</td>
</tr>
<tr>
	<td>BACKUPURLHOT</td>
	<td>URL designating location for Hot Backups on Backup Server.</td>
</tr>
<tr>
	<td>BACKUPURLARCH</td>
	<td>URL designating location for Archive Logs on Backup Server.</td>
</tr>
<tr>
	<td>BACKUPURLDUMP</td>
	<td>URL designating location for Database Dumps on Backup Server.</td>
</tr>
<tr>
	<td>BACKUPDIRHOT</td>
	<td>Subdirectory at backup location for Hot Backups.</td>
</tr>
<tr>
	<td>BACKUPDIRARCH</td>
	<td>Subdirectory at backup location for Archive Logs.</td>
</tr>
<tr>
	<td>BACKUPDIRDUMP</td>
	<td>Subdirectory at backup location for Database Dumps.</td>
</tr>
</table>


### URL Format ###

<table>
<tr>
	<th>Type</th>
	<th>Example</th>
	<th>Description</th>
</tr>
<tr>
	<td>
		nfs<br>
		cifs
	</td>
	<td>
		nfs:///home/nas<br>
		cifs:///home/nas
	</td>
	<td>Mount point for remote filesystem.</td>
</tr>
<tr>
	<td>file</td>
	<td>file:///home/nas</td>
	<td>Mount point for local filesystem.</td>
</tr>
<tr>
	<td>ssh</td>
	<td>ssh://user@10.0.0.100/backup</td>
	<td>
		Specifies the IP of a remote SSH server, the user to be used for
		passwordless SSH logins to this server and the directory on server.
	</td>
</tr>
</table>


### Sample Configuration Files ###

You can check the sample _pg\_manage.conf.primary_ file in the _conf_ folder for 
a  sample configuration file for the _primary_ server:

	SERVERTYPE=PRIMARY              # Server Type (PRIMARY or SECONDARY)
	PRIMARYHOST=10.0.0.1            # Primary Server IP in Warm Standby Setup.
	SECONDARYHOST=10.0.0.2          # Secondary Server IP in Warm Standby Setup.
	
	BACKUPURLHOT=cifs:///home/nas   # Destination for Hot Backups
	BACKUPURLARCH=cifs:///home/nas  # Destination for Archive Logs
	BACKUPURLDUMP=cifs:///home/nas  # Destination for Dumps
	BACKUPDIRHOT=pg_hotbackup
	BACKUPDIRARCH=pg_archlog
	BACKUPDIRDUMP=pg_export


You can check the sample _pg\_manage.conf.secondary_ file in the _conf_ folder 
for a  sample configuration file for the _secondary_ server:

	SERVERTYPE=SECONDARY            # Server Type (PRIMARY or SECONDARY)
	PRIMARYHOST=10.0.0.1            # Primary Server IP in Warm Standby Setup.
	SECONDARYHOST=10.0.0.2          # Secondary Server IP in Warm Standby Setup.
	
	BACKUPURLHOT=cifs:///home/nas   # Destination for Hot Backups
	BACKUPURLARCH=cifs:///home/nas  # Destination for Archive Logs
	BACKUPURLDUMP=cifs:///home/nas  # Destination for Dumps
	BACKUPDIRHOT=pg_hotbackup
	BACKUPDIRARCH=pg_archlog
	BACKUPDIRDUMP=pg_export


Usage
-----


### Summary of Options ###

#### pg_manage.pl ####

	$ pg_manage.pl -h
	Help on Usage
	usage: pg_manage.pl -h
	
	Send Archive Log to Backup Server / Retrieve Archive Log from Backup Server
	usage: pg_manage.pl [-n] [-d] [-q] -c xlog_archive [-l] -f FILE -p PATH
	usage: pg_manage.pl [-n] [-d] [-q] -c xlog_restore [-l] [-t N] [-i SECS] 
	       [-I SECS] [-w SECS] -f FILE -p PATH [-r FILE]
	
	Create / Remove Trigger File
	usage: pg_manage.pl [-n] [-d] [-q] -c recovery_trigger_fast
	usage: pg_manage.pl [-n] [-d] [-q] -c recovery_trigger_smart
	usage: pg_manage.pl [-n] [-d] [-q] -c recovery_trigger_cleanup
	
	Initialize Database
	usage: pg_manage.pl [-n] [-d] [-q] -c db_destroy
	
	Hot Backup / Restore Database
	usage: pg_manage.pl [-n] [-d] [-q] -c db_hot_backup
	usage: pg_manage.pl [-n] [-d] [-q] -c db_restore_backup -s HOST -b BACKUPFILE
	
	Dump (Export) / Restore (Import) Database
	usage: pg_manage.pl [-n] [-d] [-q] -c db_export -D DATABASE
	usage: pg_manage.pl [-n] [-d] [-q] -c db_import [-j N] -s HOST -b BACKUPFILE
	
	Initial Sync of Servers: Primary -> Secondary
	Run command only on secondary server.
	usage: pg_manage.pl [-n] [-d] [-q] -c db_initial_sync
	
	Check Primary. Return 0 if server is primary
	usage: pg_manage.pl [-n] [-d] [-q] -c check_primary
	
	Check Secondary. Return 0 if server is secondary
	usage: pg_manage.pl [-n] [-d] [-q] -c check_secondary


#### pg_check_replication.sh ####

	$ pg_check_replication.sh 
	PRIMARY: node1
	 pg_current_xlog_location 
	--------------------------
	 73A/27403A08
	(1 row)
	
	
	SECONDARY: node2
	 pg_last_xlog_receive_location | pg_last_xlog_replay_location 
	-------------------------------+------------------------------
	 73A/27403A08                  | 73A/27403A08
	(1 row)



### pg_manage.pl - Common Options ###

	-h                 Print help text.
	-d                 Debug mode.
	-q                 Quiet mode. 
	-n                 Dry-run mode. Simulate operations instead of executing them.
	                   Used for testing operations before executing them.
	-c OPER            Operation to be executed. Must be one of the following:
	                     xlog_archive       Copy Transaction Log File to Backup 
	                                        Server. Used in archive_command 
	                                        option in the  configuration file 
	                                        postgresql.conf for enabling Archive 
	                                        Logging in PostgreSQL Database.
	                     xlog_restore       Restore a Transaction Log File from 
	                                        Backup Server. Used in restore_command 
	                                        option in the configuration file 
	                                        recovery.conf for enabling recovery 
	                                        using Archive Logs in PostgreSQL 
	                                        Database. Used for Point-in-Time 
	                                        Recovery.
	                     db_destroy         Delete data directories to prepare 
	                                        the PostgreSQL Database Server for 
	                                        recovery. 
	                     db_hot_backup      Hot Backup of the PostgreSQL Database 
	                                        Server to the Backup Server. 
	                     db_restore_backup  Restore PostgreSQL Database Server 
	                                        from Hot Backup stored in Backup Server. 
	                     db_export          Generates a compressed dump (export) 
	                                        of a database at the Backup Server. 
	                     db_import          Restores a database from a compressed 
	                                        dump (export) of a database stored at 
	                                        the Backup Server. 
	                     db_initial_sync    Initial sync of data from primary 
	                                        server on secondary server. (Must be 
	                                        executed only on secondary server.)
	                     check_primary      Check if the server is configured as 
	                                        primary server.
	                     check_secondary    Check if the server is configured as 
	                                        secondary server. 
	                     recovery_trigger_fast     Generate Trigger File for 
	                                               finalizing the recovery process 
	                                               as soon as possible.
	                     recovery_trigger_smart    Generate Trigger File for 
	                                               finalizing the recovery process 
	                                               after consuming all available 
	                                               Archive Log files. 
	                     recovery_trigger_cleanup  Remove any existing Trigger 
	                                               Files.



### pg_manage.pl - Backup of Transaction Log Files - xlog_archive ###

Compresses _Transaction Log_ files and copies it to the _Backup Server_.

	Usage: pg_manage.pl [-n] [-d] [-q] -c xlog_archive [-l] -f FILE -p PATH 
	
	  -l       Generate log file with filename archive-DD.log in the log file 
	           directory of PostgreSQL Server. (The log file directory for 
	           PostgreSQL version 9.0 on RHEL / CentOS is by default 
	           /var/lib/pgsql/9.0/data/pg_log.) 
	  -f FILE  Filename for Transaction Log File. 
	  -p PATH  Path for Transaction Log Files directory. The path for 
	           PostgreSQL 9.0 on RHEL / CentOS is by default 
	           /var/lib/pgsql/9.0/data/pg_xlog.


The command is specifically designed to be used in _archive\_command_ option of 
the configuration file _postgresql.conf_ for enabling _Archive Logging_ in 
_PostgreSQL Database Server_.

Sample fragment from _postgresql.conf_:

	archive_mode = on 
	archive_command = '/usr/local/bin/pg_manage.pl -c xlog_archive -l -p "%p" 
	archive_timeout = 900 



### pg_manage.pl - Retrieval of Transaction Log Files - xlog_restore ###

Retrieves compressed _Transaction Log_ files from _Backup Server_ and uncompresses
the files.

	Usage: pg_manage.pl [-n] [-d] [-q] -c xlog_restore [-l] [-t N] [-i SECS] 
	       [-I SECS]  [-w SECS] -f FILE -p PATH [-r FILE]
	
      -l       Generate log file with filename restore-DD.log in the log file 
	           directory of PostgreSQL Server. (The log file directory for 
	           PostgreSQL version 9.0 on RHEL / CentOS is by default 
	           /var/lib/pgsql/9.0/data/pg_log.) 
	  -f FILE  Filename for Transaction Log File. 
	  -p PATH  Path for Transaction Log Files directory. The path for 
	           PostgreSQL 9.0 on RHEL / CentOS is by default 
	           /var/lib/pgsql/9.0/data/pg_xlog.
      -r FILE  Filename for the last Transaction Log file to preserve for
               consistency of PostgreSQL Database.
	  -t N     Number of times to retry retrieval of a Transaction Log File from
	           Backup Server. (Default: 3)
	  -i SECS  Time (seconds) to wait in seconds between retries for retrieval of 
	           a Transaction Log File from Backup Server.  (Default: 10 seconds)
	  -I SECS  Time (seconds) to wait between revisions of the Backup Server for
	           new Archive Log Files. (Default: 60 seconds)
	  -w SECS  Total time (seconds) to wait for the availability of a new 
	           Archive Log File on the Backup Server. (Default: 0 seconds)
	           End of recovery process will be triggered once the total time
	           for waiting for new Archive Log files runs out. 
	           The value 0 implies waiting indefinitely and may be used in
	           replication setups with Log Shipping.


The command is specifically designed to be used in _restore\_command_ option of 
the configuration file _recovery.conf_ for executing recovery using 
_Archive Logs_.

Sample _recovery.conf_ file for recovering the database until the last transaction
registered in the last available _Archive Log_ file:

    restore_command = '/usr/local/bin/pg_manage.pl -l -c xlog_restore -s node1 -I 15 -w 60 -f %f -p %p -r %r'


Sample _recovery.conf_ file for _Point-in-Time_ Recovery (recovering the database 
until a certain date and time):

    restore_command = '/usr/local/bin/pg_manage.pl -l -c xlog_restore -s node1 -I 15 -w 60 -f %f -p %p -r %r'
    recovery_target_time = '2011-02-02 23:59:50 COT'


Sample _recovery.conf_ file for _Replication_ with _Log Shipping_:

    restore_command = '/usr/local/bin/pg_manage.pl -l -c xlog_restore -s node1 -I 15 -w 0 -f %f -p %p -r %r'


Sample _recovery.conf_ file for _Streaming Replication_:

    restore_command = '/usr/local/bin/pg_manage.pl -l -c xlog_restore -s node1 -I 15 -w 60 -f %f -p %p -r %r' 
    standby_mode = 'on' 
    primary_conninfo = 'host=10.0.0.1 port=5432 user=postgres password=xxxxxxxx' 
    trigger_file = '/var/lib/pgsql/9.0/data/recovery.trigger' 



### pg_manage.pl - End Recovery Process - recovery_trigger_(fast|smart) ###

Generate _Trigger File_ for finalizing the recovery process as soon as possible:

	Usage: pg_manage.pl [-n] [-d] [-q] -c recovery_trigger_fast


Generate _Trigger File_ for finalizing the recovery process after consuming all 
available Archive Log files: 

	Usage: pg_manage.pl [-n] [-d] [-q] -c recovery_trigger_smart


Remove any existing _Trigger Files_:

	Usage: pg_manage.pl [-n] [-d] [-q] -c recovery_trigger_cleanup



### pg_manage.pl - Initialize Database - db_destroy ###

Delete data directories to prepare the PostgreSQL Database Server for recovery.

	Usage: pg_manage.pl [-n] [-d] [-q] -c db_destroy

<p class="box warning">
The command deletes data directories of _PostgreSQL Server_. In case there are 
no other copies, this might result in a total loss of data.  
</p>



### pg_manage.pl - Hot Backup - db_hotbackup ###

Executes a _Hot Backup_ of the _PostgreSQL Database_ if the database is _online_,
executes a _Cold Backup_ if the database is _offline_. The backup is stored in
the _Backup Server_ in _tgz_ format and contains a compressed copy of the data
files of the database.

	Usage: pg_manage.pl [-n] [-d] [-q] -c db_hotbackup

<p class="box warning" markdown="1">
Successful recovery from a _Hot Backup_ depends on the availability of
_Archive Logs_. The _Hot Backup_ will not be of any use unless the backups of
_Archive Logs_ or also stored in the _Backup Server_.
</p>

<p class="box warning" markdown="1">
If more than one _Hot Backup_ is generated in the same day, the last backup will
overwrite the previous one. In case the previous backups from the same day must
be preserved, the administrator must move or rename existing backup files before
executing the _Hot Backup_ again.
</p>



### pg_manage.pl - Recovery from Hot/Cold Backup - db_restore_backup ###

Executes recovery of _PostgreSQL Database_ from a _Hot_ or _Cold_ backup file 
stored on the _Backup Server_.

    Usage: pg_manage.pl [-n] [-d] [-q] -c db_restore_backup -s HOST -b BACKUPFILE
    
      -s HOST        Hostname for PostgreSQL Server of origin, where the 
                     Hot/Cold Backup was generated originally.
      -b BACKUPFILE  Filename for Hot/Cold Backup file on Backup Server. 


Command that can be executed to recover from a _Hot_ / _Cold_ backup
of the _PostgreSQL Server_ _node1_:

	$ pg_manage.pl -c db_restore_backup -s node1 -b hotbackup-node1-2010-10-08.tgz 


<p class="box warning" markdown="1">
The recovery process begins with the initialization of the local 
_PostgreSQL Database_, at which point all existing data in the local database
will be lost. Once the recovery process ends the local database would be 
overwritten with data from the backup.
</p>

<p class="box warning" markdown="1">
Successful recovery from a _Hot Backup_ depends on the availability of
_Archive Logs_. The _Hot Backup_ will not be of any use unless the backups of
_Archive Logs_ are available on the _Backup Server_.
</p>


### pg_manage.pl - Export (Dump) of a Database - db_export ###

Generates a _Compressed Database Dump_ ( _Export_ ) of a database at the Backup 
Server.

    Usage: pg_manage.pl [-n] [-d] [-q] -c db_export -D DATABASE
    
      -D DATABASE  Name of the database that will be exported.

 
Command that can be executed to perform a _dump_ (_export_) of the database 
_dbapp_:

    $ pg_manage.pl -c db_export -D dbapp


<p class="box warning" markdown="1">
If more than one _Dump_ ( _Export_ )is generated in the same day, the last backup 
will overwrite the previous one. In case the previous backups from the same day 
must be preserved, the administrator must move or rename existing backup files 
before executing the dump again.
</p>



### pg_manage.pl - Restore a Database from a Database Dump - db_import ###

Restores a database from a _Compressed Database Dump_ (_export_) of a database 
stored at the _Backup Server_. 

    Usage: pg_manage.pl [-n] [-d] [-q] -c db_import  [-j N] -s HOST -b BACKUPFILE
    
      -s HOST       Hostname for PostgreSQL Server of origin, where the 
                    Database Dump (Export) was generated originally.
      -b BACKUPFILE Filename for the Database Dump (Export) file on Backup 
                    Server. 
      -j N          Number of concurrent restore jobs to run to speed up recovery.
                    (Default: 1) The recommended value for minimizing the time
                    required for the recovery process is to set this parameter
                    to the number of processor cores in server.

Command that can be executed to restore a database from a _dump_ (_export_) of 
the database dbapp that was generated from _node1_:

    $ pg_manage.pl -c db_import -j 8 -s node1 -b node1-dbapp-bin-2011-02-07.dump


<p class="box warning" markdown="1">
The recovery process begins with the creation of the database. The recovery
process will fail, if there is a database with the same name, unless the
existing database is dropped or renamed before executing the import..
</p>



### pg_manage.pl - Initial Sync of Databases for Replication - db_initial_sync ###

The command must only be executed on the _Secondary Server_ for performing an
initial copy of data from the _Primary Server_.

    Usage: pg_manage.pl [-n] [-d] [-q] -c db_initial_sync 


<p class="box warning" markdown="1">
The initial replication process must be executed only on the secondary server.
The _pg_manage.conf_ configuration file in both the primary and secondary 
_PostgreSQL_ servers must checked to confirm that the roles of both servers are
configured correctly, before executing the initial replication process.
</p>

<p class="box warning" markdown="1">
The replication process begins with the initialization of the local 
_PostgreSQL Database_, at which point all existing data in the local database
will be lost. Once the replication process ends the local database would be 
overwritten with data from the _primary servcer_.
</p>

<p class="box warning" markdown="1">
The success of the replication process depends on the availability of 
_Archive Logs_. The replication process may fail unless the backups of
_Archive Logs_ or also stored in the _Backup Server_.
</p>



### pg_manage.pl - Verify Server Role - check_primary / check_secondary ###

The _check_primary_ command returns _0_ ( _true_ ) if the server is configured
as _Primary Server, _1_ ( _false_ ) otherwise.

	Usage: pg_manage.pl [-n] [-d] [-q] -c check_primary


The _check_secondary_ command returns _0_ ( _true_ ) if the server is configured
as _Secondary Server, _1_ ( _false_ ) otherwise.

	Usage: pg_manage.pl [-n] [-d] [-q] -c check_primary



License
-------

{% include license_gpl.inc %}


TODO
----

* Migrate the scripts to  _Python_.
* Implement the _pg_basebackup_ command to take advantage of the _Base Backup_ 
  funcionality in _PostgreSQL 9.1_.
* Adapt the scripts to other _Linux_ distributions and other versions of
  _PostgreSQL_ database.
* Avoid overriding of existing backup files.
* Improve the documentation of the scripts. 
