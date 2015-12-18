#include "StdAfx.h"
#include "Sqlite.h"
#include "sqlite3.h" 
#include <sstream>
#include <fstream>

using namespace std;

static CString GetAppPathDir()
{
	HANDLE hDllhandle=GetModuleHandle(_T("Sqlite"));//获取当前模块句柄
	WCHAR buff[MAX_PATH];
	memset(buff,0,MAX_PATH);
	GetModuleFileName((HMODULE)hDllhandle,buff,MAX_PATH);

	TCHAR drive[_MAX_DRIVE];
	TCHAR dir[_MAX_DIR];
	_tsplitpath( buff, drive, dir, NULL, NULL );

	TCHAR szPath[_MAX_PATH] = {0};
	_tmakepath( szPath, drive, dir, NULL, NULL );

	return CString( szPath );
}

static CString BuildPath( const CString& dir, const CString& fileName )
{
	CString path;
	path.Format( _T( "%s%s" ), dir, fileName );
	return path;
}



Sqlite::Sqlite():m_errmsg(0)
{
}

Sqlite::~Sqlite()
{

}

double Sqlite::m_Q = 0;
double Sqlite::m_H = 0;



char * Sqlite::getDBPath()
{
	CString dataDirName = _T( "Datas\\" );
	CString fileName;
	fileName =BuildPath ( BuildPath( GetAppPathDir(), dataDirName ),_T( "fan.db" ) );

	//宽字符转换成const char*
	const size_t strsize=(fileName.GetLength()+1)*2; // 宽字符的长度;
	char * pstr= new char[strsize]; //分配空间;
	size_t sz=0;
	wcstombs_s(&sz,pstr,strsize,fileName,_TRUNCATE);
	int n=atoi((const char*)pstr);
	return pstr;
}

void Sqlite::readDatabase( CString way)
{
	CString dataDirName = _T( "Datas\\" );
	CString fileName;
	fileName =BuildPath ( BuildPath( GetAppPathDir(), dataDirName ),_T( "hd.txt" ) );

	::DeleteFile(fileName);

	fileName =BuildPath ( BuildPath( GetAppPathDir(), dataDirName ),_T( "fan.db" ) );

	//宽字符转换成const char*
	const size_t strsize=(fileName.GetLength()+1)*2; // 宽字符的长度;
	char * pstr= new char[strsize]; //分配空间;
	size_t sz=0;
	wcstombs_s(&sz,pstr,strsize,fileName,_TRUNCATE);
	int n=atoi((const char*)pstr);

	sqlite3 *db=NULL;
	int result;

	result = sqlite3_open(pstr,&db);
	if (result!=SQLITE_OK)
	{
		return;
	}

	if(_T("压入式") == way)
	{
		result = sqlite3_exec(db,"select * from PressIn",LoadMyInfo,NULL,&m_errmsg);
	}

	else if (_T("抽出式") == way)
	{
		result = sqlite3_exec(db,"select * from PullOut",LoadMyInfo,NULL,&m_errmsg);
	}
	if (result!=SQLITE_OK)
	{
		return;
	}
	sqlite3_close(db);

}

double Sqlite::charArrayToDouble( char *ch )
{
	double val;
	stringstream ss;
	ss<< ch;
	ss>> val;

	return val;
}

int Sqlite::LoadMyInfo( void* para,int n_column,char ** column_value,char **column_name )
{
	CString dataDirName = _T( "Datas\\" );
	CString fileName;
	fileName =BuildPath ( BuildPath( GetAppPathDir(), dataDirName ),_T( "hd.txt" ) );

	ofstream fout(fileName,ios::app);
	double MinQ,MaxQ,MinH,MaxH;
	MinQ = charArrayToDouble(column_value[1]);
	MaxQ = charArrayToDouble(column_value[2]);
	MinH = charArrayToDouble(column_value[3]);
	MaxH = charArrayToDouble(column_value[4]);
	if ( MinQ <= m_Q && MaxQ >= m_Q && MinH <= m_H && MaxH >= m_H)
	{
		//m_names.push_back(column_value[0]);
		//m_minQs.push_back(MinQ);
		//m_maxQs.push_back(MaxQ);
		//m_minHs.push_back(MinH);
		//m_maxHs.push_back(MaxH);
		if(MaxH - (m_Q - MinQ) * (MaxH - MinH) / (MaxQ - MinQ) > m_H)
		{
			fout << column_value[0] << "\t" <<column_value[1] << "\t "
				<< column_value[2] << "\t " << column_value[3] << "\t "
				<< column_value[4] << "\t" << column_value[5] << endl;
		}

	}

	return 0;
}

