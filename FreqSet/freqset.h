#ifndef FREQSET_H
#define FREQSET_H

#include <QtGui/QMainWindow>
#include "ui_freqset.h"
#include "FreqsetsWidget.h"
#include <QMenu>
#include <QAction>

class FreqSet : public QMainWindow
{
	Q_OBJECT

public:
	FreqSet(QWidget *parent = 0, Qt::WFlags flags = 0);
	~FreqSet();

private:
	Ui::FreqSetClass ui;
	FreqsetsWidget*   m_pFreqsetsWidget;

	QMenu*   m_pMenu;
	QAction*  m_pAddAct;
   QAction*  m_pSpaceAct;

	private slots:
	void  onAdd();
	void  onSpaceAct();
};

#endif // FREQSET_H
