#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <iostream>
#include "gms/class_info/class_info.h"
#include "gms/gb_convert/uni_table.h"
#include "gms/include/class_mysql.h"
#include "gms/global_sql/global_sql.h"
#include "gms/log_writer/log_writer.h"

#include "commu/sock/sock.h"
#include "commu/bufio/bufio.h"
#include "commu/cmd_buf/cmd_buf_pk.h"
#include "commu/tm/tm.h"

using namespace std;
int main(int argc, char *argv[])
{
	//cout << "hello666" << endl;

	c_log_writer *p_writer = c_log_writer::instance("err.txt");
	c_class_info *CI = c_class_info::instance("conf_gms.ini");	
	c_uni_table *p_gb = c_uni_table::instance(GP_CI->get_val("dirroot"));
	c_global_sql *pg_sql = c_global_sql::instance();

	c_tm *p_tm = c_tm::instance();
	c_sock *p_sock = c_sock::instance();
	c_bufio *p_bufio = c_bufio::instance();
	c_cmd_buf *p_cb = c_cmd_buf::instance();
	
	p_sock->init_listener();
	p_tm->run(10);

	p_cb->release();
	p_bufio->release();
	p_sock->release();
	p_tm->release();


	pg_sql->release();
	p_gb->release();
	CI->release();
	p_writer->release();
	return 0;
}


/*
#include "backprocess.h"
#include "class_webserver.h"
//#include <iostream>
using namespace std;
int main(int argc,char* argv)
{
	//将本程序做为后台进程
	if(!makebackprocess())
		exit(1);
	c_webserver obj_webserver;
	//obj_webserver.tests();
	obj_webserver.run_server();	 //开始提供WEB服务
	return 1;
}
*/

