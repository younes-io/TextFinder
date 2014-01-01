#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include <QtCore/QIODevice>
#include "textfinder.h"
#include "ui_textfinder.h"

TextFinder::TextFinder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TextFinder)
{
    ui->setupUi(this);
    loadTextFile();
}

TextFinder::~TextFinder()
{
    delete ui;
}

void TextFinder::searchTheWord()
{
    QString searchString = ui->lineEdit->text();
    ui->textEdit->find(searchString, QTextDocument::FindWholeWords);
}

void TextFinder::moveCursorToStart()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
}

void TextFinder::on_findButton_clicked()
{
    this->searchTheWord();
}

void TextFinder::loadTextFile()
{
    QFile inputFile("input.txt");
    inputFile.open(QIODevice::ReadOnly);

    QTextStream in(&inputFile);
    QString line = in.readAll();
    inputFile.close();

    ui->textEdit->setPlainText(line);
    this->moveCursorToStart();
}

void TextFinder::on_lineEdit_textEdited(const QString &arg1)
{
    this->moveCursorToStart();
    this->searchTheWord();
}
