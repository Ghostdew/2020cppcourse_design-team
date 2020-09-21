#ifndef CHOOSELEVELWINDOW_H
#define CHOOSELEVELWINDOW_H

#include <QMainWindow>

namespace Ui {
class ChooseLevelWindow;
}

class ChooseLevelWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChooseLevelWindow(QWidget *parent = 0);
    ~ChooseLevelWindow();

private:
    Ui::ChooseLevelWindow *ui;

signals:
    void ChooseLevelWindowBack();
};

#endif // CHOOSELEVELWINDOW_H
