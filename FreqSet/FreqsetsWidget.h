
/*Ƶ�ʼ���ʾ�����ࡣ
* 
* �����ߣ�  �¶���
* ����ʱ�䣺2018��1����XX��Ԣ�����ϴ���GitHub��
* δ����������ɣ�����ʹ�ã��������Ը���
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
	void  AddOneNet(QString startFreq,QString sEndFreq,QString sFreqCount,QString sHopCycle,QString sLevel,QString sFreqSets,QString sUUID);


private:
	Ui::FreqsetsWidget ui;
	MyFreqsetWidget*  m_pMyFreqsetWidget;     //Ƶ�ʼ�ͼ����ʾ������
    QDoubleValidator* m_pDoubleValidator;     //double����֤��

	void  UpdateFreqset2Net();      //��Ƶ�ʼ���Ƶ�ʸ��µ���̨�б��У�ͬ�����µ�����ʼ����ֹƵ�ʣ��Լ��µ�Ƶ�ʼ���
	private slots:
		void on_pushButton_Add_clicked();      //���Ӱ�ť�ۺ���
		void on_pushButton_Delete_clicked();   //ɾ����ť�ۺ���
		void on_pushButton_InTable_clicked();  //���ť�ۺ���
		void on_cellClicked ( int row, int column );        //Ƶ�ʼ�����������ۺ���
		void OnSelectFreq(int iIndex,double dFreq);          //Ƶ�ʼ���ָ������λ��Ƶ�ʱ�ѡ�вۺ���������ͼ����ָ��Ƶ�ʱ�ѡ���¼�
		void on_AllFreqcellClicked ( int row, int column );  //��̨����������ۺ���
protected:
	
signals:
		void TableSelectFreq(int iIndex,double dFreq);    //Ƶ�ʼ���ָ������Ƶ��ѡ���¼���������ͼ����Ƶ��ѡ�вۺ�����

		/*������̨��Ϣ������źš������źŵĲۺ�����Ҫ�������
		@param startFreq��ʾ��ʼƵ�ʡ���λMHz
		@param sEndFreq��ʾ��ֹƵ�ʡ���λMHz
		@param sFreqCount��ʾ��������λMHz
		@param sHopCycle��ʾ��Ƶ���ڡ���λ����
		@param sLevel��ʾ��ƽ����λdB
		@param sFreqSets��ʾƵ�ʼ���Ƶ�ʼ��ö��ŷָ���Ƶ�ʵ�λMHz��
		@param sUUID��ʾ��̨��Ψһ�Ա�ǣ���Ϊ�գ���ʾû�б�ǡ�
		*/
		void NetSignal(QString startFreq,QString sEndFreq,QString sFreqCount,QString sHopCycle,QString sLevel,QString sFreqSets,QString sUUID);
};

#endif // FREQSETSWIDGET_H
