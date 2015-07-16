#ifndef _GAME_UNIT_H_
#define _GAME_UNIT_H_

#include <string>
#include <map>
#include "GameEvent.h"
#include "GameBase.h"
#include "GameLayerSquare.h"
#include "lua.hpp"

using namespace std;

class GameUnit : public GameBase
{
	struct Pos
	{
		int x;
		int y;
	};
private:
	Pos position;
	GameLayerSquare* parent;
public:
	GameUnit();
	GameUnit(string _UnitName, int x, int y);
	GameUnit(GameLayerSquare* _parent);
	~GameUnit();

	Pos Position();
	int ChangePosition(int x, int y);
	int ChangePosition(Pos newPos);

	/*
	* @brief ���ø�����
	* @param _parent:Ҫ����Ϊ�������ָ��
	* @return 0:���óɹ� 1:����ʧ��
	*/
	int SetParent(GameLayerSquare* _parent);
};



#endif