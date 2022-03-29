#ifndef NOTEVIEW_H
#define NOTEVIEW_H

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class NoteView; }
QT_END_NAMESPACE

class NoteView : public QMainWindow {
    Q_OBJECT

public:
    NoteView(QWidget *parent = nullptr);
    ~NoteView();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionType_font_triggered();

    void on_actionBold_font_triggered();

    void on_actionItalic_triggered();

private:
    Ui::NoteView *ui;
    QString currentFile;
};

#endif // NOTEVIEW_H
