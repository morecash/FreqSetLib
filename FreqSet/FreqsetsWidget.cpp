#include "FreqsetsWidget.h"
#include <QMessageBox>
#include <QTextCodec>
#include <QDebug>
#include <math.h>

#define StartFreqColumn      0       //��ʼƵ���к�
#define EndFreqColumn        1       //��ֹƵ���к�
#define FreqCountColumn      2       //Ƶ�����к�
#define HopCycleColumn       3       //��Ƶ�����к�
#define LevelColumn          4       //��ƽ�к�
#define FreqSetColumn        5       //Ƶ�ʼ��к�

#define UUIDRole             100     //UUID�Ľ�ɫ����

FreqsetsWidget::FreqsetsWidget(QWidget *parent)
	: QWidget(parent)
{
	this->setStyleSheet("color:rgb(255,255,255);background-color:rgb(100,100,100)");  //����ǰ��ɫ(��)�ͱ���ɫ���ң�
	ui.setupUi(this);
	setFixedSize(1242,570);
	m_pMyFreqsetWidget = new MyFreqsetWidget(this);

	QRect rect(1,0,this->width()-ui.tableWidget_Freqset->width()-15,ui.tableWidget_Freqset->height()-100);
    m_pMyFreqsetWidget->setGeometry(rect);

	QRect AllFreqRect(1,rect.y()+rect.height()+3,rect.width(),this->height()-rect.height()-rect.y()-10);
	ui.tableWidget_AllFreq->setGeometry(AllFreqRect);

    connect(ui.tableWidget_Freqset,SIGNAL(cellClicked(int,int)),this,SLOT(on_cellClicked(int,int)));
	connect(ui.tableWidget_AllFreq,SIGNAL(cellClicked(int,int)),this,SLOT(on_AllFreqcellClicked(int,int)));

	connect(m_pMyFreqsetWidget,SIGNAL(SelectFreq(int,double)),this,SLOT(OnSelectFreq(int,double)));
	connect(this,SIGNAL(TableSelectFreq(int,double)),m_pMyFreqsetWidget,SLOT(on_TableSelectFreq(int,double)));

	m_pDoubleValidator = new QDoubleValidator(this);
	m_pDoubleValidator->setRange(30,1300,4);
	ui.lineEdit_Freq->setValidator(m_pDoubleValidator);

	ui.tableWidget_Freqset->setColumnCount(1);
	
	//���ñ�ͷ����
	QStringList header;
	header<<QString::fromLocal8Bit("Ƶ��(MHz)");//Ƶ��
	ui.tableWidget_Freqset->setHorizontalHeaderLabels(header);
	ui.tableWidget_Freqset->setSelectionBehavior(QAbstractItemView::SelectRows);  //����ѡ����Ϊʱÿ��ѡ��һ��
    ui.tableWidget_Freqset->setSelectionMode(QAbstractItemView::SingleSelection); //�������ѡ��һ��
	ui.tableWidget_Freqset->setStyleSheet("selection-background-color:lightblue;"); //����ѡ�б���ɫ
	ui.tableWidget_Freqset->setEditTriggers(QAbstractItemView::NoEditTriggers); //���ò��ɱ༭
	ui.tableWidget_Freqset->horizontalHeader()->setStretchLastSection(true); //���ó�������
	ui.tableWidget_Freqset->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(100,100,100);}"); //���ñ�ͷ����ɫ
	ui.tableWidget_Freqset->verticalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(100,100,100);}"); //���ñ�ͷ����ɫ
    ui.tableWidget_Freqset->setAlternatingRowColors(true);     //����ɫ����
	ui.tableWidget_Freqset->setStyleSheet("alternate-background-color:rgb(130,130,130);");  //���ý������ɫ
	
	//����̨��
	QStringList headerNet;
	headerNet<<QString::fromLocal8Bit("��ʼƵ��(MHz)")<<QString::fromLocal8Bit("��ֹƵ��(MHz)")<<QString::fromLocal8Bit("Ƶ�ʵ���")<<QString::fromLocal8Bit("��Ƶ����(ms)")<<QString::fromLocal8Bit("��ƽ(dB)")<<QString::fromLocal8Bit("Ƶ�ʼ�(MHz)");//Ƶ��
	ui.tableWidget_AllFreq->setColumnCount(headerNet.count());
	ui.tableWidget_AllFreq->setHorizontalHeaderLabels(headerNet);
	ui.tableWidget_AllFreq->setSelectionBehavior(QAbstractItemView::SelectRows);  //����ѡ����Ϊʱÿ��ѡ��һ��
	ui.tableWidget_AllFreq->setSelectionMode(QAbstractItemView::SingleSelection); //�������ѡ��һ��
	ui.tableWidget_AllFreq->setStyleSheet("selection-background-color:lightblue;"); //����ѡ�б���ɫ
	ui.tableWidget_AllFreq->setEditTriggers(QAbstractItemView::NoEditTriggers); //���ò��ɱ༭
	ui.tableWidget_AllFreq->horizontalHeader()->setStretchLastSection(true); //���ó�������
	ui.tableWidget_AllFreq->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(100,100,100);}"); //���ñ�ͷ����ɫ
	ui.tableWidget_AllFreq->verticalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(100,100,100);}"); //���ñ�ͷ����ɫ
	ui.tableWidget_AllFreq->setAlternatingRowColors(true);     //����ɫ����
	ui.tableWidget_AllFreq->setStyleSheet("alternate-background-color:rgb(130,130,130);");  //���ý������ɫ
}

