
// calculator-Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "calculator-.h"
#include "calculator-Dlg.h"
#include "afxdialogex.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalculatorDlg �Ի���




CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcalculatorDlg::IDD, pParent)
	, m_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_str);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_B1, &CcalculatorDlg::OnBnClickedB1)
	ON_BN_CLICKED(IDC_B2, &CcalculatorDlg::OnBnClickedB2)
	ON_BN_CLICKED(IDC_B3, &CcalculatorDlg::OnBnClickedB3)
	ON_BN_CLICKED(IDC_B4, &CcalculatorDlg::OnBnClickedB4)
	ON_BN_CLICKED(IDC_B5, &CcalculatorDlg::OnBnClickedB5)
	ON_BN_CLICKED(IDC_B6, &CcalculatorDlg::OnBnClickedB6)
	ON_BN_CLICKED(IDC_B7, &CcalculatorDlg::OnBnClickedB7)
	ON_BN_CLICKED(IDC_B8, &CcalculatorDlg::OnBnClickedB8)
	ON_BN_CLICKED(IDC_B9, &CcalculatorDlg::OnBnClickedB9)
	ON_BN_CLICKED(IDC_B0, &CcalculatorDlg::OnBnClickedB0)
	ON_BN_CLICKED(IDC_DOT, &CcalculatorDlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_CALCULATOR, &CcalculatorDlg::OnBnClickedCalculator)
	ON_BN_CLICKED(IDC_ADD, &CcalculatorDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_Minus, &CcalculatorDlg::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_Mutiply, &CcalculatorDlg::OnBnClickedMutiply)
	ON_BN_CLICKED(IDC_Divide, &CcalculatorDlg::OnBnClickedDivide)
	ON_BN_CLICKED(IDC_PERCENT, &CcalculatorDlg::OnBnClickedPercent)
	ON_BN_CLICKED(IDC_X, &CcalculatorDlg::OnBnClickedX)
	ON_BN_CLICKED(IDC_CLEAR, &CcalculatorDlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_Backspace, &CcalculatorDlg::OnBnClickedBackspace)
	ON_BN_CLICKED(IDC_plusminus, &CcalculatorDlg::OnBnClickedplusminus)
	ON_BN_CLICKED(IDC_signofecolution, &CcalculatorDlg::OnBnClickedsignofecolution)
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CcalculatorDlg ��Ϣ�������

BOOL CcalculatorDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	SetTimer(1,1000,NULL);
	secag=-0.05;
	minag=-0.05;
	hag=-0.05;

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcalculatorDlg::OnPaint()
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
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}






