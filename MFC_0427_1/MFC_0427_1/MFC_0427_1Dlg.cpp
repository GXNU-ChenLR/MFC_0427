
// MFC_0427_1Dlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFC_0427_1Dlg �Ի���



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


// CMFC_0427_1Dlg ��Ϣ�������

BOOL CMFC_0427_1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	string sss;//��ȡ�ļ��ַ������浽sss��
	CString name;//�����ȡ�������ִ�
	ifstream ifs(_T("C:\\Users\\Bug\\Desktop\\ѧ������.txt"));  // ���ļ�
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

	//Lbox.AddString(_T("abcd"));//�����Ƿ�ɹ���������ִ����б��

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC_0427_1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFC_0427_1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_0427_1Dlg::OnLbnSelchangeList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	n = Lbox.GetCurSel();
	Lbox.GetText(n, s);
	CString s1 = s;
	this->UpdateData(true);
	ss = s1;
	UpdateData(false);
}


void CMFC_0427_1Dlg::OnBnClickedButton1()
{//�޸�ѧ������
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		this->UpdateData(true);
		CString s2 = ss;
		Lbox.DeleteString(n);
		Lbox.InsertString(n, s2);
		UpdateData(false);
		
		ofstream ofs(_T("C:\\Users\\Bug\\Desktop\\ѧ������.txt"));//���ļ�
		for (int j = 0; j < Lbox.GetCount(); j++)
		{
			Lbox.GetText(j, nname);
			ofs << CT2A(nname) << endl;
		}
		ofs.close();
}
