/*��ͼ���ݽṹ�塣����ͼ��ʱ���ݽӿڲ������̶ֹ�ʽ�Ľṹ�塣
* 
* �����ߣ�  �¶���
* ����ʱ�䣺2017��07��22���ڻ���Ԣ
*/


#ifndef FreqDrawDataHeader_H
#define FreqDrawDataHeader_H

struct  FreqDrawData
{
	short   m_Amp;        //����
	double  m_dFreq;      //Ƶ��
	FreqDrawData()
	{
		m_Amp =0;
		m_dFreq = 0;
	}
};


struct  FreqPos
{
	short   m_iPos;       //X������
	double  m_dFreq;      //Ƶ��
	FreqPos()
	{
		m_iPos =0;
		m_dFreq = 0;
	}
};











#endif