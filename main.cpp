/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 04-03-2017
///		Date update	: 04-03-2017
///		Comment		:
/// ============================================================================
#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    cfmc::monitoring::main_window w;
    w.show();

    return a.exec();
}