FreqsetsWidget::~FreqsetsWidget()
{

}

void FreqsetsWidget::ResetNet()
{
	ui.tableWidget_AllFreq->clearContents();
	ui.tableWidget_AllFreq->setRowCount(0);
	ui.tableWidget_Freqset->setRowCount(0);
	m_pMyFreqsetWidget->ResetNet();
}

void FreqsetsWidget::AddOneNet(QString startFreq,QString sEndFreq,QString sFreqCount,QString sHopCycle,QString sLevel,QString sFreqSets,QString sUUID)
{

	int iRow = ui.tableWidget_AllFreq->rowCount();
    ui.tableWidget_AllFreq->setRowCount(iRow+1);
    
	QTableWidgetItem *pItem = new QTableWidgetItem();
	pItem->setText(startFreq);
	pItem->setData(UUIDRole,sUUID);    //��ʼƵ�����������UUID
	ui.tableWidget_AllFreq->setItem(iRow, StartFreqColumn, pItem);
	pItem = new QTableWidgetItem();
	pItem->setText(sEndFreq);
	ui.tableWidget_AllFreq->setItem(iRow, EndFreqColumn, pItem);
	pItem = new QTableWidgetItem();
	pItem->setText(sFreqCount);
	ui.tableWidget_AllFreq->setItem(iRow, FreqCountColumn, pItem);
	pItem = new QTableWidgetItem();
	pItem->setText(sHopCycle);
	ui.tableWidget_AllFreq->setItem(iRow, HopCycleColumn, pItem);
	pItem = new QTableWidgetItem();
	pItem->setText(sLevel);
	ui.tableWidget_AllFreq->setItem(iRow, LevelColumn, pItem);
	pItem = new QTableWidgetItem();
	pItem->setText(sFreqSets);
	ui.tableWidget_AllFreq->setItem(iRow, FreqSetColumn, pItem);
    if( iRow == 0)
	{
		on_AllFreqcellClicked(0,1);
	}
	QList<QTableWidgetItem*> netlist=ui.tableWidget_AllFreq->selectedItems();
	if( netlist.size() == 0)
	{
       ui.tableWidget_AllFreq->selectRow(0);
	}
}

void FreqsetsWidget::UpdateFreqset2Net()
{
	QTableWidgetItem* pItem = NULL;
	QList<QTableWidgetItem*> netlist=ui.tableWidget_AllFreq->selectedItems();
	if( netlist.size() != 0)
	{
		int  iRowCount = ui.tableWidget_Freqset->rowCount();
		QString sStartFreq = (ui.tableWidget_Freqset->item(0,0)->text());
		QString sEndFreq = ui.tableWidget_Freqset->item(iRowCount -1,0)->text();
		QString sFreqSets = "";
		for(int i=0;i<iRowCount;i++)
		{
			sFreqSets += ui.tableWidget_Freqset->item(i,0)->text();
			if( i != iRowCount-1)
			{
				sFreqSets += ",";
			}
		}
        //ȡ�������ֵ
		int  iNetRow = netlist.at(0)->row();
		pItem = ui.tableWidget_AllFreq->item(iNetRow,StartFreqColumn);
		pItem->setText(sStartFreq);

		pItem = ui.tableWidget_AllFreq->item(iNetRow,EndFreqColumn);
		pItem->setText(sEndFreq);

		pItem = ui.tableWidget_AllFreq->item(iNetRow,FreqCountColumn);
		pItem->setText(QString("%1").arg(iRowCount));

		pItem = ui.tableWidget_AllFreq->item(iNetRow,FreqSetColumn);
		pItem->setText(sFreqSets);
	}
}

