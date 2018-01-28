<<<<<<< HEAD
#ifndef TESTNETSHOW_H
#define TESTNETSHOW_H

#include <QtGui/QMainWindow>
#include "ui_testnetshow.h"

#include "..\NetShowLib\FreqsetsWidget.h"

class TestNetShow : public QMainWindow
{
	Q_OBJECT

public:
	TestNetShow(QWidget *parent = 0, Qt::WFlags flags = 0);
	~TestNetShow();

private:
	Ui::TestNetShowClass ui;

	FreqsetsWidget*   m_pFreqsetsWidget;

	QMenu*   m_pMenu;
	QAction*  m_pAddAct;
	QAction*  m_pSpaceAct;

	private slots:
		void  onAdd();
		void  onSpaceAct();

		void OnNetSignal(QString startFreq,QString sEndFreq,QString sFreqCount,QString sHopCycle,QString sLevel,QString sFreqSets,QString sUUID);

};

#endif // TESTNETSHOW_H
=======
#ifndef TESTNETSHOW_H
#define TESTNETSHOW_H

#include <QtGui/QMainWindow>
#include "ui_testnetshow.h"

#include "..\NetShowLib\FreqsetsWidget.h"

class TestNetShow : public QMainWindow
{
	Q_OBJECT

public:
	TestNetShow(QWidget *parent = 0, Qt::WFlags flags = 0);
	~TestNetShow();

private:
	Ui::TestNetShowClass ui;

	FreqsetsWidget*   m_pFreqsetsWidget;

	QMenu*   m_pMenu;
	QAction*  m_pAddAct;
	QAction*  m_pSpaceAct;

	private slots:
		void  onAdd();
		void  onSpaceAct();

		void OnNetSignal(QString startFreq,QString sEndFreq,QString sFreqCount,QString sHopCycle,QString sLevel,QString sFreqSets,QString sUUID);

};

#endif // TESTNETSHOW_H
>>>>>>> origin/master
