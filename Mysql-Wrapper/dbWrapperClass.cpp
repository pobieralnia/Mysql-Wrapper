/*
 * Filename dbWrapperClass.cpp
 * Methods for mysql wrapper
 * 
 * @author	Tomasz L
 * @package dbWrapperClass
 */

#include "dbWrapperClass.h"


/**
 * Constructor
 * - we set NULL to all main variables for mysql
 * 
 * @return	void
 */
DB_wrapper::DB_wrapper(void)
{
	this->m_conn = NULL;
	this->m_result = NULL;
	this->m_row = NULL;
	this->m_field = NULL;
}

/**
 * Method Disconnet
 * - we try to close mysql connection if there is such as. Next we free mysql result.
 *
 * @return	void
 */
void DB_wrapper::disconnet() const
{
	// Check if connection is open if so than close it
	if(this->m_conn)
	{
		mysql_close(this->m_conn);
	}

	//release result data
	this->free(); 
}

/**
 * Method Free
 * - free mysql resutl if it is needed.
 *
 * @return	void
 */
void DB_wrapper::free(void) const
{
	 // Check if there is a result if so we free it
	 if (this->m_result)
	 {
		mysql_free_result(this->m_result);
	 }
}

/**
 * Method Free
 * - free mysql resutl if it is needed. If connection exists we return bool.
 *
 * @param	bool check - if we want to check or not
 * @return	bool - if connection exists we return True else False
 */
bool DB_wrapper::free(bool check)
{
	 // Check if there is a result if so we free it
	 if (this->m_result)
	 {
		mysql_free_result(this->m_result);
		return true;
	 }

	 return false;
}

MYSQL_RES * DB_wrapper::fetch_all(const char * c)
{
	//query the database
	if(mysql_query(this->m_conn,c))
	{
		fprintf(stderr, "%s\n", mysql_error(m_conn));
		exit(0);
	}

	this->m_result = mysql_store_result(this->m_conn);
	* m_number_fields = mysql_num_fields(this->m_result);

	return this->m_result;
}

/**
 * Method num_fields
 * 
 * @return	int - number of fields for result
 */
int DB_wrapper::num_fields()
{
	if (this->m_result)
	{
		return * m_number_fields;
	}
	else
		return 0;
}

/**
 * Init mysql connection
 * - connect to database using define variables
 *
 * @return bool
 */
int DB_wrapper::init(void)
{
	 if(this->m_conn) //already connected to another database
		this->disconnet(); //disconnect from that one

	 //initilize the socket
	 this->m_conn = mysql_init(0);

	 //something went wrong with the socket
	 if (!this->m_conn)
	 {
	 }

	 //try connecting to the database  
	 if(!mysql_real_connect(this->m_conn, DB_HOST, DB_USERNAME, DB_PASSWORD, DB_DATABASE, 0, NULL, 0))
	 {
		
	 }

	 //successfully connected to the database    
	 return true;  
}

/**
 * Destructor
 * - free the result and close connection if exists
 * 
 * @return	void
 */
DB_wrapper::~DB_wrapper(void)
{
	delete this->m_number_fields;
	this->disconnet();
}

// end of file dbWrapperClass.cpp
