#include "FreqsetsWidget.h"
#include <QMessageBox>
#include <QTextCodec>
#include <QDebug>
#include <math.h>

#define StartFreqColumn      0       //起始频率列号
#define EndFreqColumn        1       //终止频率列号
#define FreqCountColumn      2       //频点数列号
#define HopCycleColumn       3       //跳频周期列号
#define LevelColumn          4       //电平列号
#define FreqSetColumn        5       //频率集列号

#define UUIDRole             100     //UUID的角色代号

FreqsetsWidget::FreqsetsWidget(QWidget *parent)
	: QWidget(parent)
{
	this->setStyleSheet("color:rgb(255,255,255);background-color:rgb(100,100,100)");  //设置前景色(白)和背景色（灰）
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
	
	//设置表头内容
	QStringList header;
	header<<QString::fromLocal8Bit("频率(MHz)");//频率
	ui.tableWidget_Freqset->setHorizontalHeaderLabels(header);
	ui.tableWidget_Freqset->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选择行为时每次选择一行
    ui.tableWidget_Freqset->setSelectionMode(QAbstractItemView::SingleSelection); //设置最多选中一行
	ui.tableWidget_Freqset->setStyleSheet("selection-background-color:lightblue;"); //设置选中背景色
	ui.tableWidget_Freqset->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
	ui.tableWidget_Freqset->horizontalHeader()->setStretchLastSection(true); //设置充满表宽度
	ui.tableWidget_Freqset->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(100,100,100);}"); //设置表头背景色
	ui.tableWidget_Freqset->verticalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(100,100,100);}"); //设置表头背景色
    ui.tableWidget_Freqset->setAlternatingRowColors(true);     //背景色交替
	ui.tableWidget_Freqset->setStyleSheet("alternate-background-color:rgb(130,130,130);");  //设置交替的颜色
	
	//多网台表
	QStringList headerNet;
	headerNet<<QString::fromLocal8Bit("起始频率(MHz)")<<QString::fromLocal8Bit("终止频率(MHz)")<<QString::fromLocal8Bit("频率点数")<<QString::fromLocal8Bit("跳频周期(ms)")<<QString::fromLocal8Bit("电平(dB)")<<QString::fromLocal8Bit("频率集(MHz)");//频率
	ui.tableWidget_AllFreq->setColumnCount(headerNet.count());
	ui.tableWidget_AllFreq->setHorizontalHeaderLabels(headerNet);
	ui.tableWidget_AllFreq->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选择行为时每次选择一行
	ui.tableWidget_AllFreq->setSelectionMode(QAbstractItemView::SingleSelection); //设置最多选中一行
	ui.tableWidget_AllFreq->setStyleSheet("selection-background-color:lightblue;"); //设置选中背景色
	ui.tableWidget_AllFreq->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
	ui.tableWidget_AllFreq->horizontalHeader()->setStretchLastSection(true); //设置充满表宽度
	ui.tableWidget_AllFreq->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(100,100,100);}"); //设置表头背景色
	ui.tableWidget_AllFreq->verticalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(100,100,100);}"); //设置表头背景色
	ui.tableWidget_AllFreq->setAlternatingRowColors(true);     //背景色交替
	ui.tableWidget_AllFreq->setStyleSheet("alternate-background-color:rgb(130,130,130);");  //设置交替的颜色
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
	pItem->setData(UUIDRole,sUUID);    //起始频率这项关联到UUID
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
        //取出各项的值
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
		box.setWindowTitle(QString::fromLocal8Bit("提示"));
		box.setText(QString::fromLocal8Bit("频率不能低于30MHz。"));
		box.exec();
		return;
	}
	if( dFreq > m_pDoubleValidator->top() )
	{
		QMessageBox  box;
		box.setWindowTitle(QString::fromLocal8Bit("提示"));
		box.setText(QString::fromLocal8Bit("频率不能高于1300MHz。"));
		box.exec();
		return;
	}
    
	//加到频率表中合适位置
	int iRow = ui.tableWidget_Freqset->rowCount();
	if( iRow < 10)  //防出错。
	{
		QMessageBox  box;
		box.setWindowTitle(QString::fromLocal8Bit("提示"));
		box.setText(QString::fromLocal8Bit("频率个数少于10个。"));
		box.exec();
		return;
	}
	if( iRow > 1040)
	{
		QMessageBox  box;
		box.setWindowTitle(QString::fromLocal8Bit("提示"));
		box.setText(QString::fromLocal8Bit("频率个数已大于1040个。"));
		box.exec();
		return;
	}
	QTableWidgetItem* pItem = NULL;
	double dTempFreq = 30;
	double dFirstFreq = ui.tableWidget_Freqset->item(0,0)->text().toDouble();   //第一个频率

    for(int i=0;i<iRow;i++) //
	{
		pItem = ui.tableWidget_Freqset->item(i,0);
		dTempFreq = pItem->text().toDouble();
		if( fabs(dTempFreq-dFreq) < 0.001)
		{
			QMessageBox  box;
			box.setWindowTitle(QString::fromLocal8Bit("提示"));
			box.setText(QString::fromLocal8Bit("相同频率已存在。"));
			box.exec();
			return;
		}
	}


	if( dFreq < dFirstFreq )  //加到最前面，成第一个频率
	{
        pItem = new QTableWidgetItem();
		pItem->setText(QString("%1").arg(dFreq));
		ui.tableWidget_Freqset->insertRow(0);
		ui.tableWidget_Freqset->setItem(0, 0, pItem);
		//表格更新后需要同步到其他地方。
        m_pMyFreqsetWidget->InsertFreq(0,dFreq);

		
		UpdateFreqset2Net();//更新到网台列表中。

        return;
	}
	else  //找到需要插入的那个频率，插到那里去。
	{
		int  iRowPos = 0;
		double dAfterFreq = 0;
		int  iInsertRow = -1;      //这是待插入的那个位置
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
		ui.tableWidget_Freqset->insertRow(iInsertRow);   //在指定行位置插入一空行。Inserts an empty row into the table at row.
		ui.tableWidget_Freqset->setItem(iInsertRow, 0, pItem);
		//表格更新后需要同步到其他地方。
		m_pMyFreqsetWidget->InsertFreq(iInsertRow,dFreq);

		UpdateFreqset2Net();//更新到网台列表中。
	}
	
}

