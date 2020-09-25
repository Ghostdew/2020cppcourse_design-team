#ifndef CHOOSELEVELWINDOW_H
#define CHOOSELEVELWINDOW_H

#include <QMainWindow>
#include "playwindow.h"

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
    playwindow *play = nullptr;

signals:
    void ChooseLevelWindowBack();
};

#endif // CHOOSELEVELWINDOW_H
