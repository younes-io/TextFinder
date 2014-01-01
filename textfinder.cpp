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

void TextFinder::on_lineEdit_textEdited(const QString &arg1)
{
    this->searchTheWord();
}


void TextFinder::searchTheWord()
{
    QString searchString = ui->lineEdit->text();
//    ui->textEdit->find(searchString, QTextDocument::FindWholeWords);

    QList<QTextEdit::ExtraSelection> extraSelections;

    ui->textEdit->moveCursor(QTextCursor::Start);
    QColor color = QColor(Qt::gray).lighter(130);

    int numberOccurrences = 0;
    while(ui->textEdit->find(searchString))
    {
        numberOccurrences++;

        QTextEdit::ExtraSelection extra;
        extra.format.setBackground(color);

        extra.cursor = ui->textEdit->textCursor();
        extraSelections.append(extra);
    }

    ui->textEdit->setExtraSelections(extraSelections);
    QString num = QString::number(numberOccurrences);

    ui->numberOccurrencesLabel->setText(num);
}

void TextFinder::moveCursorToStart()
{
    QTextCursor cursor = ui->textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
    ui->textEdit->setTextCursor(cursor);
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
