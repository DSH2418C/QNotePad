#ifndef QNOTEPAD_H
#define QNOTEPAD_H

#include <QMainWindow>
#include <QLabel>
#include <QPlainTextEdit>

class QNotePad : public QMainWindow
{
    Q_OBJECT

private:
    QLabel m_statusLabel;
    QPlainTextEdit m_mainEditor;

    QNotePad();
    QNotePad(const QNotePad&);
    QNotePad& operator = (const QNotePad&);

    bool construct();

    bool initMenuBar();
    bool initToolBar();
    bool initStatusBar();
    bool initMainEditor();
    bool initFileMenu(QMenuBar* mb);
    bool initEditMenu(QMenuBar* mb);
    bool initFormatMenu(QMenuBar* mb);
    bool initViewMenu(QMenuBar* mb);
    bool initHelpMenu(QMenuBar* mb);
    bool initFileToolItem(QToolBar* tb);
    bool initEditToolItem(QToolBar* tb);
    bool initFormatToolItem(QToolBar* tb);
    bool initViewToolItem(QToolBar* tb);
    bool makeAction(QAction*& action, QString text, int key, QWidget* parent);
    bool makeAction(QAction*& action, QString tip, QString iconPath, QWidget* parent);

public:
    static QNotePad* NewInstance();
    ~QNotePad();
};

#endif // QNOTEPAD_H


