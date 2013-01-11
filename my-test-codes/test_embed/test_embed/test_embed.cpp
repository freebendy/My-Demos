// test_embed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "mysql.h"
MYSQL *mysql;
MYSQL_RES *results1;
MYSQL_RES *results2;
MYSQL_RES *results3;
MYSQL_ROW record1,record2,record3;
//
//static char *server_options[]={"mysql_test",
//											 "--language=./share/english",
//											 "--datadir=./data/",
//											 "--innodb_data_home_dir=./data/",
//											 "--set-variable=key_buffer_size=32M"};

static char *server_options[]={"mysql_test","--defaults-file=./my.ini"};
int num_elements=sizeof(server_options)/sizeof(char *);
static char *server_groups[]={"test_libmysqld_SERVER","embedded","server",NULL};

int _tmain(int argc, _TCHAR* argv[])
{
	
	std::cout<<"begin!"<<'\n';

	if(!mysql_server_init(num_elements,server_options,server_groups))//��ʼ����Ƕ������
		std::cout<<"mysql_serve_init success!"<<'\n' ;
	else
	{
		std::cout<<"mysql_serve_init fail!"<<'\n' ;
		return 1 ;
	}

	mysql=mysql_init(NULL); //��ȡMysql���

	std::cout<<"mysql_init success!!"<<'\n' ;

	
	//��������ѡ��
	mysql_options(mysql,MYSQL_READ_DEFAULT_GROUP,"embedded");
	mysql_options(mysql,MYSQL_OPT_USE_EMBEDDED_CONNECTION,NULL);

	mysql_real_connect(mysql,NULL,NULL,NULL,"mysql",3306,NULL,0); //�������ݿ�
	std::cout<<"mysql_real_connect success!"<<'\n' ;

	mysql_query(mysql,"SELECT help_category_id,name,parent_category_id FROM help_category"); //��ѯ����
	std::cout<<"mysql_query success!"<<'\n' ;

	results1=mysql_store_result(mysql); //��ȡ��ѯ�����
	std::cout<<"mysql_store_result success!"<<'\n' ;

	//�����ѯ���
	while((record1 = mysql_fetch_row(results1)))
		std::cout<<record1[0]<<"\t"<<record1[1]<<"\t\t"<<record1[2]<<'\n' ;

	std::cout<<'\n'<<'\n' ;

	std::cin.get();


	mysql_real_connect(mysql,NULL,NULL,NULL,"ben",3306,NULL,0); //�������ݿ�
	std::cout<<"mysql_real_connect success!"<<'\n' ;

	mysql_query(mysql,"SELECT * FROM bb"); //��ѯ����
	std::cout<<"mysql_query success!"<<'\n' ;

	results2=mysql_store_result(mysql); //��ȡ��ѯ�����
	std::cout<<"mysql_store_result success!"<<'\n' ;

	//�����ѯ���
	while((record2 = mysql_fetch_row(results2)))
		std::cout<<record2[0]<<"\t"<<record2[1]<<'\n' ;

	//�������ݿ�ͱ��Լ����²���
	//if(!mysql_query(mysql,"CREATE DATABASE test_embedded"))
	//	printf("create test_embedded success!\n");
	mysql_real_connect(mysql,NULL,NULL,NULL,"test_embedded",3306,NULL,CLIENT_MULTI_STATEMENTS) ;
	//if(!mysql_query(mysql,"CREATE TABLE test_table (id INT)"))
	//	printf("create test_table success!\n");
	if (!mysql_query(mysql,"INSERT INTO test_table VALUE(40)"))
		printf("insert success!\n");
	if(!mysql_query(mysql,"UPDATE test_table SET id=20 WHERE id=10"))
		printf("update success!\n");	
    if(!mysql_query(mysql,"SELECT * FROM test_table"))
		printf("Query success!\n");
	results3=mysql_store_result(mysql);
	
	printf ("Number of rows: %lu\n", (unsigned long) mysql_num_rows(results3));
	
	while((record3=mysql_fetch_row(results3)))
		std::cout<<record3[0]<<'\n' ;
	printf("%ld products updated",(long) mysql_affected_rows(mysql));
	mysql_free_result(results3);



	//�ͷ���Դ
	mysql_free_result(results1);
	mysql_free_result(results2);
	mysql_close(mysql);
	mysql_server_end();

	std::cout<<'\n'<<"end!"<<'\n' ;
	std::cin.get();

	return 0;
}
