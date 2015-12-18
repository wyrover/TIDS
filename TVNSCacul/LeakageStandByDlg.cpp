#include "stdafx.h"
#include "LeakageStandByDlg.h"

#include "../MineGE/HelperClass.h"
// LeakageStandByDlg 对话框

IMPLEMENT_DYNAMIC(LeakageStandByDlg, CDialog)

LeakageStandByDlg::LeakageStandByDlg(CWnd* pParent /*=NULL*/,AcDbObjectId objId,CString chimType)
	: CDialog(LeakageStandByDlg::IDD, pParent)
	, m_isFactor(false)
	, m_isHM(false)
{
	m_objId = objId;
	m_chimType = chimType;
}

LeakageStandByDlg::~LeakageStandByDlg()
{
}

void LeakageStandByDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_HM_LEAKAGE_EDIT, m_HMEdit);
	DDX_Control(pDX, IDC_LEAKAGE_FACTOR_EDIT, m_factorEdit);
	//m_HMEdit.SetWindowText(_T("不使用该方法计算"));
	//m_factorEdit.SetWindowText(_T("不使用该方法计算"));

	m_HMEdit.SetReadOnly(TRUE);
	m_factorEdit.SetReadOnly(TRUE);

}


BEGIN_MESSAGE_MAP(LeakageStandByDlg, CDialog)
	ON_BN_CLICKED(IDC_HM_LEAKAGE_RADIO, &LeakageStandByDlg::OnBnClickedHmLeakageRadio)
	ON_BN_CLICKED(IDC_LEAKAGE_FACTOR_RADIO, &LeakageStandByDlg::OnBnClickedLeakageFactorRadio)
	ON_BN_CLICKED(IDOK, &LeakageStandByDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// LeakageStandByDlg 消息处理程序

void LeakageStandByDlg::OnBnClickedHmLeakageRadio()
{
	m_isHM = true;
	m_isFactor = false;
	if(_T("金属风筒") == m_chimType )
	{
		m_HMEdit.SetReadOnly(TRUE);
		m_factorEdit.SetReadOnly(TRUE);
		m_HMEdit.SetWindowText(_T("0.000001"));
	}
	else
	{
		m_HMEdit.SetReadOnly(FALSE);
		m_factorEdit.SetReadOnly(TRUE);
		m_HMEdit.SetWindowText(_T("53.31"));

	}
	m_factorEdit.SetWindowText(_T("不使用该方法计算"));
}

void LeakageStandByDlg::OnBnClickedLeakageFactorRadio()
{
	m_isHM = false;
	m_isFactor = true;
	m_HMEdit.SetReadOnly(TRUE);
	m_factorEdit.SetReadOnly(FALSE);
	m_factorEdit.SetWindowText(_T("0.002"));
	m_HMEdit.SetWindowText(_T("不使用该方法计算"));
}

void LeakageStandByDlg::readPropertyData()
{
	CString hm,factor;
	DataHelper::GetPropertyData( m_objId, _T( "百米漏风率" ), hm );
	DataHelper::GetPropertyData( m_objId, _T( "漏风系数" ), factor );
	
	m_HMEdit.SetWindowText(hm);
	m_factorEdit.SetWindowText(factor);

	UpdateData(FALSE);
}

void LeakageStandByDlg::writePropertyData()
{
	UpdateData(TRUE);

	CString hm,factor;
	m_HMEdit.GetWindowText(hm);
	m_factorEdit.GetWindowText(factor);

	DataHelper::SetPropertyData( m_objId, _T( "百米漏风率" ), hm );
	DataHelper::SetPropertyData( m_objId, _T( "漏风系数" ), factor );

}
BOOL LeakageStandByDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	readPropertyData();

	return TRUE;
}

void LeakageStandByDlg::OnBnClickedOk()
{
	writePropertyData();
	OnOK();
}
