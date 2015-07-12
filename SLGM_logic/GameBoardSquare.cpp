#include "GameBoardSquare.h"


//////////////////////////////��������������//////////////////////////////
GameBoardSquare::GameBoardSquare()
{
	nLayerNumber = 0;
}

GameBoardSquare::GameBoardSquare(Game* _parent)
{
	nLayerNumber = 0;
	parent = _parent;
}


//////////////////////////////�Ӷ��������//////////////////////////////
/*
* @brief ����һ��ָ�����Ƶ��²�
* @param sLayerName:�²������
* @return 0:�ɹ����� 1:�Ѵ���ӵ�и����ƵĲ�
*/
int GameBoardSquare::AddLayer(string sLayerName)
{
	if (layer.count(sLayerName) == 1)
		return 1;
	nLayerNumber ++;
	layer[sLayerName] = new GameLayerSquare(this);
	return 0;
}
/*
* @brief ��һ�����в����GameBoardSquare
* @param sLayerName:����������� gameLayer:Ҫ����Ĳ�
* @return 0:�ɹ����� 1:�Ѵ���ӵ�и����ƵĲ�
*/
int GameBoardSquare::AddLayer(string sLayerName, GameLayerSquare* gameLayer)
{
	if (layer.count(sLayerName) == 1)
		return 1;
	nLayerNumber ++;
	layer[sLayerName] = gameLayer;
	layer[sLayerName]->SetParent(this);
	return 0;
}
/*
* @brief ��GameBoardSquare��ɾ��һ��ָ����
*        ע�⣡��������Ϸ������һ���㱻�Ƴ����������ˣ�����Ȼ���ܶ���Ϸ����Ӱ�죡
*        ���Գ���һ����Ϸ���׽�����Ҫ�ͷ��ڴ棬��������Ҫ���øú�����
* @param sLayerName:Ҫɾ���Ĳ������; bDestroy:�Ƿ�ͬʱ���ڴ���ɾ��
* @return 0:�ɹ�ɾ�� 1:ӵ�и����ƵĲ㲻����
*/
int GameBoardSquare::DeleteLayer(string sLayerName, bool bDestroy = true)
{
	if (layer.count(sLayerName) == 0)
		return 1;
	if (bDestroy)
		delete layer[sLayerName];
	return 0;
}



//////////////////////////////�����������//////////////////////////////
/*
* @brief ��չGameBoardSquare��С
* @param nNewSizeX,nNewSizeY:�����̵Ĵ�С nAnchorX,nAnchorY:ԭ����(0,0)���������ϵ�����
* @return 0:�ɹ���չ 1:�����̵Ĵ�С��ԭ�д�С��ҪС 2:����nAnchorX��nAnchorY������ԭ����һ����/ȫ�����������̷�Χ
*/
int GameBoardSquare::ExpandBoard(int nNewSizeX, int nNewSizeY, int nAnchorX = 0, int nAnchorY = 0)
{
	map<string,GameLayerSquare*>::iterator it;
	for (it = layer.begin(); it != layer.end(); it++)
	{
		if (it->second->ExpandLayer(nNewSizeX, nNewSizeY, nAnchorX, nAnchorY) != 0)
			return it->second->ExpandLayer(nNewSizeX, nNewSizeY, nAnchorX, nAnchorY);
	}
	return 0;
}
/*
* @brief ��СGameBoardSquare��С
* @param nNewSizeX,nNewSizeY:�����̵Ĵ�С nAnchorX,nAnchorY:������(0,0)��ԭ�����ϵ�����
* @return 0:�ɹ���չ 1:�����̵Ĵ�С��ԭ�д�С��Ҫ�� 2:����nAnchorX��nAnchorY������������һ����/ȫ������ԭ���̷�Χ
*/
int GameBoardSquare::ShrinkBoard(int nNewSizeX, int nNewSizeY, int nAnchorX = 0, int nAnchorY = 0)
{
	map<string,GameLayerSquare*>::iterator it;
	for (it = layer.begin(); it != layer.end(); it++)
	{
		if (it->second->ShrinkLayer(nNewSizeX, nNewSizeY, nAnchorX, nAnchorY) != 0)
			return it->second->ShrinkLayer(nNewSizeX, nNewSizeY, nAnchorX, nAnchorY);
	}
	return 0;
}

int GameBoardSquare::SetParent(Game* _parent)
{
	parent = _parent;
	return 0;
}

//////////////////////////////��ѯ����//////////////////////////////
/*
* @brief ��ѯ���������Ƿ���ָ�����ƵĲ㣬�����򷵻�ָ������ָ��
* @param sLayerName:Ҫ��ѯ�Ĳ������; result:��ѯ����ָ��
* @return 0: 1:û�и����ƵĲ�ָ��Ҫ��ѯ�Ĳ��ָ��
*/
int GameBoardSquare::QueryLayer(string sLayerName, GameLayerSquare* result)
{
	if (layer.count(sLayerName) == 0)
		return 1;
	result = layer[sLayerName];
	return 0;
}


int GameBoardSquare::SizeX()
{
	return nSizeX;
}
int GameBoardSquare::SizeY()
{
	return nSizeY;
}