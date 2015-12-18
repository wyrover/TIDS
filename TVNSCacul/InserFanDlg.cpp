#include "stdafx.h"
#include "InserFanDlg.h"
#include "../Sqlite/Sqlite.h"

// InserFanDlg 对话框

IMPLEMENT_DYNAMIC(InserFanDlg, CDialog)

InserFanDlg::InserFanDlg(CWnd* pParent /*=NULL*/)
	: CDialog(InserFanDlg::IDD, pParent)
	, m_fanName(_T(""))
	, m_minQ(_T(""))
	, m_maxQ(_T(""))
	, m_minH(_T(""))
	, m_maxH(_T(""))
	, m_power(_T(""))
{

}

InserFanDlg::~InserFanDlg()
{
}

void InserFanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FANNAME_EDIT, m_fanName);
	DDX_Text(pDX, IDC_NEWMINQ_EDIT, m_minQ);
	DDX_Text(pDX, IDC_NEWMAXQ_EDIT, m_maxQ);
	DDX_Text(pDX, IDC_NEWMINH_EDIT, m_minH);
	DDX_Text(pDX, IDC_NEWMAXH_EDIT, m_maxH);
	DDX_Text(pDX, IDC_NEWPOWER_EDIT, m_power);
	DDX_Control(pDX, IDC_NEWMETHOD_COMBO, m_methodCmBox);
}


BEGIN_MESSAGE_MAP(InserFanDlg, CDialog)
	ON_BN_CLICKED(IDOK, &InserFanDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// InserFanDlg 消息处理程序
static char* UnicodeToUtf8(CString unicode);

void InserFanDlg::OnBnClickedOk()
{
	UpdateData(TRUE);
	Sqlite *sqlite = new Sqlite;
	if (m_fanName.IsEmpty() || m_minQ.IsEmpty() || m_maxQ.IsEmpty() || m_minH.IsEmpty() || m_maxH.IsEmpty() || m_power.IsEmpty())
	{
		AfxMessageBox(_T("风机参数不能为空"),MB_ICONSTOP | MB_OK);
		return;
	}
	else
	{
		int minQ = _ttoi(m_minQ);
		int maxQ = _ttoi(m_maxQ);
		int minH = _ttoi(m_minH);
		int maxH = _ttoi(m_maxH);
		CString mehtod;
		GetDlgItem(IDC_NEWMETHOD_COMBO)->GetWindowText(mehtod);
		char *name = UnicodeToUtf8(m_fanName);
		char *power = UnicodeToUtf8(m_power);
		if(sqlite->insertFan(mehtod,name,minQ,maxQ,minH,maxH,power))
		{
			AfxMessageBox(_T("数据成功加入"),MB_ICONWARNING | MB_OK);
		}
	}
	OnOK();
}

BOOL InserFanDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_methodCmBox.AddString(_T("压入式"));
	m_methodCmBox.AddString(_T("抽出式"));
	m_methodCmBox.SetCurSel(0);
	return TRUE;
}

static char* UnicodeToUtf8(CString unicode)
{
	wchar_t* wszString = unicode.AllocSysString();
	//预转换，得到所需空间的大小，这次用的函数和上面名字相反
	int u8Len = ::WideCharToMultiByte(CP_UTF8, NULL, wszString, wcslen(wszString), NULL, 0, NULL, NULL);
	//同上，分配空间要给'\0'留个空间
	//UTF8虽然是Unicode的压缩形式，但也是多字节字符串，所以可以以char的形式保存
	char* szU8 = new char[u8Len + 1];
	//转换
	//unicode版对应的strlen是wcslen
	::WideCharToMultiByte(CP_UTF8, NULL, wszString, wcslen(wszString), szU8, u8Len, NULL, NULL);
	//最后加上'\0'
	szU8[u8Len] = '\0';
	return szU8;
}
