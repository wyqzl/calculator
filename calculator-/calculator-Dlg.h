
// calculator-Dlg.h : ͷ�ļ�
//

#pragma once


// CcalculatorDlg �Ի���
class CcalculatorDlg : public CDialogEx
{
// ����
public:
	CcalculatorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CALCULATOR_DIALOG };

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
	CString m_str;
	int flag;
	double temp;
	afx_msg void OnBnClickedB1();
	afx_msg void OnBnClickedB2();
	afx_msg void OnBnClickedB3();
	afx_msg void OnBnClickedB4();
	afx_msg void OnBnClickedB5();
	afx_msg void OnBnClickedB6();
	afx_msg void OnBnClickedB7();
	afx_msg void OnBnClickedB8();
	afx_msg void OnBnClickedB9();
	afx_msg void OnBnClickedB0();
	afx_msg void OnBnClickedDot();
	afx_msg void OnBnClickedCalculator();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedMinus();
	afx_msg void OnBnClickedMutiply();
	afx_msg void OnBnClickedDivide();
	afx_msg void OnBnClickedPercent();
	afx_msg void OnBnClickedX();
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedBackspace();
	afx_msg void OnBnClickedplusminus();
	afx_msg void OnBnClickedsignofecolution();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	double x,y,secag,hag,minag;
	int color;
};
