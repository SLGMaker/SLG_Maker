#include "GameUnit.h"
#include "GameLayerSquare.h"

using namespace std;


//////////////////////////////��������������//////////////////////////////
GameUnit::GameUnit()
{
}

GameUnit::GameUnit(GameLayerSquare* _parent)
{
	parent = _parent;
}

GameUnit::~GameUnit()
{
}


//////////////////////////////�����������//////////////////////////////
GameUnit::Pos GameUnit::Position()
{
	return position;
}

int GameUnit::ChangePosition(int x, int y)
{
	position.x = x;
	position.y = y;
	return 0;
}

int GameUnit::ChangePosition(Pos newPos)
{
	position = newPos;
	return 0;
}

/*
* @brief ���ø�����
* @param _parent:Ҫ����Ϊ�������ָ��
* @return 0:���óɹ� 1:����ʧ��
*/
int GameUnit::SetParent(GameLayerSquare* _parent)
{
	parent = _parent;
	return 0;
}
