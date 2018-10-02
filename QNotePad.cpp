#include "QNotePad.h"

#include <QMenu>
#include<QMenuBar>
#include <QToolBar>
#include <QStatusBar>

#include <QDebug>


//对象创建函数[静态]
QNotePad* QNotePad::NewInstance()
{
    QNotePad* ret = new QNotePad();

    if( (ret == nullptr) || !(ret->construct()) )
    {
        delete ret;
        ret = nullptr;
    }

    return ret;
}


QNotePad::QNotePad()
    :m_mainEditor(this)
{}


//二阶构造
bool QNotePad::construct()
{
    bool ret = true;

    ret = ret && initMenuBar();
    ret = ret && initToolBar();
    ret = ret && initStatusBar();
    ret = ret && initMainEditor();

    return ret;
}


// 创建菜单栏
bool QNotePad::initMenuBar()
{
    bool ret = true;

    // 此方式 mb 父类必为 this
    QMenuBar* mb = menuBar();

    ret = ret && initFileMenu(mb);
    ret = ret && initEditMenu(mb);
    ret = ret && initFormatMenu(mb);
    ret = ret && initViewMenu(mb);
    ret = ret && initHelpMenu(mb);

    return ret;
}


// 创建工具栏
bool QNotePad::initToolBar()
{
    bool  ret = true;

    // 创建ToolBar并插入工具栏区域
    QToolBar* tb = addToolBar("Tool Bar");

    tb->setIconSize(QSize(16, 16));

    ret = ret && initFileToolItem(tb);
    tb->addSeparator();

    ret = ret && initEditToolItem(tb);
    tb->addSeparator();

    ret = ret && initFormatToolItem(tb);
    tb->addSeparator();

    return ret;
}


// 创建状态栏
bool QNotePad::initStatusBar()
{
    bool ret = true;

    QStatusBar* sb = statusBar();

    QLabel* label = new QLabel("HSD");

    if( label != NULL )
    {
        m_statusLabel.setMinimumWidth(180);
        m_statusLabel.setAlignment(Qt::AlignCenter);
        m_statusLabel.setText("Ln: 1  Col: 1");

        label->setMinimumWidth(180);
        label->setAlignment(Qt::AlignCenter);

        sb->addPermanentWidget(&m_statusLabel);
        sb->addPermanentWidget(label);
    }
    else
    {
        ret = false;
    }

    return ret;
}


// 创建文本编辑组件
bool QNotePad::initMainEditor()
{
    bool ret = true;

    setCentralWidget(&m_mainEditor);

    return ret;
}


// file下拉菜单
bool QNotePad::initFileMenu(QMenuBar* mb)
{
    QMenu* menu = new QMenu("File(&F)", mb);

    bool ret = (menu != NULL);

    if( ret )
    {
        QAction* action = nullptr;

        ret = ret && makeAction(action, "New(&N)", Qt::CTRL + Qt::Key_N, menu);
        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && makeAction(action, "Open(&O)...", Qt::CTRL + Qt::Key_O, menu);
        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && makeAction(action, "Save(&S)", Qt::CTRL + Qt::Key_S, menu);
        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && makeAction(action, "Save As(&A)...", Qt::CTRL + Qt::Key_A, menu);
        if( ret )
        {
            menu->addAction(action);
        }

        menu->addSeparator(); // 分隔符

        ret = ret && makeAction(action, "Print(&P)...", Qt::CTRL + Qt::Key_P, menu);
        if( ret )
        {
            menu->addAction(action);
        }

        menu->addSeparator();

        ret = ret && makeAction(action, "Exit(&X)", 0, menu);
        if( ret )
        {
            menu->addAction(action);
        }
    }

    if( ret )
    {
        mb->addMenu(menu);
    }
    else
    {
        delete menu;
    }

    return ret;
}


// Edit下拉菜单
bool QNotePad::initEditMenu(QMenuBar* mb)
{
    QMenu* menu = new QMenu("Edit(&E)", mb);

    bool ret = (menu != nullptr);

    if( ret )
    {
        QAction* action = nullptr;

        ret = ret && makeAction(action, "Undo(&U)", Qt::CTRL + Qt::Key_Z, menu);
        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && makeAction(action, "Redo(&R)...", Qt::CTRL + Qt::Key_Y, menu);
        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && makeAction(action, "Cut(&T)", Qt::CTRL + Qt::Key_X, menu);
        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && makeAction(action, "Copy(&C)...", Qt::CTRL + Qt::Key_C, menu);
        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && makeAction(action, "Paste(&P)...", Qt::CTRL + Qt::Key_V, menu);
        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && makeAction(action, "Delete(&L)", Qt::CTRL + Qt::Key_Delete, menu);
        if( ret )
        {
            menu->addAction(action);
        }

        menu->addSeparator();

        ret = ret && makeAction(action, "Find(&F)...", Qt::CTRL + Qt::Key_F, menu);
        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && makeAction(action, "Replace(&R)...", Qt::CTRL + Qt::Key_H, menu);
        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && makeAction(action, "Goto(&G)...", Qt::CTRL + Qt::Key_G, menu);
        if( ret )
        {
            menu->addAction(action);
        }

        menu->addSeparator();

        ret = ret && makeAction(action, "Select All(&A)", Qt::CTRL + Qt::Key_A, menu);
        if( ret )
        {
            menu->addAction(action);
        }
    }

    if( ret )
    {
        mb->addMenu(menu);
    }
    else
    {
        delete menu;
    }

    return ret;
}


