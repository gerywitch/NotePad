#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printer)
#if QT_CONFIG(printdialog)
#include <QPrintDialog>
#endif // QT_CONFIG(printdialog)
#include <QPrinter>
#endif // QT_CONFIG(printer)
#endif // QT_PRINTSUPPORT_LIB
#include <QFont>
#include <QFontDialog>
#include "notepad.h"
#include "ui_notepad.h"

Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    connect(ui->actionNew, &QAction::triggered, this, &Notepad::newDocument);
    connect(ui->save,&QAction::triggered,this,&Notepad::save);
}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::newDocument()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}

void Notepad::save(){
   QString fileName=QFileDialog::getSaveFileName(this,"保存文件");
   QFile file(fileName);
   if (!file.open(QFile::WriteOnly | QFile::Text)) {
       QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
       return;
   }
   currentFile=fileName;
   setWindowTitle(currentFile);
   QTextStream out(&file);
   QString text= ui->textEdit->toPlainText();
   out<<text;
   file.close();
}

