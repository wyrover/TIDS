// TunnelDockBarChildDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TunnelDockBarChildDlg.h"

#include "../MineGE/HelperClass.h"
#include "../ArxHelper/HelperClass.h"

IMPLEMENT_DYNAMIC(TunnelDockBarChildDlg, PropertyData_DockBarChildDlg)

TunnelDockBarChildDlg::TunnelDockBarChildDlg(CWnd* pParent /*=NULL*/)
	: PropertyData_DockBarChildDlg(TunnelDockBarChildDlg::IDD, pParent)
	, m_name(_T(""))
{

}

TunnelDockBarChildDlg::~TunnelDockBarChildDlg()
{
}

void TunnelDockBarChildDlg::DoDataExchange(CDataExchange* pDX)
{
	PropertyData_DockBarChildDlg::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TUNNEL_NAME_EDIT, m_name);
	DDX_Text(pDX, IDC_TUNNEL_LENTH_EDIT, m_lenth);
	DDX_Text(pDX, IDC_TUNNEL_AREA_EDIT, m_area);
}


BEGIN_MESSAGE_MAP(TunnelDockBarChildDlg, PropertyData_DockBarChildDlg)
END_MESSAGE_MAP()

void TunnelDockBarChildDlg::readPropertyData()
{
	DataHelper::GetPropertyData( m_objId, _T( "名称" ), m_name );
	DataHelper::GetPropertyData( m_objId, _T( "断面面积" ), m_area );
	DataHelper::GetPropertyData( m_objId, _T( "长度" ), m_lenth);

}

void TunnelDockBarChildDlg::writePropertyData()
{
	DataHelper::SetPropertyData( m_objId, _T( "名称" ), m_name );
	DataHelper::SetPropertyData( m_objId, _T( "断面面积" ), m_area );
	DataHelper::SetPropertyData( m_objId, _T( "长度" ), m_lenth );

}
// TunnelDockBarChildDlg 消息处理程序
