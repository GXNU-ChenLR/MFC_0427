
// MFC_0427_1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_0427_1.h"
#include "MFC_0427_1Dlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC_0427_1Dlg 对话框



CMFC_0427_1Dlg::CMFC_0427_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_0427_1_DIALOG, pParent)
	, ss(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_0427_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, Lbox);
	DDX_Text(pDX, IDC_EDIT1, ss);
}

BEGIN_MESSAGE_MAP(CMFC_0427_1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_LBN_SELCHANGE(IDC_LIST1, &CMFC_0427_1Dlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_0427_1Dlg::OnBnClickedButton1)
//	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CMFC_0427_1Dlg 消息处理程序

BOOL CMFC_0427_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	string sss;//读取文件字符串保存到sss中
	CString name;//保存读取的姓名字串
	ifstream ifs(_T("C:\\Users\\Bug\\Desktop\\学生名单.txt"));  // 打开文件
	CClientDC dc(this);
	int x = 20, y = 10;
	while(ifs >> sss)
	{
		name = CString(sss.c_str());
		Lbox.AddString(name);
		//nname.Append(name);
		//nname += _T("\n");
		y += 30;
	}
	ifs.close();

	//Lbox.AddString(_T("abcd"));//测试是否成功添加姓名字串到列表框

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC_0427_1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC_0427_1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFC_0427_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_0427_1Dlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
	n = Lbox.GetCurSel();
	Lbox.GetText(n, s);
	CString s1 = s;
	this->UpdateData(true);
	ss = s1;
	UpdateData(false);
}


void CMFC_0427_1Dlg::OnBnClickedButton1()
{//修改学生姓名
	// TODO: 在此添加控件通知处理程序代码
		this->UpdateData(true);
		CString s2 = ss;
		Lbox.DeleteString(n);
		Lbox.InsertString(n, s2);
		UpdateData(false);
		
		ofstream ofs(_T("C:\\Users\\Bug\\Desktop\\学生名单.txt"));//打开文件
		for (int j = 0; j < Lbox.GetCount(); j++)
		{
			Lbox.GetText(j, nname);
			ofs << CT2A(nname) << endl;
		}
		ofs.close();
}