BOOL Sqlite::insertFan( const CString& workMethod,char *Name,int MinQ,int MaxQ,int MinH,int MaxH,char *Power )
{
	char *dataPath = getDBPath();
	sqlite3 *db=NULL;
	int result;

	result = sqlite3_open(dataPath,&db);
	if (result!=SQLITE_OK)
	{
		return false;
	}

	sqlite3_stmt* stmt = NULL; 
	char *sql;
	if (_T("压入式") == workMethod)
	{
		sql = "insert into PressIn values(?,?,?,?,?,?)";
	}
	else if (_T("抽出式") == workMethod)
	{
		sql = "insert into PullOut values(?,?,?,?,?,?)";
	}
	else return false;

	if(sqlite3_prepare_v2(db,
		sql,
		512, &stmt, NULL) != SQLITE_OK)
	{
		sqlite3_close(db);
		return false;
	}
	if(sqlite3_bind_text(stmt, 1, Name, -1, NULL) != SQLITE_OK)
	{
		sqlite3_close(db);
		return false;
	}
	if(sqlite3_bind_int(stmt, 2, MinQ) != SQLITE_OK)
	{
		sqlite3_close(db);
		return false;
	}
	if(sqlite3_bind_int(stmt, 3, MaxQ) != SQLITE_OK)
	{
		sqlite3_close(db);
		return false;
	}

	if(sqlite3_bind_int(stmt, 4, MinH) != SQLITE_OK)
	{
		sqlite3_close(db);
		return false;
	}
	if(sqlite3_bind_int(stmt, 5, MaxH) != SQLITE_OK)
	{
		sqlite3_close(db);
		return false;
	}
	if(sqlite3_bind_text(stmt, 6, Power, -1, NULL) != SQLITE_OK)
	{
		sqlite3_close(db);
		return false;
	}


	if(sqlite3_step(stmt) != SQLITE_DONE)
	{
		sqlite3_close(db);
		return false;
	}
	if(sqlite3_finalize(stmt) != SQLITE_OK)
	{
		sqlite3_close(db);
		return false;
	}

	sqlite3_close(db);
	return true;

}

AcStringArray Sqlite::findFan( CString sqlStr )
{
	AcStringArray findRet;
	char *dataPath = getDBPath();
	sqlite3 *db=NULL;
	int result;

	result = sqlite3_open(dataPath,&db);
	if (result!=SQLITE_OK)
	{
		return NULL;
	}

	sqlite3_stmt* stmt = NULL; 
	//CString sqlStr = _T("select * from ") + fanMethod + _T(" where ") + findType +  fieldValue;
	char *sql = new char[sqlStr.GetLength()+1];
	wsprintfA(sql, "%ls", sqlStr);

	if(sqlite3_prepare_v2(db,sql,

		512, &stmt, NULL) != SQLITE_OK)
	{
		sqlite3_close(db);
		return NULL;
	}

	int rc = sqlite3_step(stmt);

	while( rc == SQLITE_ROW ){
		CString nameRet = sqlite3_column_text(stmt,0);
		CString minQRet = sqlite3_column_text(stmt,1);
		CString maxQRet = sqlite3_column_text(stmt,2);
		CString minHRet = sqlite3_column_text(stmt,3);
		CString maxHRet = sqlite3_column_text(stmt,4);
		CString powerRet = sqlite3_column_text(stmt,5);

		findRet.append(nameRet);
		findRet.append(minQRet);
		findRet.append(maxQRet);
		findRet.append(minHRet);
		findRet.append(maxHRet);
		findRet.append(powerRet);

		rc=sqlite3_step(stmt);
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);


	return findRet;
}

BOOL Sqlite::deleFan(const CString& sqlStr )
{
	AcStringArray findRet;
	char *dataPath = getDBPath();
	sqlite3 *db=NULL;
	int result;

	result = sqlite3_open(dataPath,&db);
	if (result!=SQLITE_OK)
	{
		return FALSE;
	}

	CString method = getFanMethod(db,sqlStr);
	//AfxMessageBox(method);
	if(method.IsEmpty()) 
	{
		sqlite3_close(db);
		return FALSE;
	}
	CString sql0 = _T("delete from ") + method + _T(" where ") + sqlStr;

	//AfxMessageBox(sql0);
	sqlite3_stmt* stmt = NULL; 
	//CString sqlStr = _T("select * from ") + fanMethod + _T(" where ") + findType +  fieldValue;
	char *sql = new char[sql0.GetLength()+1];
	wsprintfA(sql, "%ls", sql0);
	if(sqlite3_prepare_v2(db,sql,

		512, &stmt, NULL) != SQLITE_OK)
	{
		sqlite3_close(db);
		return FALSE;
	}

	if(sqlite3_step(stmt) != SQLITE_DONE)
	{
		sqlite3_close(db);
		return FALSE;
	}
	if(sqlite3_finalize(stmt) != SQLITE_OK)
	{
		sqlite3_close(db);
		return FALSE;
	}

	sqlite3_close(db);

	return TRUE;
}