// Format下拉菜单
bool QNotePad::initFormatMenu(QMenuBar* mb)
{
    QMenu* menu = new QMenu("Format(&O)", mb);

    bool ret = (menu != nullptr);

    if( ret )
    {
        QAction* action = nullptr;

        ret = ret && makeAction(action, "Auto Wrap(&W)", 0, menu);
        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && makeAction(action, "Font(&F)...", 0, menu);
        if( ret )
        {
            menu->addAction(action);
        }
    }

    if( ret )
    {
        mb->addMenu(menu);
    }
    else
    {
        delete menu;
    }

    return ret;
}


// View下拉菜单
bool QNotePad::initViewMenu(QMenuBar* mb)
{
    QMenu* menu = new QMenu("View(&V)", mb);

    bool ret = (menu != nullptr);

    if( ret )
    {
        QAction* action = nullptr;

        ret = ret && makeAction(action, "Tool Bar(&T)", 0, menu);
        if( ret )
        {
            menu->addAction(action);
        }

        ret = ret && makeAction(action, "Status Bar(&S)", 0, menu);
        if( ret )
        {
            menu->addAction(action);
        }
    }

    if( ret )
    {
        mb->addMenu(menu);
    }
    else
    {
        delete menu;
    }

    return ret;
}


// Help 下拉菜单
bool QNotePad::initHelpMenu(QMenuBar* mb)
{
    QMenu* menu = new QMenu("Help(&H)", mb);

    bool ret = (menu != nullptr);

    if( ret )
    {
       QAction* action = nullptr;

       ret = ret && makeAction(action, "User Manual", 0, menu);
       if( ret )
       {
           menu->addAction(action);
       }

       ret = ret && makeAction(action, "About NotePad...", 0, menu);
       if( ret )
       {
           menu->addAction(action);
       }
    }

    if( ret )
    {
       mb->addMenu(menu);
    }
    else
    {
       delete menu;
    }

    return ret;
}


// file类快捷工具
bool QNotePad::initFileToolItem(QToolBar* tb)
{
    bool ret = true;

    QAction* action = nullptr;

    ret = ret && makeAction(action, "New", ":/ico/new.png", tb);
    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Open", ":/ico/open.png", tb);
    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Save", ":/ico/save.png", tb);
    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Save As", ":/ico/saveas.png", tb);
    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Print", ":/ico/print.png", tb);
    if( ret )
    {
        tb->addAction(action);
    }

    return ret;
}


// edit类快捷工具
bool QNotePad::initEditToolItem(QToolBar* tb)
{
    bool ret = true;

    QAction* action = nullptr;

    ret = ret && makeAction(action, "Undo", ":/ico/undo.png", tb);
    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Redo", ":/ico/redo.png", tb);
    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Cut", ":/ico/cut.png", tb);
    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Copy", ":/ico/copy.png", tb);
    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Paste", ":/ico/paste.png", tb);
    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Find", ":/ico/find.png", tb);
    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Replace", ":/ico/replace.png", tb);
    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Goto", ":/ico/goto.png", tb);
    if( ret )
    {
        tb->addAction(action);
    }

    return ret;
}


// forma类快捷工具
bool QNotePad::initFormatToolItem(QToolBar* tb)
{
    bool ret = true;

    QAction* action = NULL;

    ret = ret && makeAction(action, "Auto Wrap", ":/ico/wrap.png", tb);
    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Font", ":/ico/font.png", tb);
    if( ret )
    {
        tb->addAction(action);
    }

    return ret;
}


// view类快捷工具
bool QNotePad::initViewToolItem(QToolBar* tb)
{
    bool ret = true;

    QAction* action = NULL;

    ret = ret && makeAction(action, "Tool Bar", ":/ico/tool.png", tb);
    if( ret )
    {
        tb->addAction(action);
    }

    ret = ret && makeAction(action, "Status Bar", ":/ico/status.png", tb);
    if( ret )
    {
        tb->addAction(action);
    }

    return ret;
}


// 创建菜单项
bool QNotePad::makeAction(QAction*& action, QString text, int key, QWidget* parent)
{
    action = new QAction(text, parent);

    bool ret = (action != nullptr);

    if( ret )
    {
        // 设置快捷键
        action->setShortcut(QKeySequence(key));
    }

    return ret;
}


// 创建快捷项
bool QNotePad::makeAction(QAction*& action, QString tip, QString iconPath, QWidget* parent)
{
    bool ret = true;

    action = new QAction("", parent);

    ret = (action != nullptr);

    if( action )
    {
        action->setToolTip(tip);
        action->setIcon(QIcon(iconPath));
    }

    return ret;
}


QNotePad::~QNotePad()
{}
