#include "main.hpp"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	gui w;

	QThread *serialThread = new QThread();

	Serial *serialTasks = new Serial();

	serialTasks->moveToThread(serialThread);

	QObject::connect(serialThread, SIGNAL(started()), serialTasks, SLOT(slot_getCOMPorts()));

	QObject::connect(serialTasks, SIGNAL(sig_updateCOMPorts(void*)), &w, SLOT(slot_updateCOMPorts(void*)));

	QObject::connect(&w, SIGNAL(sig_transmit(const QString&)), serialTasks, SLOT(slot_transmit(const QString&)));

	QObject::connect(&w, SIGNAL(sig_quit()), &a, SLOT(quit()));
	
	serialThread->start();

	w.show();

	return a.exec();
}
