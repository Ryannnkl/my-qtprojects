#include "notepad.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication EditorApp(argc, argv);
    Notepad editor;
    editor.show();
    return EditorApp.exec();
}