void FreqsetsWidget::on_pushButton_Add_clicked()
{
	double dFreq = ui.lineEdit_Freq->text().toDouble();
	if( dFreq < m_pDoubleValidator->bottom() )
	{
		QMessageBox  box;
		box.setWindowTitle(QString::fromLocal8Bit("��ʾ"));
		box.setText(QString::fromLocal8Bit("Ƶ�ʲ��ܵ���30MHz��"));
		box.exec();
		return;
	}
	if( dFreq > m_pDoubleValidator->top() )
	{
		QMessageBox  box;
		box.setWindowTitle(QString::fromLocal8Bit("��ʾ"));
		box.setText(QString::fromLocal8Bit("Ƶ�ʲ��ܸ���1300MHz��"));
		box.exec();
		return;
	}
    
	//�ӵ�Ƶ�ʱ��к���λ��
	int iRow = ui.tableWidget_Freqset->rowCount();
	if( iRow < 10)  //������
	{
		QMessageBox  box;
		box.setWindowTitle(QString::fromLocal8Bit("��ʾ"));
		box.setText(QString::fromLocal8Bit("Ƶ�ʸ�������10����"));
		box.exec();
		return;
	}
	if( iRow > 1040)
	{
		QMessageBox  box;
		box.setWindowTitle(QString::fromLocal8Bit("��ʾ"));
		box.setText(QString::fromLocal8Bit("Ƶ�ʸ����Ѵ���1040����"));
		box.exec();
		return;
	}
	QTableWidgetItem* pItem = NULL;
	double dTempFreq = 30;
	double dFirstFreq = ui.tableWidget_Freqset->item(0,0)->text().toDouble();   //��һ��Ƶ��

    for(int i=0;i<iRow;i++) //
	{
		pItem = ui.tableWidget_Freqset->item(i,0);
		dTempFreq = pItem->text().toDouble();
		if( fabs(dTempFreq-dFreq) < 0.001)
		{
			QMessageBox  box;
			box.setWindowTitle(QString::fromLocal8Bit("��ʾ"));
			box.setText(QString::fromLocal8Bit("��ͬƵ���Ѵ��ڡ�"));
			box.exec();
			return;
		}
	}


	if( dFreq < dFirstFreq )  //�ӵ���ǰ�棬�ɵ�һ��Ƶ��
	{
        pItem = new QTableWidgetItem();
		pItem->setText(QString("%1").arg(dFreq));
		ui.tableWidget_Freqset->insertRow(0);
		ui.tableWidget_Freqset->setItem(0, 0, pItem);
		//�����º���Ҫͬ���������ط���
        m_pMyFreqsetWidget->InsertFreq(0,dFreq);

		
		UpdateFreqset2Net();//���µ���̨�б��С�

        return;
	}
	else  //�ҵ���Ҫ������Ǹ�Ƶ�ʣ��嵽����ȥ��
	{
		int  iRowPos = 0;
		double dAfterFreq = 0;
		int  iInsertRow = -1;      //���Ǵ�������Ǹ�λ��
		for(int i=0;i<iRow;i++)
		{
			pItem = ui.tableWidget_Freqset->item(i,0);
			dTempFreq = pItem->text().toDouble();
            if( i< iRow-1)
			{
                 pItem = ui.tableWidget_Freqset->item(i+1,0);
				 dAfterFreq = pItem->text().toDouble();
				 if(  (dTempFreq-dFreq<0.0001) && ( dAfterFreq-dFreq > 0.0001 ))
				 {
					 iInsertRow = i+1;
                     break;
				 }
			}		
		}
		if( iInsertRow == -1)
		{
			iInsertRow = iRow;
		}

		QTableWidgetItem* pItem = new QTableWidgetItem();
		pItem->setText(QString("%1").arg(dFreq));
		ui.tableWidget_Freqset->insertRow(iInsertRow);   //��ָ����λ�ò���һ���С�Inserts an empty row into the table at row.
		ui.tableWidget_Freqset->setItem(iInsertRow, 0, pItem);
		//�����º���Ҫͬ���������ط���
		m_pMyFreqsetWidget->InsertFreq(iInsertRow,dFreq);

		UpdateFreqset2Net();//���µ���̨�б��С�
	}
	
}

void FreqsetsWidget::on_pushButton_Delete_clicked()
{
	if( ui.tableWidget_Freqset->rowCount() == 0)
	{
		QMessageBox  box;
		box.setWindowTitle(QString::fromLocal8Bit("��ʾ"));
		box.setText(QString::fromLocal8Bit("��Ƶ�ʡ�"));
		box.exec();
		return;
	}
	if( ui.tableWidget_Freqset->rowCount() < 10)
	{
		QMessageBox  box;
		box.setWindowTitle(QString::fromLocal8Bit("��ʾ"));
		box.setText(QString::fromLocal8Bit("Ƶ�ʸ����Ѿ�����10������������ɾ����"));
		box.exec();
		return;
	}
    QList<QTableWidgetItem*> list=ui.tableWidget_Freqset->selectedItems();
	if( list.size() != 0)
	{
       QTableWidgetItem*  pItem = list.at(0);
	   double dFreq = pItem->text().toDouble();
	   int iRow = pItem->row();
	   ui.tableWidget_Freqset->removeRow(pItem->row());
	   m_pMyFreqsetWidget->RemoveFreq(dFreq);
	   if( iRow == ui.tableWidget_Freqset->rowCount()) //ɾ�������һ��
	   {
		   ui.tableWidget_Freqset->selectRow(iRow-1);
	   }
	   else if(iRow == 0)  //ɾ���ǵ�һ��
	   {
           ui.tableWidget_Freqset->selectRow(0);
	   }
	   else    //����ʱѡ�е�ǰ�е���һ��
	   {
		   ui.tableWidget_Freqset->selectRow(iRow);
           double dFreq = ui.tableWidget_Freqset->item(iRow,0)->text().toDouble();
		   emit TableSelectFreq(iRow+1,dFreq);
	   }  

	   UpdateFreqset2Net();//���µ���̨�б��С�
	}
}

