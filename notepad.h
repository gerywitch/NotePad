#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Notepad;
}
QT_END_NAMESPACE

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    Notepad(QWidget *parent = nullptr);
    ~Notepad();
private slots:
      void newDocument();
      void save();

private:
    Ui::Notepad *ui;
    QString currentFile;
//! [6]
};
#endif // NOTEPAD_H
