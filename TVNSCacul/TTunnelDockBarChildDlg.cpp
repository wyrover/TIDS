// TTunnelDockBarChildDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TTunnelDockBarChildDlg.h"

#include "../MineGE/HelperClass.h"
#include "../ArxHelper/HelperClass.h"

IMPLEMENT_DYNAMIC(TTunnelDockBarChildDlg, PropertyData_DockBarChildDlg)

TTunnelDockBarChildDlg::TTunnelDockBarChildDlg(CWnd* pParent /*=NULL*/)
	: PropertyData_DockBarChildDlg(TTunnelDockBarChildDlg::IDD, pParent)
	, m_name(_T(""))
{

}

TTunnelDockBarChildDlg::~TTunnelDockBarChildDlg()
{
}

void TTunnelDockBarChildDlg::DoDataExchange(CDataExchange* pDX)
{
	PropertyData_DockBarChildDlg::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TTUNNEL_NAME_EDIT, m_name);
	DDX_Text(pDX, IDC_TTUNNEL_LENTH_EDIT, m_lenth);
	DDX_Text(pDX, IDC_TTUNNEL_AREA_EDIT, m_area);
}


BEGIN_MESSAGE_MAP(TTunnelDockBarChildDlg, PropertyData_DockBarChildDlg)
END_MESSAGE_MAP()

void TTunnelDockBarChildDlg::readPropertyData()
{
	DataHelper::GetPropertyData( m_objId, _T( "名称" ), m_name );
	DataHelper::GetPropertyData( m_objId, _T( "断面面积" ), m_area );
	DataHelper::GetPropertyData( m_objId, _T( "长度" ), m_lenth );
	UpdateData(FALSE);
}

void TTunnelDockBarChildDlg::writePropertyData()
{
	UpdateData(TRUE);
	DataHelper::SetPropertyData( m_objId, _T( "名称" ), m_name );
	DataHelper::SetPropertyData( m_objId, _T( "断面面积" ), m_area );
	DataHelper::SetPropertyData( m_objId, _T( "长度" ), m_lenth);
}
// TTunnelDockBarChildDlg 消息处理程序
