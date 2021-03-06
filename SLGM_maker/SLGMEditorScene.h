#ifndef MAGICTOWERSCENE_H
#define MAGICTOWERSCENE_H

#include <QGraphicsScene>
#include <QMap>
#include <QGraphicsView>

class QString;
class SLGCGameUnit;
class MagicTowerCharacter;
class MagicTowerExtension;
class SLGMObjectSelector;
class SLGMMainWindow;
class CharacterPropertyExtension;
class SLGCGameMap;
class SLGCGame;

class SLGMEditorScene : public QGraphicsScene
{
	Q_OBJECT
public:
	SLGCGame* game;
protected:
    /**
     * @brief parentWidget，MagicTowerScene创建时为自己创建的用于呈现自己的QGraphicsView对象
     */
    QGraphicsView* parentWidget;

    /**
     * @brief activeCharacter表示魔塔当前的“活动”（受操纵的）人物。
     */
    MagicTowerCharacter* activeCharacter;
    /**
     * @brief magicTowerExtensions存储了魔塔中所有的扩展对象。扩展对象的特点在于可以摆脱网格状结构存储的限制，
     * 获得键盘焦点，从而实现更多更复杂的功能。
     */
    QMap<QString, MagicTowerExtension*> magicTowerExtensions;

    /**
     * @brief activeMap记录了当前魔塔的活动地图（楼层），这在切换楼层时格外的有用。
     */
    QString activeMap;
public:
	QString currentCursorObject;
	SLGMMainWindow* mainWindow;
public:
    /**
     * @brief 重置场景
     */
    void reset();

    /**
     * @brief 获取游戏主窗口
     * @return 指向游戏主窗口的指针
     */
    QGraphicsView* getParentWidget() ;

    //设置当前的活动地图
    bool setActiveMap(const QString& map);

    template<class ExtType>
    bool addExtension(const QString& name)
    {
		//if(magicTowerExtensions.find(name)!=magicTowerExtensions.end()) return false;
		//magicTowerExtensions.insert(name, new ExtType(this));
		return false;
    }

    template<class ExtType>
    ExtType* getExtension(const QString& name)
    {
		return NULL;
		//return dynamic_cast<ExtType*>(magicTowerExtensions[name]);
    }

    /**
     * @brief setActiveCharacter设置一个“活动人物”，地图中的视角将根据活动人物进行调整。
     * 事实上，目前魔塔里只有一个人物，这一函数的意义在于初始化方便跟踪人物的位置。
     * @param activeCharacter魔塔中的活动人物
     * @return 设置活动人物是否成功
     */
    bool setActiveCharacter(MagicTowerCharacter* activeCharacter);

    /**
     * @brief getActiveCharacter获取当前的活动人物。
     * @return 当前的活动人物，可能为NULL。
     */
    MagicTowerCharacter* getActiveCharacter();

	SLGCGameUnit* setObjectAt(const QString& map, const QString& layer, int x, int y, SLGCGameUnit* obj, bool release = true);
protected:
    //鼠标移动事件，用于覆盖基类避免焦点对象被意外改变
    void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent );
public:
	SLGMEditorScene(QObject* parent = 0);
public slots:
	void onUnitAdded(SLGCGameUnit* unit);
};

#endif // MAGICTOWERSCENE_H
