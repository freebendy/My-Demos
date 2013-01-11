// embed_mysql.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <mysql.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

MYSQL *db_connect(const char *dbname);
void db_disconnect(MYSQL *db);
void db_do_query(MYSQL *db, const char *query);

static char *server_options[]={"mysql_test","--defaults-file=./my.ini"};
int num_elements=sizeof(server_options)/sizeof(char *);
const char *server_groups[] = {	"test2_libmysqld_SERVER", "embedded", "server", NULL};

int main(int argc, char **argv)
{
	MYSQL *one, *two;

	printf("begin!\n");
	mysql_server_init(num_elements, server_options, (char **)server_groups);

	printf("server init success!\n") ;

	two = db_connect(NULL);

	one = db_connect("mysql");


/*	printf("test!\n") ;*/

	db_do_query(one, "SHOW TABLE STATUS");
	printf("test!\n") ;
	db_do_query(two, "SHOW DATABASES");

	mysql_close(two);
	mysql_close(one);

	/* This must be called after all other mysql functions */
	mysql_server_end();

	exit(EXIT_SUCCESS);
}

static void die(MYSQL *db, char *fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	vfprintf(stderr, fmt, ap);
	va_end(ap);
	(void)putc('\n', stderr);
	if (db)
		db_disconnect(db);
	exit(EXIT_FAILURE);
}

MYSQL* db_connect(const char *dbname)
{
	printf("begin connect!\n") ;
	MYSQL *db = mysql_init(NULL);
	if (!db)
		die(db, "mysql_init failed: no memory");
	/*
	* Notice that the client and server use separate group names.
	* This is critical, because the server does not accept the
	* client's options, and vice versa.
	*/
	if(!mysql_options(db, MYSQL_READ_DEFAULT_GROUP, "test2_libmysqld_client"))
		printf("option success!\n");
	if (!mysql_real_connect(db, NULL, NULL, NULL, dbname, 0, NULL, 0))
	{
		printf("connect fail!\n");
		die(db, "mysql_real_connect failed: %s", mysql_error(db));
	}
	printf("connect success!\n");
	return db;
}

void db_disconnect(MYSQL *db)
{
	mysql_close(db);
	printf("mysql close!\n") ;
}

void db_do_query(MYSQL *db, const char *query)
{
	if (mysql_query(db, query) != 0)
		goto err;

	if (mysql_field_count(db) > 0)
	{
		MYSQL_RES *res;
		MYSQL_ROW row, end_row;
		int num_fields;

		if (!(res = mysql_store_result(db)))
			goto err;
		num_fields = mysql_num_fields(res);
		while ((row = mysql_fetch_row(res)))
		{
			(void)fputs(">> ", stdout);
			for (end_row = row + num_fields; row < end_row; ++row)
				(void)printf("%s\t", row ? (char*)*row : "NULL");
			(void)fputc('\n', stdout);
		}
		(void)fputc('\n', stdout);
		mysql_free_result(res);
	}
	else
		(void)printf("Affected rows: %lld\n", mysql_affected_rows(db));

	return;

err:
	die(db, "db_do_query failed: %s [%s]", mysql_error(db), query);
} 