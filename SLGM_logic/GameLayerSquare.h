#ifndef _GAME_LAYER_SQUARE_H_
#define _GAME_LAYER_SQUARE_H_

#include <string>
#include <map>
#include "GameUnit.h"
#include "GameEvent.h"
#include "GameBase.h"

using namespace std;

class GameBoardSquare;

class GameLayerSquare : public GameBase
{
private:
	//���̴�С��һ�������Ӧ���븺���������GameBoardSquareͬ��
	int nSizeX;
	int nSizeY;
	//�ɵ�λID����λָ���ӳ��
	map<int,GameUnit*> unit;
	//��λ����
	int nUnitNumber;
	//�ò㣨����Ⱦʱ���ĵ��Ŵ�����ֵԽ��Խ���ϲ�
	int nStackOrder;

	GameBoardSquare* parent;

public:
	GameLayerSquare();
	GameLayerSquare(GameBoardSquare* _parent);
	~GameLayerSquare();
	int StackOrder();
	int SizeX();
	int SizeY();

	/*
	* @brief ��һ�����е�λ����GameLayerSquare����ָ����id
	*        ע�⣡���ڵ�λ(GameUnit)�����ʣ����������ɣ�����յ�λ����ͬʱ�����뵥λid���Զ�����
	* @param gameLayer:Ҫ����ĵ�λ
	* @return 0:�ɹ�����
	*/
	int AddUnit(GameUnit* newUnit);
	/*
	* @brief ɾ��һ��ָ��id�ĵ�λ�����䲻����GameLayerSquare��������Ҫʱ���Խ�����ڴ���ɾ��
	*        ע�⣡��������Ϸ������һ����λ���Ƴ����������ˣ�����Ȼ���ܶ���Ϸ����Ӱ�죡
	*        ���Գ���һ����Ϸ���׽�����Ҫ�ͷ��ڴ棬��������Ҫ���øú�����
	* @param nId:Ҫɾ���ĵ�λ��id; bDestroy:�Ƿ�ͬʱ���ڴ���ɾ��
	* @return 0:�ɹ�ɾ��;
	*/
	int DeleteUnit(int nId, bool bDestroy = true);
	/*
	* @brief ��ѯָ��id�ĵ�λ�����������ṩ��ָ��
	* @param nId:Ҫ��ѯ�ĵ�λ��id; result:��ѯ���
	* @return 0:�ɹ���ѯ; 1:������ͬid��λ
	*/
	int QueryUnit(int nId, GameUnit* result);

	/*
	* @brief ���ø�����
	* @param _parent:Ҫ����Ϊ�������ָ��
	* @return 0:���óɹ� 1:����ʧ��
	*/
	int SetParent(GameBoardSquare* _parent);

	/*
	* @brief ��չGameLayerSquare��С
	*        ע�⣡���ڵ�������һ����Ĵ�С������������㲻Э��������������Ȿ����ֻ����ExpandBoard���ã�
	* @param nNewSizeX,nNewSizeY:�²�Ĵ�С nAnchorX,nAnchorY:ԭ����(0,0)���²��ϵ�����
	* @return 0:�ɹ���չ 1:�²�Ĵ�С��ԭ�д�С��ҪС 2:����nAnchorX��nAnchorY������ԭ��һ����/ȫ�������²㷶Χ
	*/
	int ExpandLayer(int nNewSizeX, int nNewSizeY, int nAnchorX = 0, int nAnchorY = 0);
	/*
	* @brief ��СGameLayerSquare��С
	*        ע�⣡���ڵ�������һ����Ĵ�С������������㲻Э��������������Ȿ����ֻ����ExpandBoard���ã�
	*        ע�⣡������ػ���δ��ɣ���������������ƣ�
	* @param nNewSizeX,nNewSizeY:�²�Ĵ�С nAnchorX,nAnchorY:�²��ϵ�����(0,0)��ԭ�������
	* @return 0:�ɹ���չ 1:�²�Ĵ�С��ԭ�д�С��Ҫ�� 2:����nAnchorX��nAnchorY������ԭ��һ����/ȫ�������²㷶Χ
	*/
	int ShrinkLayer(int nNewSizeX, int nNewSizeY, int nAnchorX = 0, int nAnchorY = 0);
};


#endif
