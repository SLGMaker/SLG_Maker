#include <string>
#include <map>
#include "Game.h"

using namespace std;


//////////////////////////////��������������//////////////////////////////




//////////////////////////////�����������//////////////////////////////
/*
* @brief ���Ĳ��ŵ�bgm���
* @param nBGMSerial:��Ҫ���ĵ�ֵ
* @return 0:���ĳɹ�
*/
int Game::SwitchBGM(int nBGMSerial)
{
	nBGMStatus = nBGMSerial;
	return 0;
}



//////////////////////////////�Ӷ��������//////////////////////////////
/*
* @brief �½�һ��GameBoardSquare��ָ��һ������GameBoardSquare���������Game�Ĺ�������
* @param sBoardName:Ҫ�����GameBoardSquare������; gameBoardSquare:ָ��Ҫ�����GameBoardSquare��ָ��
* @return 0:�ɹ��½�/����; 1:�Ѵ���ͬ��GameBoardSquare���½�/����ʧ��
*/
int Game::AddGameBoardSquare(string sBoardName, GameBoardSquare* newGameBoardSquare = NULL)
{
	if (gameBoardSquare.count(sBoardName) == 1)
		return 1;
	if (newGameBoardSquare == NULL)
		gameBoardSquare[sBoardName] = new GameBoardSquare(this);
	else
	{
		gameBoardSquare[sBoardName] = newGameBoardSquare;
		gameBoardSquare[sBoardName]->SetParent(this);
	}
	nBoardNumber ++;
	return 0;
}

/*
* @brief ɾ��һ��ָ����GameBoardSquare�����䲻����Game��������Ҫʱ���Խ�����ڴ���ɾ��
*        ע�⣡��������Ϸ������һ��GameBoardSquare���Ƴ����������ˣ�����Ȼ���ܶ���Ϸ����Ӱ�죡
*        ���Գ���һ����Ϸ���׽�������������Ҫ��destroy=1��
* @param sBoardName:Ҫɾ����GameBoardSquare������; bDestroy:�Ƿ�ͬʱ���ڴ���ɾ��
* @return 0:�ɹ�ɾ��; 1:������ͬ��GameBoardSquare��ɾ��ʧ��
*/
int Game::DeleteGameBoardSquare(string sBoardName, bool bDestroy = true)
{
	if (gameBoardSquare.count(sBoardName) == 0)
		return 1;
	if (bDestroy)
		delete gameBoardSquare[sBoardName];
	gameBoardSquare.erase(sBoardName);
	nBoardNumber --;
	return 0;
}

/*
* @brief ��ѯָ�����Ƶ�GameBoardSquare�����������ṩ��ָ��
* @param sBoardName:Ҫ��ѯ��GameBoardSquare������; result:��ѯ���
* @return 0:�ɹ���ѯ; 1:������ͬ��GameBoardSquare
*/
int Game::QueryGameBoardSquare(string sBoardName, GameBoardSquare* result)
{
	if (gameBoardSquare.count(sBoardName) == 0)
		return 1;
	result = gameBoardSquare[sBoardName];
	return 0;
}