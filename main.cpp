#include "notepad.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Notepad edit;
    edit.show();
    return a.exec();
}
