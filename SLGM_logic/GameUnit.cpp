#include "GameUnit.h"

using namespace std;


//////////////////////////////��������������//////////////////////////////
GameUnit::GameUnit()
{
}

GameUnit::GameUnit(GameLayerSquare* _parent, string _UnitName, int x, int y)
{
	parent = _parent;

	string UnitFile = _UnitName + ".lua";
	AddProperty("UnitName", _UnitName);

	lua_State* LS = luaL_newstate();
	int a = luaL_loadfile(LS, UnitFile.c_str());
	lua_pcall(LS,0,0,0);

	lua_pushglobaltable(LS);
	int nIndex = lua_gettop(LS);
	lua_pushnil(LS);
	while (lua_next(LS, nIndex))
	{
		bool flag = false;
		if (lua_istable(LS,-1))
		{
		}

		
		
		if (lua_isnumber(LS,-1))
		{
			string ts = lua_tostring(LS, -2);
			double td = lua_tonumber(LS,-1);
			if (td == int(td))
			{
				AddProperty(ts, int(td));
			}
			else
			{
				AddProperty(ts, td);
			}
		//	cout << "number:" << lua_tostring(LS, -2) << "=" << lua_tonumber(LS, -1) << endl;
		}
		else
		{
			if (lua_isstring(LS,-1))
			{
				AddProperty(lua_tostring(LS, -2), lua_tostring(LS, -1));
				flag = true;
			}
		}
		
		if (lua_isfunction(LS,-1))
		{
		}

		lua_pop(LS,1);
	}
	lua_pop(LS,1);


	position.x = x;
	position.y = y;
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