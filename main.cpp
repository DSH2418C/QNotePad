#include "QNotePad.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    int ret = -1;
    QApplication a(argc, argv);

    QNotePad* notePad = QNotePad::NewInstance();

    if( notePad != NULL )
    {
        notePad->show();

        ret = a.exec();
    }

    delete notePad;

    return ret;
}

