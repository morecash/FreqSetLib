/*频率集绘图类。
* 
* 创建者：  陈鼎才
* 创建时间：2018年1月于XX公寓。并上传到GitHub。
* 未经创建者许可，请勿使用，否则后果自负。
*/


#pragma once

#include <QRect>
#include <QPainter>
#include <QPixmap>
#include "FreqDrawDataHeader.h"


class  MyFreqsetWidget;
class CMyFreqsetChart
{
public:
	CMyFreqsetChart(void);
	~CMyFreqsetChart(void);

public:
	//创建绘图区
	void CreateRect(QRect  rect);
	//刷新绘图区
	void Refresh(QPainter* pPainter);
	//绘制绘图区
	void Draw();
    //删除一个频率后请求绘图一致
	void  RemoveFreq(double dFreq);
	//插入一个频率后请求绘图一致
	void  InsertFreq(int iRow,double dFreq);
	//选中一个坐标，请求频率集表格选中的一致
	void  PressPos(int xPos);
	//绑定频率集管理类和绘图类
	void  AttachMyFreqsetWidget(MyFreqsetWidget*  pMyFreqsetWidget);
    //频率集表格选中频率后，请求绘图区一致
	void  SelectFreq(int iIndex,double dFreq);

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
	void  AddOneNet(QString startFreq,QString sEndFreq,QString sFreqCount,QString sHopCycle,QString sLevel,QString sFreqSets,QString sReserved);

private:
	QString  m_sFreq;      //选中点的频率  为空表示没有选中
	int      m_iPressPos;  //选中点对应的X坐标
	QRect  m_Rect;
	QPixmap  m_Pixmap;     //画布
	short      m_iAmp;     //网台的平均电平

	double  m_dStartFreq;  //
	double  m_dEndfreq;
	double  m_iFreqCount;
	FreqDrawData*  m_pDrawData;
	QList<FreqDrawData> m_List;

	FreqPos  m_FreqPos[1048];        //最多1024个。

	MyFreqsetWidget*  m_pMyFreqsetWidget;
};
