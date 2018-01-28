#include "MyFreqsetChart.h"
#include <math.h>
#include <QDebug>
#include "MyFreqsetWidget.h"

CMyFreqsetChart::CMyFreqsetChart(void)
{
  
   m_iFreqCount = 10;
   m_pDrawData = new FreqDrawData[10];
   m_iPressPos = 0;
   m_iAmp = -80;
}

CMyFreqsetChart::~CMyFreqsetChart(void)
{
   delete [] m_pDrawData;
}

void CMyFreqsetChart::CreateRect(QRect rect)
{
   m_Rect = rect;
   m_Pixmap =  QPixmap( rect.width(),rect.height());   //Pixmap是对应整个区域的，不是仅仅对应频谱区。
}

void CMyFreqsetChart::Refresh(QPainter* pPainter)
{
    Draw();
	pPainter->drawPixmap(m_Rect,m_Pixmap);
}

void CMyFreqsetChart::Draw()
{
	m_sFreq = "";
	QPainter painter(&m_Pixmap);
	QRect r = m_Pixmap.rect();
	painter.fillRect(m_Rect.x(),m_Rect.y(),m_Rect.width(),m_Rect.height(),QColor(0,0,0));
	painter.setPen(QPen(QColor(0,255,0)));
    if( m_List.size() == 0 )
	{
		return;
	}
	if( m_List.size() > m_Rect.width() )
	{
		return;
	}
	float fVFlex = m_Rect.height()/(120);
    float fHFlex = (m_dEndfreq-m_dStartFreq)/(m_Rect.width()-5);
    QPointF  firstPoint,secondPoint;
    firstPoint.setX(1);
	firstPoint.setY(m_Rect.y()+m_Rect.height());
	bool bSelected = false;
	for(int i=0;i<m_List.size();i++)
	{
        firstPoint.setX( 2+(m_List.at(i).m_dFreq-m_dStartFreq)/fHFlex);
		secondPoint.setX(firstPoint.x());
		secondPoint.setY( (120-(m_List.at(i).m_Amp-(-120)))*fVFlex );
        painter.drawLine(firstPoint,secondPoint);
		m_FreqPos[i].m_dFreq = m_List.at(i).m_dFreq;
		m_FreqPos[i].m_iPos = firstPoint.x();
		if( abs(m_iPressPos - firstPoint.x())<=3 && bSelected == false )
		{
		   if( i+1 < m_List.size() )
		   {
               float fX = 1+(m_List.at(i+1).m_dFreq-m_dStartFreq)/fHFlex;
			   if( abs(m_iPressPos - firstPoint.x()) > abs(m_iPressPos - fX ) )
			   {
				   continue;
			   }
		   }
           painter.save();
           painter.setPen(QPen(QColor(255,0,0)));
           painter.drawLine(firstPoint,secondPoint);
		   painter.restore();
		   bSelected = true;
		   m_sFreq = QString("%1").arg(m_List.at(i).m_dFreq);
		}
	}
    if( m_sFreq != "")
	{
	   painter.drawText(10,20,m_sFreq+"MHz");
	}
}

void CMyFreqsetChart::RemoveFreq(double dFreq)
{
	QList<FreqDrawData>::Iterator Iter;
	for(Iter=m_List.begin();Iter!=m_List.end();Iter++)
	{
		double d = Iter->m_dFreq;
		double dd = fabs(Iter->m_dFreq - dFreq);
		if( fabs(Iter->m_dFreq - dFreq) < 0.001)
		{
			m_List.erase(Iter);
			m_iFreqCount--;
			break;
		}
	}
	m_dStartFreq = m_List.at(0).m_dFreq;
	m_dEndfreq = m_List.at(m_List.size()-1).m_dFreq;
	if( m_iPressPos != 0)
	{
	   PressPos(m_iPressPos);
	}
}

void CMyFreqsetChart::InsertFreq(int iRow,double dFreq)
{
	
	if( iRow == 0)
	{
		FreqDrawData  drawData;
		drawData.m_dFreq = dFreq;
		drawData.m_Amp = m_iAmp;
		m_List.push_front(drawData);
	}
	else 
	{
		FreqDrawData  drawData;
		drawData.m_Amp = m_iAmp;
		drawData.m_dFreq = dFreq;
		m_List.insert(iRow,drawData);
	}
	m_dStartFreq = m_List.at(0).m_dFreq;
	m_dEndfreq = m_List.at(m_List.size()-1).m_dFreq;
	if( m_iPressPos != 0)
	{
		PressPos(m_iPressPos);
	}
}

void CMyFreqsetChart::PressPos(int xPos)
{
   for(int i=0;i<m_iFreqCount;i++)
   {
	   if( abs(m_FreqPos[i].m_iPos - xPos) <= 3)
	   {
		   if( i+1 < m_iFreqCount )
		   {
			   if( abs(m_FreqPos[i].m_iPos - xPos) > abs(m_FreqPos[i+1].m_iPos - xPos))
			   {
				   continue;
			   }
		   }
		   m_sFreq = QString("%1").arg(m_FreqPos[i].m_dFreq);
		   m_iPressPos = xPos;
		   m_pMyFreqsetWidget->PressFreq(i,m_FreqPos[i].m_dFreq);
		   break;
	   }
   }
}

void CMyFreqsetChart::AttachMyFreqsetWidget(MyFreqsetWidget* pMyFreqsetWidget)
{
     m_pMyFreqsetWidget = pMyFreqsetWidget;
}

void CMyFreqsetChart::SelectFreq(int iIndex,double dFreq)
{
	m_iPressPos = m_FreqPos[iIndex].m_iPos;
	m_pMyFreqsetWidget->update();
}

void CMyFreqsetChart::ResetNet()
{
    m_List.clear();
	m_sFreq = "";
}

void CMyFreqsetChart::AddOneNet(QString startFreq,QString sEndFreq,QString sFreqCount,QString sHopCycle,QString sLevel,QString sFreqSets,QString sReserved)
{
   QStringList list = sFreqSets.split(",");
   if( list.size() < 8 )
   {
	   return;
   }
   if(list.size() > 1040)
   {
      return;
   }
   m_iFreqCount = list.size();
   for(int i=0;i<m_iFreqCount;i++)
   {
	   FreqDrawData drawData;
       drawData.m_dFreq = list.at(i).toDouble();
	   drawData.m_Amp = sLevel.toShort();
	   m_List.push_back(drawData);
   }
   m_dStartFreq = list.at(0).toDouble();
   m_dEndfreq = list.at(list.size()-1).toDouble();
   m_iAmp = sLevel.toShort();
} 
