/**************************************************************************

Copyright:Sunburst

Author:������

Date:2015-03-29

Description:ʵ����GameBoardSquare�ࡣ

**************************************************************************/

#ifndef _GAME_BOARD_SQUARE_H_
#define _GAME_BOARD_SQUARE_H_

#include <string>
#include <map>
#include "GameBase.h"
#include "GameLayerSquare.h"
#include "GameEvent.h"
#include "Game.h"

using namespace std;

/*
* @brief
* GameBoardSquare�����߼����ֵ����ģ�飬������ʵ�ֲ����������θ����̡�
* ����һ������ʵ�������ɶ���ص��Ĳ㣨�絥λ�����εȣ���ɵģ�����GameBoardSquareʵ���ϸ��������Щ�㡣
* ͬʱ��GameBoardSquareҲ�����һЩ��������ı����������Լ������ƣ�
*/
class GameBoardSquare : public GameBase
{
private:
	//���̴�С
	int nSizeX;
	int nSizeY;
	//������������Ĳ�
	map<string,GameLayerSquare*> layer;

	int nLayerNumber;

	Game* parent;

public:
	//���캯��
	GameBoardSquare();
	GameBoardSquare(Game* _parent);
	//��������
	~GameBoardSquare();

	/*
	* @brief ����һ��ָ�����Ƶ��²�
	* @param sLayerName:�²������
	* @return 0:�ɹ����� 1:�Ѵ���ӵ�и����ƵĲ�
	*/
	int AddLayer(string sLayerName);

	/*
	* @brief ��һ�����в����GameBoardSquare
	* @param sLayerName:����������� gameLayer:Ҫ����Ĳ�
	* @return 0:�ɹ����� 1:�Ѵ���ӵ�и����ƵĲ�
	*/
	int AddLayer(string sLayerName, GameLayerSquare* gameLayer);

	/*
	* @brief ��GameBoardSquare��ɾ��һ��ָ���㣬��Ҫʱ���Խ�����ڴ���ɾ��
	*        ע�⣡��������Ϸ������һ���㱻�Ƴ����������ˣ�����Ȼ���ܶ���Ϸ����Ӱ�죡
	*        ���Գ���һ����Ϸ���׽�����Ҫ�ͷ��ڴ棬��������Ҫ���øú�����
	* @param sLayerName:Ҫɾ���Ĳ������; bDestroy:�Ƿ�ͬʱ���ڴ���ɾ��
	* @return 0:�ɹ�ɾ�� 1:ӵ�и����ƵĲ㲻����
	*/
	int DeleteLayer(string sLayerName, bool bDestroy = true);

	/*
	* @brief ��չGameBoardSquare��С
	* @param nNewSizeX,nNewSizeY:�����̵Ĵ�С nAnchorX,nAnchorY:ԭ����(0,0)���������ϵ�����
	* @return 0:�ɹ���չ 1:�����̵Ĵ�С��ԭ�д�С��ҪС 2:����nAnchorX��nAnchorY������ԭ����һ����/ȫ�����������̷�Χ
	*/
	int ExpandBoard(int nNewSizeX, int nNewSizeY, int nAnchorX = 0, int nAnchorY = 0);

	/*
	* @brief ��СGameBoardSquare��С
	* @param nNewSizeX,nNewSizeY:�����̵Ĵ�С nAnchorX,nAnchorY:������(0,0)��ԭ�����ϵ�����
	* @return 0:�ɹ���չ 1:�����̵Ĵ�С��ԭ�д�С��Ҫ�� 2:����nAnchorX��nAnchorY������������һ����/ȫ������ԭ���̷�Χ
	*/
	int ShrinkBoard(int nNewSizeX, int nNewSizeY, int nAnchorX = 0, int nAnchorY = 0);

	/*
	* @brief ��ѯ���������Ƿ���ָ�����ƵĲ㣬�����򷵻�ָ������ָ��
	* @param sLayerName:Ҫ��ѯ�Ĳ������; result:��ѯ����ָ��
	* @return 0: 1:û�и����ƵĲ�ָ��Ҫ��ѯ�Ĳ��ָ��
	*/
	int QueryLayer(string sLayerName, GameLayerSquare* result);
	
	/*
	* @brief ���ø�����
	* @param _parent:Ҫ����Ϊ�������ָ��
	* @return 0:���óɹ� 1:����ʧ��
	*/
	int SetParent(Game* _parent);

	int SizeX();
	int SizeY();
};

#endif