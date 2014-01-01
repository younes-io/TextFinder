#ifndef TEXTFINDER_H
#define TEXTFINDER_H

#include <QWidget>

namespace Ui {
class TextFinder;
}

class TextFinder : public QWidget
{
    Q_OBJECT

public:
    explicit TextFinder(QWidget *parent = 0);
    ~TextFinder();

private slots:
    void on_findButton_clicked();
    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::TextFinder *ui;
    void loadTextFile();
    void searchTheWord();
    void moveCursorToStart();
};

#endif // TEXTFINDER_H
