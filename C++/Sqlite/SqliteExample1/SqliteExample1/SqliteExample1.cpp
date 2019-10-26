#include "pch.h"
#include <iostream>
#include "sqlite3.h"
#include <sstream>

static const char *_dbName = "Test.db";

static int callback(void* data, int argc, char** argv, char** azColName)
{
	int i;

	std::ostringstream *ptr_ss_result = (std::ostringstream *) data;

	for (i = 0; i < argc; i++) {
		*ptr_ss_result << azColName[i] << " , " << (argv[i] ? argv[i] : "NULL") << std::endl;
	}

	*ptr_ss_result << std::endl;
	return 0;
}

int main()
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	std::string str_sql = "";
	char* messaggeError = NULL;
	std::ostringstream ss_result;

	rc = sqlite3_open(_dbName, &db);
	if (rc) 
	{
		std::cerr << "Can't open database: " << sqlite3_errmsg(db) <<std::endl;
		return(0);
	}
	else {
		std::cout << "Opened database successfully" << std::endl;
	}

	str_sql = "CREATE TABLE TEST("
		"ID INT PRIMARY KEY     NOT NULL, "
		"DAY           TEXT    NOT NULL, "
		"COLOUR          TEXT     NOT NULL);";
	rc = sqlite3_exec(db, str_sql.c_str(), NULL, 0, &messaggeError);

	if (rc != SQLITE_OK) 
	{
		std::cerr << "Error Create Table" << std::endl;
		sqlite3_free(messaggeError);
		messaggeError = NULL;
	}
	else
	{
		std::cout << "Table created Successfully" << std::endl;
	}

	str_sql = "INSERT INTO TEST VALUES(1, 'MONDAY', 'RED'); "
		"INSERT INTO TEST VALUES(2, 'SATURDAY', 'BLUE'); "
		"INSERT INTO TEST VALUES(3, 'SUNDAY', 'GREEN'); ";
	rc = sqlite3_exec(db, str_sql.c_str(), NULL, 0, &messaggeError);

	if (rc != SQLITE_OK)
	{
		std::cerr << "Error Insert" << std::endl;
		sqlite3_free(messaggeError);
		messaggeError = NULL;
	}
	else
	{
		std::cout << "Records Created Successfully:" << std::endl;
	}

	str_sql = "select * from TEST";
	rc = sqlite3_exec(db, str_sql.c_str(), callback, (void *) &ss_result, &messaggeError);
	if (rc != SQLITE_OK)
	{
		std::cerr << "Error SELECT" << std::endl;
		sqlite3_free(messaggeError);
		messaggeError = NULL;
	}	
	else 
	{
		std::cout << std::endl;
		std::cout << ss_result.str();
	}
	ss_result.str("");

	str_sql = "DELETE FROM TEST WHERE ID = 2;";
	rc = sqlite3_exec(db, str_sql.c_str(), NULL, 0, &messaggeError);
	if (rc != SQLITE_OK)
	{
		std::cerr << "Error Delete" << std::endl;
		sqlite3_free(messaggeError);
		messaggeError = NULL;
	}
	else
	{
		std::cout << "Records(ID =2) Deleted Successfully:" << std::endl;
	}

	str_sql = "select * from TEST";
	rc = sqlite3_exec(db, str_sql.c_str(), callback, (void *)&ss_result, &messaggeError);
	if (rc != SQLITE_OK)
	{
		std::cerr << "Error SELECT" << std::endl;
		sqlite3_free(messaggeError);
		messaggeError = NULL;
	}
	else
	{
		std::cout << std::endl << std::endl;
		std::cout << ss_result.str();
	}
	ss_result.str("");

	sqlite3_close(db);

	getchar();
	return 0;
}
