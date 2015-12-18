#include "stdafx.h"
#include "WindageChooseDlg.h"

IMPLEMENT_DYNAMIC(WindageChooseDlg, CDialog)

WindageChooseDlg::WindageChooseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(WindageChooseDlg::IDD, pParent)
	, m_windageWay(0)
	, m_hmWindage(false)
	, m_formula(false)
{
}

WindageChooseDlg::~WindageChooseDlg()
{
}

void WindageChooseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(WindageChooseDlg, CDialog)
	ON_BN_CLICKED(IDC_HM_WINDAGE_RADIO, &WindageChooseDlg::OnBnClickedHmWindageRadio)
	ON_BN_CLICKED(IDC_FORMULA_RADIO, &WindageChooseDlg::OnBnClickedFormulaRadio)
	ON_BN_CLICKED(IDOK, &WindageChooseDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// WindageChooseDlg 消息处理程序

void WindageChooseDlg::OnBnClickedHmWindageRadio()
{
	m_hmWindage = true;
	m_formula = false;
}

void WindageChooseDlg::OnBnClickedFormulaRadio()
{
	m_hmWindage = false;
	m_formula = true;
}

void WindageChooseDlg::OnBnClickedOk()
{
	if(m_hmWindage) m_windageWay = 1;
	if(m_formula) m_windageWay = 2;
	OnOK();
}

BOOL WindageChooseDlg::OnInitDialog()
{
	CButton* radio=(CButton*)GetDlgItem(IDC_HM_WINDAGE_RADIO);

	radio->SetCheck(1);
	m_windageWay = 1;
	return TRUE;
}