#ifndef __GUI_HPP__
#define __GUI_HPP__

#include <QtWidgets/QMainWindow>

#include <QAction>
#include <QComboBox>
#include <QFrame>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QStatusBar>
#include <QTextEdit>
#include <QWidget>

class gui : public QMainWindow
{
	Q_OBJECT

public:
	gui(QWidget *parent = Q_NULLPTR);
	~gui();

private:

	void createWidgets();
	void createActions();
	void createMenus();
	void createLayouts();

	QFrame *baseFrame;
	QFrame *leftFrame;
	QFrame *rightFrame;
	  
	QLabel *transmitLabel;
	QLineEdit *transmitLineEdit;
	QLabel *receiveLabel;
	QTextEdit *receiveTextEdit;

	QPushButton *transmitButton;

	QLabel *portLabel;
	QComboBox *portCombo;
	QLabel *baudRateLabel;
	QComboBox *baudRateCombo;
	QLabel *dataSizeLabel;
	QComboBox *dataSizeCombo;
	QLabel *parityLabel;
	QComboBox *parityCombo;
	QLabel *stopBitsLabel;
	QComboBox *stopBitsCombo;

	QAction *quitAction;
	
	QMenu *fileMenu;

	QHBoxLayout *baseLayout;
	QVBoxLayout *leftLayout;
	QVBoxLayout *rightLayout;

public slots:

	void slot_updateCOMPorts(void*);

private slots:
	
	void slot_transmitButtonClicked();

	void slot_quit();

signals:

	void sig_getCOMPorts();

	void sig_transmit(const QString&);
	
	void sig_quit();

};

#endif // !__GUI_HPP__