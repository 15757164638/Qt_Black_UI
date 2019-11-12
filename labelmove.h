#ifndef LABELMOVE_H
#define LABELMOVE_H

#include <QObject>
#include <QLabel>
#include <QMouseEvent>

/**
 * @brief The LabelMove class
 * 功能：通过鼠标事件移动标签的父窗口
 */

class LabelMove : public QLabel
{
public:
    explicit LabelMove(QWidget *parent = nullptr);
private:
    //鼠标点击时全局位置
    QPoint startPos;
    //鼠标点击时相对位置
    QPoint startPos1;
    //父对象
    QWidget *par;
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // LABELMOVE_H
