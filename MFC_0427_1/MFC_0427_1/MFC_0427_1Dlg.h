
// MFC_0427_1Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;


// CMFC_0427_1Dlg 对话框
class CMFC_0427_1Dlg : public CDialogEx
{
// 构造
public:
	CMFC_0427_1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_0427_1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList1();
	CListBox Lbox;
	CString s;
	CString ss;
	bool flag;
	int n;
	CString nname;//保存读取的所有姓名字串
	afx_msg void OnBnClickedButton1();
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
