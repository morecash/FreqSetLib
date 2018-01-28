#include "testnetshow.h"
#include <QTextCodec>
#include <QDebug>
#include "FreqDrawDataHeader.h"

#pragma  comment(lib,"../FreqSet/Win32/Debug/NetShowLib.lib")

TestNetShow::TestNetShow(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
	QString strMessage = QString::fromLocal8Bit("我是UTF8编码的文件：");
	qDebug() << strMessage;

	resize(1249,590);
	//ui.setupUi(this);
	m_pFreqsetsWidget = new FreqsetsWidget();
	setCentralWidget(m_pFreqsetsWidget);
	
	connect(m_pFreqsetsWidget,SIGNAL(NetSignal(QString,QString,QString,QString,QString,QString,QString)),this,SLOT(OnNetSignal(QString,QString,QString,QString,QString,QString,QString)));

	m_pMenu = menuBar()->addMenu(tr("&File"));
	m_pAddAct = new QAction("Open",this);
	m_pMenu->addAction(m_pAddAct);

	connect(m_pAddAct,SIGNAL(triggered()),this,SLOT(onAdd()));

	m_pSpaceAct = new QAction("Space",this);
	m_pMenu->addAction(m_pSpaceAct);

	connect(m_pSpaceAct,SIGNAL(triggered()),this,SLOT(onSpaceAct()));
}

TestNetShow::~TestNetShow()
{

}

void TestNetShow::onAdd()
{
bool bInit = true;
	if( bInit )
	{
		m_pFreqsetsWidget->ResetNet();
		int  iRow = 512;
		QString sFreqSet = "";
		//ui.tableWidget_Freqset->setRowCount(iRow);
		FreqDrawData*  pData = new FreqDrawData[iRow];
		double dStart = 100;
		double dEnd = 120;
		float iCount = (dEnd-dStart)/iRow;
		for(int i=0;i<iRow;i++)
		{
			pData[i].m_dFreq = dStart+i*iCount;
			pData[i].m_Amp = -46;


			/*QTableWidgetItem *pItem = new QTableWidgetItem();
			pItem->setText(QString("%1").arg(pData[i].m_dFreq));
			ui.tableWidget_Freqset->setItem(i, 0, pItem);*/

			sFreqSet += QString("%1").arg(pData[i].m_dFreq);
			if( i != iRow-1 )
			{
			   sFreqSet += ",";
			}
		}
		
        m_pFreqsetsWidget->AddOneNet("100","120",QString("%1").arg(iRow),"30","-46",sFreqSet,"123");
		m_pFreqsetsWidget->AddOneNet("100","120",QString("%1").arg(iRow),"30","-49",sFreqSet,"12345");
		m_pFreqsetsWidget->AddOneNet("100","120",QString("%1").arg(iRow),"30","-80",sFreqSet,"123456");
		delete [] pData;

		bInit = false;
	}
}

void TestNetShow::onSpaceAct()
{
 m_pFreqsetsWidget->ResetNet();
}

void TestNetShow::OnNetSignal(QString startFreq,QString sEndFreq,QString sFreqCount,QString sHopCycle,QString sLevel,QString sFreqSets,QString sUUID)
{

}
