#include "Sqlite.h"
#include <fstream>

int main()
{
	Sqlite sql;
	Sqlite::m_Q = 160;
	Sqlite::m_H = 1800;

	sql.readDatabase();

	ifstream fin("hd.txt");
	while(!fin.eof())
	{
		char name[_MAX_PATH], minQ[_MAX_PATH], maxQ[_MAX_PATH] ,minH[_MAX_PATH] ,maxH[_MAX_PATH];
		fin >> name >> minQ >> maxQ >> minH >> maxH;
		//fin >> m_names[i] >> m_minQs[i] >> m_maxQs[i] >> m_minHs[i] >> m_maxHs[i];
		//m_names.push_back(name);
		if(NULL != name[0])
		{
			//cout << "Name:"<< name << "\tQ:" << minQ << "->" << maxQ << "\tH:"
			//	<< minH << "->" << maxH << endl;
			sql.m_names.push_back(name);
			sql.m_minQs.push_back(minQ);
			sql.m_maxQs.push_back(maxQ);
			sql.m_minHs.push_back(minH);
			sql.m_maxHs.push_back(maxH);
		}

	}

	int len = sql.m_names.size();

	for (int i = 0; i < len; i++)
	{
		//cout << m_names[i];
		cout << "Name:"<<sql.m_names[i] << "\tQ:" << sql.m_minQs[i] << "->" << sql.m_maxQs[i] << "\tH:"
			<< sql.m_minHs[i] << "->" << sql.m_maxHs[i] << endl;
	}

	return 0;
}