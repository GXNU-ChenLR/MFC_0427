
// MFC_0427_1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;


// CMFC_0427_1Dlg �Ի���
class CMFC_0427_1Dlg : public CDialogEx
{
// ����
public:
	CMFC_0427_1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_0427_1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList1();
	CListBox Lbox;
};