void FreqsetsWidget::on_pushButton_Delete_clicked()
{
	if( ui.tableWidget_Freqset->rowCount() == 0)
	{
		QMessageBox  box;
		box.setWindowTitle(QString::fromLocal8Bit("提示"));
		box.setText(QString::fromLocal8Bit("无频率。"));
		box.exec();
		return;
	}
	if( ui.tableWidget_Freqset->rowCount() < 10)
	{
		QMessageBox  box;
		box.setWindowTitle(QString::fromLocal8Bit("提示"));
		box.setText(QString::fromLocal8Bit("频率个数已经低于10个，不允许再删除。"));
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
	   if( iRow == ui.tableWidget_Freqset->rowCount()) //删的是最后一行
	   {
		   ui.tableWidget_Freqset->selectRow(iRow-1);
	   }
	   else if(iRow == 0)  //删的是第一行
	   {
           ui.tableWidget_Freqset->selectRow(0);
	   }
	   else    //其他时选中当前行的下一行
	   {
		   ui.tableWidget_Freqset->selectRow(iRow);
           double dFreq = ui.tableWidget_Freqset->item(iRow,0)->text().toDouble();
		   emit TableSelectFreq(iRow+1,dFreq);
	   }  

	   UpdateFreqset2Net();//更新到网台列表中。
	}
}

void FreqsetsWidget::on_pushButton_InTable_clicked()
{
	QList<QTableWidgetItem*> netlist=ui.tableWidget_AllFreq->selectedItems();
	if( netlist.size() == 0)
	{
		QMessageBox  box;
		box.setWindowTitle(QString::fromLocal8Bit("提示"));
		box.setText(QString::fromLocal8Bit("无网台。"));
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

