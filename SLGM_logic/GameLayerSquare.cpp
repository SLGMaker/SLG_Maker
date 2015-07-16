#include "GameUnit.h"
#include "GameLayerSquare.h"

using namespace std;

//////////////////////////////��������������//////////////////////////////
GameLayerSquare::GameLayerSquare()
{
	nUnitNumber = 0;
}

GameLayerSquare::GameLayerSquare(GameBoardSquare* _parent)
{
	nUnitNumber = 0;
	parent = _parent;
}


//////////////////////////////�Ӷ��������//////////////////////////////
/*
* @brief ��һ�����е�λ����GameLayerSquare
*        ע�⣡���ڵ�λ(GameUnit)�����ʣ����������ɣ�����յ�λ����ͬʱ�����뵥λid���Զ�����
* @param gameLayer:Ҫ����ĵ�λ
* @return 0:�ɹ�����
*/
int GameLayerSquare::AddUnit(GameUnit* newUnit)
{
	unit[nUnitNumber] = newUnit;
	unit[nUnitNumber]->SetParent(this);
	nUnitNumber ++;
	return 0;
}
/*
* @brief ɾ��һ��ָ��id�ĵ�λ�����䲻����GameLayerSquare��������Ҫʱ���Խ�����ڴ���ɾ��
*        ע�⣡��������Ϸ������һ����λ���Ƴ����������ˣ�����Ȼ���ܶ���Ϸ����Ӱ�죡
*        ���Գ���һ����Ϸ���׽�����Ҫ�ͷ��ڴ棬��������Ҫ���øú�����
* @param nId:Ҫɾ���ĵ�λ��id; bDestroy:�Ƿ�ͬʱ���ڴ���ɾ��
* @return 0:�ɹ�ɾ��;
*/
int GameLayerSquare::DeleteUnit(int nId, bool bDestroy)
{
	if (bDestroy)
		delete unit[nId];
	unit.erase(nId);
	nUnitNumber --;
	return 0;
}
/*
* @brief ��ѯָ��id�ĵ�λ�����������ṩ��ָ��
* @param nId:Ҫ��ѯ�ĵ�λ��id; result:��ѯ���
* @return 0:�ɹ���ѯ; 1:������ͬid��λ
*/
int GameLayerSquare::QueryUnit(int nId, GameUnit* result)
{
	if (unit.count(nId) == 0)
		return 1;
	result = unit[nId];
	return 0;
}

//////////////////////////////�����������//////////////////////////////
/*
* @brief ���ø�����
* @param _parent:Ҫ����Ϊ�������ָ��
* @return 0:���óɹ� 1:����ʧ��
*/
int GameLayerSquare::SetParent(GameBoardSquare* _parent)
{
	parent = _parent;
	return 0;
}

/*
* @brief ��չGameLayerSquare��С
*        ע�⣡���ڵ�������һ����Ĵ�С������������㲻Э��������������Ȿ����ֻ����ExpandBoard���ã�
* @param nNewSizeX,nNewSizeY:�²�Ĵ�С nAnchorX,nAnchorY:ԭ����(0,0)���²��ϵ�����
* @return 0:�ɹ���չ 1:�²�Ĵ�С��ԭ�д�С��ҪС 2:����nAnchorX��nAnchorY������ԭ��һ����/ȫ�������²㷶Χ
*/
int GameLayerSquare::ExpandLayer(int nNewSizeX, int nNewSizeY, int nAnchorX, int nAnchorY)
{
	if (nNewSizeX < nSizeX || nNewSizeY < nSizeY)
		return 1;
	if (nAnchorX + nSizeX > nNewSizeX || nAnchorY + nSizeY > nNewSizeY)
		return 2;
	map<int,GameUnit*>::iterator it;
	for (it = unit.begin(); it != unit.end(); it++)
		it->second->ChangePosition(it->second->Position().x + nAnchorX, it->second->Position().y + nAnchorY);
	return 0;
}
/*
* @brief ��СGameLayerSquare��С
*        ע�⣡���ڵ�������һ����Ĵ�С������������㲻Э��������������Ȿ����ֻ����ExpandBoard���ã�
*        ע�⣡������ػ���δ��ɣ���������������ƣ�
* @param nNewSizeX,nNewSizeY:�²�Ĵ�С nAnchorX,nAnchorY:�²��ϵ�����(0,0)��ԭ�������
* @return 0:�ɹ���չ 1:�²�Ĵ�С��ԭ�д�С��Ҫ�� 2:����nAnchorX��nAnchorY�������²�һ����/ȫ������ԭ�㷶Χ
*/
int GameLayerSquare::ShrinkLayer(int nNewSizeX, int nNewSizeY, int nAnchorX, int nAnchorY)
{
	if (nNewSizeX > nSizeX || nNewSizeY > nSizeY)
		return 1;
	if (nAnchorX + nNewSizeX > nSizeX || nAnchorY + nNewSizeY > nSizeY)
		return 2;
	map<int,GameUnit*>::iterator it;
	for (it = unit.begin(); it != unit.end(); it++)
		it->second->ChangePosition(it->second->Position().x - nAnchorX, it->second->Position().y - nAnchorY);
	return 0;
}


//////////////////////////////��ѯ����//////////////////////////////
int GameLayerSquare::StackOrder()
{
	return nStackOrder;
}

int GameLayerSquare::SizeX()
{
	return nSizeX;
}

int GameLayerSquare::SizeY()
{
	return nSizeY;
}