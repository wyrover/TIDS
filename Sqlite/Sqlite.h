#pragma once
#include "dlimexp.h"

class sqlite3;
class SQLITE_EXPORT_API Sqlite
{
public:
	Sqlite();
	~Sqlite();

public:
	void readDatabase( CString way);
	BOOL insertFan(const CString& workMethod,char *Name,int MinQ,int MaxQ,int MinH,int MaxH,char *Power);
	AcStringArray findFan( CString sqlStr );
	BOOL deleFan(const CString& sqlStr );
	BOOL updateFan( const CString& fanMethod,const AcStringArray& oldValues,const AcStringArray& newValues);
private:
	static double charArrayToDouble( char *ch );
	static int LoadMyInfo(void* para,int n_column,char ** column_value,char **column_name);
	char* getDBPath();
	CString getFanMethod( sqlite3* db,const CString& sqlStr);

public:
	static double m_Q;
	static double m_H;

private:
	char *m_errmsg;

};