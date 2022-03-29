#include "noteView.h"
#include "ui_noteView.h"

NoteView::NoteView(QWidget *parent) : QMainWindow(parent), ui(new Ui::NoteView) {
    ui->setupUi(this);
    setCentralWidget(ui->textEdit);
}

NoteView::~NoteView() {
    delete ui;
}

void NoteView::on_actionNew_triggered() {
    currentFile.clear();
    ui->textEdit->setText(QString());
}


void NoteView::on_actionOpen_triggered() {
    QString fileName = QFileDialog::getOpenFileName(this, ("Open the file"), QDir::homePath());
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void NoteView::on_actionSave_as_triggered() {
    QString fileName = QFileDialog::getSaveFileName(this, ("Save as"), QDir::homePath());
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot save file : " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}


void NoteView::on_actionExit_triggered() {
    QApplication::quit();
}


void NoteView::on_actionCopy_triggered() {
    ui->textEdit->copy();
}


void NoteView::on_actionPaste_triggered() {
    ui->textEdit->paste();
}


void NoteView::on_actionCut_triggered() {
    ui->textEdit->cut();
}


void NoteView::on_actionUndo_triggered() {
    ui->textEdit->undo();
}


void NoteView::on_actionRedo_triggered() {
    ui->textEdit->redo();
}

void NoteView::on_actionType_font_triggered() {
    bool check;
    QFont font = QFontDialog::getFont(&check,this);
    if (check) {
        ui->textEdit->setFontFamily(font.family());
        ui->textEdit->setFontPointSize(font.pointSize());
    }
}

void NoteView::on_actionBold_font_triggered() {
    if (ui->textEdit->fontWeight() == QFont::Normal) {
        ui->textEdit->setFontWeight(QFont::Bold);
    } else {
        ui->textEdit->setFontWeight(QFont::Normal);
    }
}

void NoteView::on_actionItalic_triggered(){
    if (ui->textEdit->fontItalic()) {
        ui->textEdit->setFontItalic(false);
    } else {
        ui->textEdit->setFontItalic(true);
    }
}

