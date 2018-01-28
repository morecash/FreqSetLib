/*Ƶ�ʼ���ͼ�ࡣ
* 
* �����ߣ�  �¶���
* ����ʱ�䣺2018��1����XX��Ԣ�����ϴ���GitHub��
* δ����������ɣ�����ʹ�ã��������Ը���
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
	//������ͼ��
	void CreateRect(QRect  rect);
	//ˢ�»�ͼ��
	void Refresh(QPainter* pPainter);
	//���ƻ�ͼ��
	void Draw();
    //ɾ��һ��Ƶ�ʺ������ͼһ��
	void  RemoveFreq(double dFreq);
	//����һ��Ƶ�ʺ������ͼһ��
	void  InsertFreq(int iRow,double dFreq);
	//ѡ��һ�����꣬����Ƶ�ʼ����ѡ�е�һ��
	void  PressPos(int xPos);
	//��Ƶ�ʼ�������ͻ�ͼ��
	void  AttachMyFreqsetWidget(MyFreqsetWidget*  pMyFreqsetWidget);
    //Ƶ�ʼ����ѡ��Ƶ�ʺ������ͼ��һ��
	void  SelectFreq(int iIndex,double dFreq);

    //��ʼ����̨����
	void  ResetNet();
		
	/*�����̨��Ϣ.
    @param startFreq��ʾ��ʼƵ�ʡ���λMHz
	@param sEndFreq��ʾ��ֹƵ�ʡ���λMHz
	@param sFreqCount��ʾ��������λMHz
	@param sHopCycle��ʾ��Ƶ���ڡ���λ����
	@param sLevel��ʾ��ƽ����λdB
	@param sFreqSets��ʾƵ�ʼ���Ƶ�ʼ��ö��ŷָ���Ƶ�ʵ�λMHz��
	@param sUUID��ʾ��̨��Ψһ�Ա�ǣ���Ϊ�գ���ʾû�б�ǡ�
	*/
	void  AddOneNet(QString startFreq,QString sEndFreq,QString sFreqCount,QString sHopCycle,QString sLevel,QString sFreqSets,QString sReserved);

private:
	QString  m_sFreq;      //ѡ�е��Ƶ��  Ϊ�ձ�ʾû��ѡ��
	int      m_iPressPos;  //ѡ�е��Ӧ��X����
	QRect  m_Rect;
	QPixmap  m_Pixmap;     //����
	short      m_iAmp;     //��̨��ƽ����ƽ

	double  m_dStartFreq;  //
	double  m_dEndfreq;
	double  m_iFreqCount;
	FreqDrawData*  m_pDrawData;
	QList<FreqDrawData> m_List;

	FreqPos  m_FreqPos[1048];        //���1024����

	MyFreqsetWidget*  m_pMyFreqsetWidget;
};
