
// MFC_0427_2View.cpp : CMFC_0427_2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC_0427_2.h"
#endif

#include "MFC_0427_2Doc.h"
#include "MFC_0427_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_0427_2View

IMPLEMENT_DYNCREATE(CMFC_0427_2View, CView)

BEGIN_MESSAGE_MAP(CMFC_0427_2View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMFC_0427_2View ����/����

CMFC_0427_2View::CMFC_0427_2View()
{
	// TODO: �ڴ˴���ӹ������
	flag = false;
	//crect.SetRect(0, 0, 0, 0);
}

CMFC_0427_2View::~CMFC_0427_2View()
{
}

BOOL CMFC_0427_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC_0427_2View ����

void CMFC_0427_2View::OnDraw(CDC* pDC)
{
	CMFC_0427_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	pDC->Ellipse(crect);
	for (int i = 0; i < pDoc->cr.GetCount(); i++)
	{
		pDC->Ellipse(pDoc->cr[i]);
	}
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC_0427_2View ���

#ifdef _DEBUG
void CMFC_0427_2View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_0427_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_0427_2Doc* CMFC_0427_2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0427_2Doc)));
	return (CMFC_0427_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0427_2View ��Ϣ�������


void CMFC_0427_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	GetCapture();
	flag = true;
	crect.left = point.x;
	crect.top = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC_0427_2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	crect.right = point.x;
	crect.bottom = point.y;
	if (flag)
    Invalidate();
	CView::OnMouseMove(nFlags, point);
}


void CMFC_0427_2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	CMFC_0427_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	ReleaseCapture();
	flag = false;
	//Invalidate();
	pDoc->cr.Add(crect);
	CView::OnLButtonUp(nFlags, point);
}
