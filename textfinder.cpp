#include "textfinder.h"
#include "ui_textfinder.h"

TextFinder::TextFinder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TextFinder)
{
    ui->setupUi(this);
}

TextFinder::~TextFinder()
{
    delete ui;
}

void TextFinder::on_findButton_clicked()
{

}

void loadTextFile()
{
    QFile inputFile(":/input.txt");
    inputFile.open(QIODevice::ReadOnly);

    QTextStream in(&inputFile);
    QString line = in.readAll();
    inputFile.close();

    ui->textEdit->setPlainText(line);
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}
