/*Ƶ�ʼ���ͼ����ĸ�崰���ࡣ
* 
* �����ߣ�  �¶���
* ����ʱ�䣺2018��1���ڻ���Ԣ�����ϴ���GitHub��
* δ����������ɣ�����ʹ�ã��������Ը���
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
	//���캯��
	MyFreqsetWidget(QWidget *parent=0);
	//��������
	~MyFreqsetWidget();
	//ɾ��һ��Ƶ��
	void  RemoveFreq(double dFreq);
	//ѡ��һ��Ƶ��
    void  PressFreq(int iIndex,double dFreq);
	//����һ��Ƶ��
	void   InsertFreq(int iRow,double dFreq);
    //��̨��ʼ��
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

protected:
	void resizeEvent(QResizeEvent* event);  
	void  paintEvent(QPaintEvent *event);
	void  mousePressEvent(QMouseEvent *event);
private:
	//Ƶ�ʼ���ͼ��
	CMyFreqsetChart*  m_pMyFreqsetChart;

	private slots:
		//Ƶ�ʱ���Ƶ��ѡ�еĲۺ���
        void on_TableSelectFreq(int iIndex,double dFreq);
signals:
		//Ƶ��ѡ���źš�
		void SelectFreq(int iIndex,double dFreq);
};

#endif // MYFREQSETWIDGET_H
