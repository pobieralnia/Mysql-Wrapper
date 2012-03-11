/*
 * Filename dbWrapperClass.h
 * Header for mysql wrapper class
 * 
 * @author	Tomasz L
 * @package dbWrapperClass
 */

#ifndef _DBWRAPPERCLASS_H_
#define _DBWRAPPERCLASS_H_

#include <Windows.h>
#include <mysql.h>
#include <string>
#include <vector>

#define DB_HOST "localhost"
#define DB_USERNAME "root"
#define DB_PASSWORD ""
#define DB_DATABASE "escard"


class DB_wrapper
{
	private:
		void disconnet() const;		// Method to disconnet mysql
		bool free(bool check);		// Free memory for current query with bool return
		
		// Mysql class
		MYSQL *m_conn;
		MYSQL_RES *m_result;
		MYSQL_ROW m_row;
		MYSQL_FIELD *m_field;

		// variables
		int * m_number_fields = new int;
	
	public:
		DB_wrapper(void);
		int init(void);		// init connection
		void free(void) const;		// Free memory for current query
		int num_fields(void);	// Number of fields for the result
		MYSQL_RES * fetch_all(const char *c);		// sql query and fetch all records
		~DB_wrapper(void);
};

#endif