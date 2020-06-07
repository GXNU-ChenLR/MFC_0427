
// MFC_0427_2View.h : CMFC_0427_2View 类的接口
//

#pragma once


class CMFC_0427_2View : public CView
{
protected: // 仅从序列化创建
	CMFC_0427_2View();
	DECLARE_DYNCREATE(CMFC_0427_2View)

// 特性
public:
	CMFC_0427_2Doc* GetDocument() const;

	void OnLButtonDown(UINT nFlags, CPoint point);
	void OnMouseMove(UINT nFlags, CPoint point);
	void OnLButtonUp(UINT nFlags, CPoint point);
// 操作
public:
	CRect crect;
	bool flag;
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CMFC_0427_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC_0427_2View.cpp 中的调试版本
inline CMFC_0427_2Doc* CMFC_0427_2View::GetDocument() const
   { return reinterpret_cast<CMFC_0427_2Doc*>(m_pDocument); }
#endif

