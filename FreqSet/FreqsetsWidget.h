
/*频率集显示窗口类。
* 
* 创建者：  陈鼎才
* 创建时间：2018年1月于XX公寓。并上传到GitHub。
* 未经创建者许可，请勿使用，否则后果自负。
*/




#ifndef FREQSETSWIDGET_H
#define FREQSETSWIDGET_H

#include <QWidget>
#include "ui_FreqsetsWidget.h"
#include "MyFreqsetWidget.h"
#include <QDoubleValidator>


class FreqsetsWidget : public QWidget
{
	Q_OBJECT

public:
	FreqsetsWidget(QWidget *parent = 0);
	~FreqsetsWidget();

	//初始化网台个数
	void  ResetNet();

	/*添加网台信息.
    @param startFreq表示起始频率。单位MHz
	@param sEndFreq表示终止频率。单位MHz
	@param sFreqCount表示点数。单位MHz
	@param sHopCycle表示跳频周期。单位毫秒
	@param sLevel表示电平。单位dB
	@param sFreqSets表示频率集。频率间用逗号分隔，频率单位MHz。
	@param sUUID表示网台的唯一性标记，若为空，表示没有标记。
	*/
	void  AddOneNet(QString startFreq,QString sEndFreq,QString sFreqCount,QString sHopCycle,QString sLevel,QString sFreqSets,QString sUUID);


private:
	Ui::FreqsetsWidget ui;
	MyFreqsetWidget*  m_pMyFreqsetWidget;     //频率集图形显示窗口类
    QDoubleValidator* m_pDoubleValidator;     //double型验证器

	void  UpdateFreqset2Net();      //把频率集中频率更新到网台列表中，同步更新的是起始和终止频率，以及新的频率集。
	private slots:
		void on_pushButton_Add_clicked();      //增加按钮槽函数
		void on_pushButton_Delete_clicked();   //删除按钮槽函数
		void on_pushButton_InTable_clicked();  //入表按钮槽函数
		void on_cellClicked ( int row, int column );        //频率集表格子项被点击槽函数
		void OnSelectFreq(int iIndex,double dFreq);          //频率集中指定索引位置频率被选中槽函数。关联图形中指定频率被选中事件
		void on_AllFreqcellClicked ( int row, int column );  //网台表格子项被点击槽函数
protected:
	
signals:
		void TableSelectFreq(int iIndex,double dFreq);    //频率集中指定索引频率选中事件。关联到图形中频率选中槽函数。

		/*发送网台信息到表的信号。接收信号的槽函数需要将其入表
		@param startFreq表示起始频率。单位MHz
		@param sEndFreq表示终止频率。单位MHz
		@param sFreqCount表示点数。单位MHz
		@param sHopCycle表示跳频周期。单位毫秒
		@param sLevel表示电平。单位dB
		@param sFreqSets表示频率集。频率间用逗号分隔，频率单位MHz。
		@param sUUID表示网台的唯一性标记，若为空，表示没有标记。
		*/
		void NetSignal(QString startFreq,QString sEndFreq,QString sFreqCount,QString sHopCycle,QString sLevel,QString sFreqSets,QString sUUID);
};

#endif // FREQSETSWIDGET_H
