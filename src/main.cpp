#include "noteView.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    NoteView w;
    w.show();
    return a.exec();
}