CString Sqlite::getFanMethod(sqlite3* db,const CString& sqlStr )
{
	CString method;
	CString sql1 = _T("select * from PressIn where ") + sqlStr;
	CString sql2 = _T("select * from PullOut where ") + sqlStr;

	sqlite3_stmt* stmt = NULL; 
	char *sql = new char[sql1.GetLength()+1];
	wsprintfA(sql, "%ls", sql1);
	if(sqlite3_prepare_v2(db,sql,

		512, &stmt, NULL) != SQLITE_OK)
	{
		method = _T("");
	}
	if(sqlite3_reset(stmt) != SQLITE_OK) method = _T("");
	if(SQLITE_ROW == sqlite3_step(stmt)) method = _T(" PressIn ");
	if(SQLITE_OK != sqlite3_finalize(stmt)) method = _T("");
	
	if(!method.IsEmpty()) return method;

	sql = new char[sql2.GetLength()+1];
	wsprintfA(sql, "%ls", sql2);
	if(sqlite3_prepare_v2(db,sql,
		512, &stmt, NULL) != SQLITE_OK)
	{
		if(method.IsEmpty())
			return method;
	}

	sqlite3_reset(stmt);
	if(SQLITE_ROW == sqlite3_step(stmt)) method = _T(" PullOut ");
	sqlite3_finalize(stmt);
	return method;
}

BOOL Sqlite::updateFan( const CString& fanMethod,const AcStringArray& oldValues,const AcStringArray& newValues )
{
	AcStringArray findRet;
	char *dataPath = getDBPath();
	sqlite3 *db=NULL;
	int result;

	result = sqlite3_open(dataPath,&db);
	if (result!=SQLITE_OK)
	{
		return FALSE;
	}

	CString sqlStr = _T("UPDATE ") + fanMethod + _T(" SET Name = '");
	sqlStr.Append(newValues[0]);
	sqlStr.Append(_T("' , MinQ = "));
	sqlStr.Append(newValues[1]);
	sqlStr.Append(_T(" , MaxQ = "));
	sqlStr.Append(newValues[2]);
	sqlStr.Append(_T(" , MinH = "));
	sqlStr.Append(newValues[3]);
	sqlStr.Append(_T(" , MaxH = "));
	sqlStr.Append(newValues[4]);
	sqlStr.Append(_T(" , Power = '"));
	sqlStr.Append(newValues[5]);
	sqlStr.Append(_T("' WHERE "));
	sqlStr.Append(_T(" Name is '"));
	sqlStr.Append(oldValues[0]);
	sqlStr.Append(_T("' and MinQ is "));
	sqlStr.Append(oldValues[1]);
	sqlStr.Append(_T(" and MaxQ is "));
	sqlStr.Append(oldValues[2]);
	sqlStr.Append(_T(" and MinH is "));
	sqlStr.Append(oldValues[3]);
	sqlStr.Append(_T(" and MaxH is "));
	sqlStr.Append(oldValues[4]);
	sqlStr.Append(_T(" and Power is '"));
	sqlStr.Append(oldValues[5]);
	sqlStr.Append(_T("'"));

	sqlite3_stmt* stmt = NULL; 
	char *sql = new char[sqlStr.GetLength()+1];
	wsprintfA(sql, "%ls", sqlStr);
	if(sqlite3_prepare_v2(db,sql,
		512, &stmt, NULL) != SQLITE_OK)
	{
		sqlite3_close(db);
		return FALSE;
	}

	if(sqlite3_step(stmt) != SQLITE_DONE)
	{
		sqlite3_close(db);
		return FALSE;
	}
	if(sqlite3_finalize(stmt) != SQLITE_OK)
	{
		sqlite3_close(db);
		return FALSE;
	}

	//sqlite3_close(db);
	result = sqlite3_close(db);
	if (result!=SQLITE_OK)
	{
		return FALSE;
	}
	return TRUE;

}