void CcalculatorDlg::OnBnClickedB1()
{
	UpdateData(true);
	m_str=m_str+L"1";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedB2()
{
	UpdateData(true);
	m_str=m_str+L"2";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedB3()
{
	UpdateData(true);
	m_str=m_str+L"3";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedB4()
{
	UpdateData(true);
	m_str=m_str+L"4";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedB5()
{
	UpdateData(true);
	m_str=m_str+L"5";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedB6()
{
	UpdateData(true);
	m_str=m_str+L"6";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedB7()
{
	UpdateData(true);
	m_str=m_str+L"7";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedB8()
{
	UpdateData(true);
	m_str=m_str+L"8";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedB9()
{
	UpdateData(true);
	m_str=m_str+L"9";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedB0()
{
	UpdateData(true);
	m_str=m_str+L"0";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedDot()
{
	UpdateData(true);
	m_str=m_str+L".";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedCalculator()
{
	TRACE("flag=%d",flag);
	UpdateData(true);
	if(flag==1)
	{
		temp=temp+_ttof(m_str);

	}
	else if(flag==2)
	{
		temp=temp-_ttof(m_str);

	}
	else if(flag==3)
	{
		temp=temp*_ttof(m_str);

	}
	else if(flag==4)
	{
		temp=temp/_ttof(m_str);

	}
	m_str.Format(L"%lf",temp);//���������ֵת��Ϊ�ַ�������
	while(m_str.Right(1)=="0")
	{
		m_str.Delete(m_str.GetLength()-1,1);
	
	}
	while(m_str.Right(1)==".")
	{
		m_str.Delete(m_str.GetLength()-1,1);
	
	}
	UpdateData(false);
}



void CcalculatorDlg::OnBnClickedAdd()
{
	flag=1;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedMinus()
{
	flag=2;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedMutiply()
{
	flag=3;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
	
}


void CcalculatorDlg::OnBnClickedDivide()
{
	flag=4;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}

void CcalculatorDlg::OnBnClickedPercent()
{   
	if(flag==1||flag==2||flag==3||flag==4)
	{
		//m_str.Format(L"%lf",temp);
		if(flag==1)
		{
			temp=temp+_ttof(m_str);
		}
		else
		{
			if(flag==2)
			{
				temp=temp-_ttof(m_str);
			}
			else
			{
				if(flag==3)
				{
					temp=temp*_ttof(m_str);

				}
				else 
				{
					if(flag=4)
					{
						temp=temp/_ttof(m_str);
					}
				}	
			}  
		}
	
		m_str.Format(L"%lf",temp*_ttof(m_str)/100);
		UpdateData(false);
	}
}


void CcalculatorDlg::OnBnClickedX()
{
	
		UpdateData(true);
		temp=1/_ttof(m_str);
		m_str="";
		UpdateData(false);
}


void CcalculatorDlg::OnBnClickedClear()
{
	m_str="";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedBackspace()
{
	m_str=m_str.Left(m_str.GetLength()-1); 
    if(m_str=="") 
    {  
        m_str='0'; 
    } 
    UpdateData(false); 

}


void CcalculatorDlg::OnBnClickedplusminus()
{
	if(m_str.Left(1)=="-")
		m_str.Delete(0,1);
	else
		m_str=L"-"+m_str;
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedsignofecolution()
{
	if(_ttof(m_str)<0)
	{
		OnBnClickedClear();
		MessageBox(L"mistake!");
	}
	temp=_ttof(m_str);
	double f=sqrt(temp);
	m_str.Format(L"%f",f);
	m_str.Right(1)=="0";
	m_str.Delete(m_str.GetAllocLength()-4,7);
	while(m_str.Right(1)=="0")
	{
		m_str.Delete(m_str.GetLength()-1,1);
	
	}
	while(m_str.Right(1)==".")
	{
		m_str.Delete(m_str.GetLength()-1,1);
	
	}
	UpdateData(false);
}



void CcalculatorDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	TRACE("X=%d,Y=%d\n",point.x,point.y);
	CDialogEx::OnMouseMove(nFlags, point);
}




void CcalculatorDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	dc.SetWindowOrg(-621,-215);
	CPen *oldpen;
	CPen groundpen(PS_SOLID,4,RGB(255,255,255));
	CPen pen(PS_SOLID,3,RGB(0,0,0));//��Բ�õı�
	oldpen=dc.SelectObject(&pen);
	dc.Ellipse(-100,100,100,-100);//��Բ�ĺ���
	CPen ppen(PS_SOLID,3,RGB(0,0,0));
	oldpen=dc.SelectObject(&ppen);
	dc.Ellipse(-1,-1,1,1);//
	dc.TextOutW(90,-8,L"3");
	dc.TextOutW(-98,-8,L"9");
	dc.TextOutW(-8,-99.5,L"12");
	dc.TextOutW(-2,83,L"6");
	for(int i=0;i<12;i++)
	{
		double l=90,ag=i*3.1415926/6;
		double a=l*sin(ag)+1,b=-l*cos(ag)+1,c=l*sin(ag)-1,d=-l*cos(ag)-1;
		dc.Ellipse(a,b,c,d);
	}

	double L1=70,L2=60,L3=50;          //miaozhen
	oldpen=dc.SelectObject(&groundpen);
	CPen secpen(PS_SOLID,2,RGB(0,0,150));
	oldpen=dc.SelectObject(&secpen);
	secag=secag+3.1415926/30;
	x=L1*sin(secag);
	y=-L1*cos(secag);
	dc.MoveTo(0,0);
	dc.LineTo(x,y);
	 
	oldpen=dc.SelectObject(&groundpen);//fenzhen
	CPen minpen(PS_SOLID,3,RGB(0,200,150));
	oldpen=dc.SelectObject(&minpen);
	minag=minag+3.1415926/1800;
	x=L2*sin(minag);
	y=-L2*cos(minag);
	dc.MoveTo(0,0);
	dc.LineTo(x,y);

	oldpen=dc.SelectObject(&groundpen);//shizhen
	CPen hpen(PS_SOLID,3,RGB(255,123,0));
	oldpen=dc.SelectObject(&hpen);
	hag=hag+3.1415926/21600;
	x=L3*sin(hag);
	y=-L3*cos(hag);
	dc.MoveTo(0,0);
	dc.LineTo(x,y);

	CDialogEx::OnTimer(nIDEvent);
}
