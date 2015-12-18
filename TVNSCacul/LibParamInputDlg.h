#pragma once

#include "PropertyData_DockBarChildDlg.h"
#include "afxwin.h"

class LibParamInputDlg : public PropertyData_DockBarChildDlg
{
	DECLARE_DYNAMIC(LibParamInputDlg)

public:
	LibParamInputDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~LibParamInputDlg();

// 对话框数据
	enum { IDD = IDD_LIB_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CString m_rand;
	CString m_leakage;

protected:
	void readPropertyData();
	void writePropertyData();
	void initDatas();

public:
	virtual BOOL OnInitDialog();

};
