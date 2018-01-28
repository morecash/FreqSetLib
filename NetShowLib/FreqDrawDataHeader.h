/*绘图数据结构体。绘制图形时数据接口采用这种固定式的结构体。
* 
* 创建者：  陈鼎才
* 创建时间：2017年07月22日于皇马公寓
*/


#ifndef FreqDrawDataHeader_H
#define FreqDrawDataHeader_H

struct  FreqDrawData
{
	short   m_Amp;        //幅度
	double  m_dFreq;      //频率
	FreqDrawData()
	{
		m_Amp =0;
		m_dFreq = 0;
	}
};


struct  FreqPos
{
	short   m_iPos;       //X轴坐标
	double  m_dFreq;      //频率
	FreqPos()
	{
		m_iPos =0;
		m_dFreq = 0;
	}
};











#endif