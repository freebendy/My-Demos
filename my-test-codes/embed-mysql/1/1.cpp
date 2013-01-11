// 1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "mysql.h"

MYSQL *mysql ;
MYSQL_RES *results ;
MYSQL_ROW record ;

static char *server_options[] = {"mysql_test","--datadir=./data","--language=./english","--skip-innodb","--innodb_data_home_dir=./data","--set-variable=key_buffer_size=32M"} ;
//static char *server_options[] = {"mysql_test","--defaults-file=./my.ini"} ;
int num_elements = sizeof(server_options)/sizeof(char*) ;
static char *server_groups[] = {"test_libmysqld_SERVER","embedded","server",NULL} ;

int _tmain(int argc, _TCHAR* argv[])
{
	std::cout<<"begin!"<<'\n';

	if(!mysql_server_init(num_elements,server_options,NULL))//初始化内嵌服务器
		std::cout<<"mysql_serve_init success!"<<'\n' ;
	else
	{
		std::cout<<"mysql_serve_init fail!"<<'\n' ;
		return 1 ;
	}

	mysql=mysql_init(NULL); //获取Mysql句柄
	if(mysql)
		std::cout<<"mysql_init success!!"<<'\n' ;


	//配置连接选项
	if(mysql_options(mysql,MYSQL_READ_DEFAULT_GROUP,"embedded"))
		std::cout<<"fail 1!"<<'\n';
	if(mysql_options(mysql,MYSQL_OPT_USE_EMBEDDED_CONNECTION,NULL))
		std::cout<<"fail 2!"<<'\n';;

	if(mysql_real_connect(mysql,NULL,NULL,NULL,"mysql",3306,NULL,0)) //连接数据库
		std::cout<<"mysql_real_connect success!"<<'\n' ;

	
	/*mysql_query(mysql,"SELECT help_category_id,name,parent_category_id FROM help_category");*/
	if(!mysql_query(mysql,"SELECT help_category_id,name FROM help_category"))//查询数据
		std::cout<<"mysql_query success!"<<'\n' ;
	else
	{
		std::cout<<"mysql_query fail!"<<'\n' ;
		return 1 ;
	}

	results=mysql_store_result(mysql); //获取查询结果集
	std::cout<<"mysql_store_result success!"<<'\n' ;

	//输出查询结果
	while((record = mysql_fetch_row(results)))
		std::cout<<record[0]<<"\t"<<record[1]<<'\n' ;

	mysql_free_result(results) ;
	mysql_close(mysql) ;
	mysql_server_end();

	std::cout<<'\n'<<"end!"<<'\n' ;
	std::cin.get();
	return 0;
}

