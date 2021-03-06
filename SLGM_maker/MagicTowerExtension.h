#ifndef MAGICTOWEREXTENSION_H
#define MAGICTOWEREXTENSION_H

#include <QGraphicsObject>
#include "SLGMEditorScene.h"
class MagicTowerExtension : public QGraphicsObject
{
    Q_OBJECT
protected:
    SLGMEditorScene* magicTowerScene;
public:
    //构造函数，将扩展对象与场景相关联。
    explicit MagicTowerExtension(SLGMEditorScene* scene);

    //简单实现QGraphicsObject类的两个纯虚函数
    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
    virtual QRectF boundingRect() const;
signals:

public slots:

};

#endif // MAGICTOWEREXTENSION_H