void FreqsetsWidget::on_pushButton_InTable_clicked()
{
	QList<QTableWidgetItem*> netlist=ui.tableWidget_AllFreq->selectedItems();
	if( netlist.size() == 0)
	{
		QMessageBox  box;
		box.setWindowTitle(QString::fromLocal8Bit("��ʾ"));
		box.setText(QString::fromLocal8Bit("����̨��"));
		box.exec();
        return;
	}

	int  iNetRow = netlist.at(0)->row();
	QTableWidgetItem*  pItem = ui.tableWidget_AllFreq->item(iNetRow,StartFreqColumn);
	QString sStartFreq = pItem->text();
	QString sUUID = pItem->data(UUIDRole).toString();
	pItem = ui.tableWidget_AllFreq->item(iNetRow,EndFreqColumn);
	QString sEndFreq = pItem->text();
	pItem = ui.tableWidget_AllFreq->item(iNetRow,FreqCountColumn);
	QString sFreqCount = pItem->text();
	pItem = ui.tableWidget_AllFreq->item(iNetRow,HopCycleColumn);
	QString sHopCycle = pItem->text();
	pItem = ui.tableWidget_AllFreq->item(iNetRow,LevelColumn);
	QString sLevel = pItem->text();
	pItem = ui.tableWidget_AllFreq->item(iNetRow,FreqSetColumn);
	QString sFreqSet = pItem->text();
	emit NetSignal(sStartFreq,sEndFreq,sFreqCount,sHopCycle,sLevel,sFreqSet,sUUID);
}

void FreqsetsWidget::on_cellClicked(int row, int column)
{
   QTableWidgetItem*  pItem = ui.tableWidget_Freqset->item(row,0);
   if( pItem == NULL)
   {
	   return;
   }
   ui.lineEdit_Freq->setText(pItem->text());
   double dFreq = pItem->text().toDouble();
   //
   emit TableSelectFreq(row,dFreq);
}

void FreqsetsWidget::OnSelectFreq(int iIndex,double dFreq)
{
    ui.tableWidget_Freqset->selectRow(iIndex);
}

void FreqsetsWidget::on_AllFreqcellClicked(int row, int column)
{
	QTableWidgetItem*  pItem = ui.tableWidget_AllFreq->item(row,StartFreqColumn);
	if( pItem == NULL)
	{
		return;
	}
	QString sStartFreq = pItem->text();
	pItem = ui.tableWidget_AllFreq->item(row,EndFreqColumn);
	if( pItem == NULL)
	{
		return;
	}
	QString sEndFreq = pItem->text();

	pItem = ui.tableWidget_AllFreq->item(row,FreqCountColumn);
	if( pItem == NULL)
	{
		return;
	}
	QString sFreqCount = pItem->text();

	pItem = ui.tableWidget_AllFreq->item(row,HopCycleColumn);
	if( pItem == NULL)
	{
		return;
	}
	QString sHopCycle = pItem->text();

	pItem = ui.tableWidget_AllFreq->item(row,LevelColumn);
	if( pItem == NULL)
	{
		return;
	}
	QString sLevel = pItem->text();

	pItem = ui.tableWidget_AllFreq->item(row,FreqSetColumn);
	if( pItem == NULL)
	{
		return;
	}
	QString sFreqSet = pItem->text();

	m_pMyFreqsetWidget->ResetNet();
	m_pMyFreqsetWidget->AddOneNet(sStartFreq,sEndFreq,sFreqCount,sHopCycle,sLevel,sFreqSet,"");
	QStringList list = sFreqSet.split(",");
	if( list.size() < 8 )
	{
		return;
	}
	ui.tableWidget_Freqset->clearContents();
	ui.tableWidget_Freqset->setRowCount(list.size());
	for(int i=0;i<list.size();i++)
	{
		QTableWidgetItem *pItem = new QTableWidgetItem();
		pItem->setText(list.at(i));
		ui.tableWidget_Freqset->setItem(i, 0, pItem);
	}
}

