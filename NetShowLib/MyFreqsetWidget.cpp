<<<<<<< HEAD
#include "MyFreqsetWidget.h"
#include "MyFreqsetChart.h"

MyFreqsetWidget::MyFreqsetWidget(QWidget *parent)
	: QWidget(parent)
{
    m_pMyFreqsetChart = new CMyFreqsetChart();
	m_pMyFreqsetChart->AttachMyFreqsetWidget(this);
}

MyFreqsetWidget::~MyFreqsetWidget()
{
    if( m_pMyFreqsetChart != NULL )
	{
		delete m_pMyFreqsetChart;
		m_pMyFreqsetChart = NULL;
	}
}


void MyFreqsetWidget::RemoveFreq(double dFreq)
{
  m_pMyFreqsetChart->RemoveFreq(dFreq);
  update();
}

void MyFreqsetWidget::PressFreq(int iIndex,double dFreq)
{
   emit SelectFreq(iIndex,dFreq);
}

void MyFreqsetWidget::InsertFreq(int iRow,double dFreq)
{
	m_pMyFreqsetChart->InsertFreq(iRow,dFreq);
	update();
}

void MyFreqsetWidget::ResetNet()
{
    m_pMyFreqsetChart->ResetNet();
	update();
}

void MyFreqsetWidget::AddOneNet(QString startFreq,QString sEndFreq,QString sFreqCount,QString sHopCycle,QString sLevel,QString sFreqSets,QString sReserved)
{
    m_pMyFreqsetChart->AddOneNet(startFreq,sEndFreq,sFreqCount,sHopCycle,sLevel,sFreqSets,sReserved);
	update();
}

void MyFreqsetWidget::resizeEvent(QResizeEvent* event)
{
    m_pMyFreqsetChart->CreateRect(this->geometry());
}

void MyFreqsetWidget::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	m_pMyFreqsetChart->Refresh(&painter);
}

void MyFreqsetWidget::mousePressEvent(QMouseEvent *event)
{
    m_pMyFreqsetChart->PressPos(event->pos().x());
	update();
}


void MyFreqsetWidget::on_TableSelectFreq(int iIndex,double dFreq)
{
   m_pMyFreqsetChart->SelectFreq(iIndex,dFreq);
}
=======
#include "MyFreqsetWidget.h"
#include "MyFreqsetChart.h"

MyFreqsetWidget::MyFreqsetWidget(QWidget *parent)
	: QWidget(parent)
{
    m_pMyFreqsetChart = new CMyFreqsetChart();
	m_pMyFreqsetChart->AttachMyFreqsetWidget(this);
}

MyFreqsetWidget::~MyFreqsetWidget()
{
    if( m_pMyFreqsetChart != NULL )
	{
		delete m_pMyFreqsetChart;
		m_pMyFreqsetChart = NULL;
	}
}


void MyFreqsetWidget::RemoveFreq(double dFreq)
{
  m_pMyFreqsetChart->RemoveFreq(dFreq);
  update();
}

void MyFreqsetWidget::PressFreq(int iIndex,double dFreq)
{
   emit SelectFreq(iIndex,dFreq);
}

void MyFreqsetWidget::InsertFreq(int iRow,double dFreq)
{
	m_pMyFreqsetChart->InsertFreq(iRow,dFreq);
	update();
}

void MyFreqsetWidget::ResetNet()
{
    m_pMyFreqsetChart->ResetNet();
	update();
}

void MyFreqsetWidget::AddOneNet(QString startFreq,QString sEndFreq,QString sFreqCount,QString sHopCycle,QString sLevel,QString sFreqSets,QString sReserved)
{
    m_pMyFreqsetChart->AddOneNet(startFreq,sEndFreq,sFreqCount,sHopCycle,sLevel,sFreqSets,sReserved);
	update();
}

void MyFreqsetWidget::resizeEvent(QResizeEvent* event)
{
    m_pMyFreqsetChart->CreateRect(this->geometry());
}

void MyFreqsetWidget::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	m_pMyFreqsetChart->Refresh(&painter);
}

void MyFreqsetWidget::mousePressEvent(QMouseEvent *event)
{
    m_pMyFreqsetChart->PressPos(event->pos().x());
	update();
}


void MyFreqsetWidget::on_TableSelectFreq(int iIndex,double dFreq)
{
   m_pMyFreqsetChart->SelectFreq(iIndex,dFreq);
}
>>>>>>> origin/master
