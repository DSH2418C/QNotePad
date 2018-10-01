#include "QNotePad.h"

#include <QMenu>
#include<QMenuBar>

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
{}


//二阶构造
bool QNotePad::construct()
{
    bool ret = true;

    ret = ret && initMenuBar();

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


// 创建菜单项
bool QNotePad::makeAction(QAction*& action, QString text, int key, QWidget* parent)
{
    bool ret = true;

    action = new QAction(text, parent);

    if( action != nullptr )
    {
        // 设置快捷键
        action->setShortcut(QKeySequence(key));
    }
    else
    {
        ret = false;
    }

    return ret;
}


QNotePad::~QNotePad()
{}
