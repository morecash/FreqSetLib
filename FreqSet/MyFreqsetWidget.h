/*频率集绘图对象母体窗口类。
* 
* 创建者：  陈鼎才
* 创建时间：2018年1月于皇马公寓。并上传到GitHub。
* 未经创建者许可，请勿使用，否则后果自负。
*/

#ifndef MYFREQSETWIDGET_H
#define MYFREQSETWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QResizeEvent>
#include "FreqDrawDataHeader.h"

class CMyFreqsetChart;
class MyFreqsetWidget : public QWidget
{
	Q_OBJECT

public:
	//构造函数
	MyFreqsetWidget(QWidget *parent=0);
	//析构函数
	~MyFreqsetWidget();
	//删除一个频率
	void  RemoveFreq(double dFreq);
	//选中一个频率
    void  PressFreq(int iIndex,double dFreq);
	//插入一个频率
	void   InsertFreq(int iRow,double dFreq);
    //网台初始化
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
	void  AddOneNet(QString startFreq,QString sEndFreq,QString sFreqCount,QString sHopCycle,QString sLevel,QString sFreqSets,QString sReserved);

protected:
	void resizeEvent(QResizeEvent* event);  
	void  paintEvent(QPaintEvent *event);
	void  mousePressEvent(QMouseEvent *event);
private:
	//频率集绘图类
	CMyFreqsetChart*  m_pMyFreqsetChart;

	private slots:
		//频率表中频率选中的槽函数
        void on_TableSelectFreq(int iIndex,double dFreq);
signals:
		//频率选中信号。
		void SelectFreq(int iIndex,double dFreq);
};

#endif // MYFREQSETWIDGET_H
