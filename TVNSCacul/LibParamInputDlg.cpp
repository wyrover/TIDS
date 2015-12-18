// LibParamInputDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LibParamInputDlg.h"

#include "../MineGE/HelperClass.h"

// LibParamInputDlg 对话框

IMPLEMENT_DYNAMIC(LibParamInputDlg, PropertyData_DockBarChildDlg)

LibParamInputDlg::LibParamInputDlg(CWnd* pParent /*=NULL*/)
	: PropertyData_DockBarChildDlg(LibParamInputDlg::IDD, pParent)
	, m_rand(_T(""))
	, m_leakage(_T(""))
{

}

LibParamInputDlg::~LibParamInputDlg()
{
}

void LibParamInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_LIB_RANK_EDIT, m_rand);
	DDX_Text(pDX, IDC_LIB_LEAKAGE_EDIT, m_leakage);
}


BEGIN_MESSAGE_MAP(LibParamInputDlg, PropertyData_DockBarChildDlg)
END_MESSAGE_MAP()

void LibParamInputDlg::readPropertyData()
{
	DataHelper::GetPropertyData( m_objId, _T( "风库级别" ), m_rand );
	DataHelper::GetPropertyData( m_objId, _T( "漏风备用系数" ), m_leakage );

	initDatas();
	UpdateData(FALSE);
}

void LibParamInputDlg::writePropertyData()
{
	UpdateData(TRUE);

	DataHelper::SetPropertyData( m_objId, _T( "风库级别" ), m_rand );
	DataHelper::SetPropertyData( m_objId, _T( "漏风备用系数" ), m_leakage );
}

void LibParamInputDlg::initDatas()
{
	if (m_rand.IsEmpty())
	{
		m_rand = _T("1");
	}

	if (m_leakage.IsEmpty())
	{
		m_leakage = _T("1.2");
	}
}

BOOL LibParamInputDlg::OnInitDialog()
{
	PropertyData_DockBarChildDlg::OnInitDialog();
	return TRUE;
}
// LibParamInputDlg 消息处理程序
