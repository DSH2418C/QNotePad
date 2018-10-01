#ifndef QNOTEPAD_H
#define QNOTEPAD_H

#include <QMainWindow>

class QNotePad : public QMainWindow
{
    Q_OBJECT

private:
    QNotePad();
    QNotePad(const QNotePad&);
    QNotePad& operator = (const QNotePad&);

    bool construct();

    bool initMenuBar();
    bool initFileMenu(QMenuBar* mb);
    bool initEditMenu(QMenuBar* mb);
    bool initFormatMenu(QMenuBar* mb);
    bool initViewMenu(QMenuBar* mb);
    bool initHelpMenu(QMenuBar* mb);
    bool makeAction(QAction*& action, QString text, int key, QWidget* parent);

public:
    static QNotePad* NewInstance();
    ~QNotePad();
};

#endif // QNOTEPAD_H


