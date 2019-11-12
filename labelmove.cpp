#include "labelmove.h"

LabelMove::LabelMove(QWidget *parent) : QLabel (parent)
{
    par = qobject_cast<QWidget*>(parent);
}

void LabelMove::mousePressEvent(QMouseEvent *event)
{
    startPos = event->globalPos();//获取点击鼠标时的全局坐标
    startPos1 = event->pos();//获取点击鼠标的相对mainwindow的坐标
}

void LabelMove::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        QPoint movePos = event->globalPos() - startPos;//计算鼠标移动位置
        if( movePos.manhattanLength() > 4)//判断移动像素距离，防抖动
            this->par->move(event->globalPos() - startPos1);
        return;
    }
}

void LabelMove::mouseReleaseEvent(QMouseEvent *event)
{
    event->accept();
}
