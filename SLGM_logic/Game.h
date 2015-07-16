#ifndef _GAME_H_
#define _GAME_H_

#include <string>
#include <map>
#include "GameBoardSquare.h"
#include "GameEvent.h"
#include "GameBase.h"

using namespace std;

/*
* @brief
* Game�����߼����ֵ����ģ�飬������ʵ��һ����Ϸ��
* һ����Ϸ���ٻẬ��һ�����̣�Game�ฺ����������ǣ���
* ͬʱ��GameҲ�����һЩ��������ı���
*/
class Game : public GameBase
{
private:
	//Game�����GameBoard������
	int nBoardNumber;
	//��Game�����GameBoardquare
	map<string,GameBoardSquare*> gameBoardSquare;

	//bgm״̬������bgm�Ĳ���
	//��ֵΪ��Ҫ�����ڣ�����bgm����ţ�ȡ-1ʱ��ʾ������
	int nBGMStatus;

public:
	/*
	* @brief ���Ĳ��ŵ�bgm���
	* @param nBGMSerial:��Ҫ���ĵ�ֵ
	* @return 0:���ĳɹ�
	*/
	int SwitchBGM(int nBGMSerial);

	/*
	* @brief �½�һ��GameBoardSquare��ָ��һ������GameBoardSquare���������Game�Ĺ�������
	* @param sBoardName:Ҫ�����GameBoardSquare������; newGameBoardSquare:ָ��Ҫ�����GameBoardSquare��ָ��
	* @return 0:�ɹ��½�/����; 1:�Ѵ���ͬ��GameBoardSquare���½�/����ʧ��
	*/
	int AddGameBoardSquare(string sBoardName, GameBoardSquare* newGameBoardSquare = NULL);
	/*
	* @brief ɾ��һ��ָ����GameBoardSquare�����䲻����Game��������Ҫʱ���Խ�����ڴ���ɾ��
	*        ע�⣡��������Ϸ������һ��GameBoardSquare���Ƴ����������ˣ�����Ȼ���ܶ���Ϸ����Ӱ�죡
	*        ���Գ���һ����Ϸ���׽�����Ҫ�ͷ��ڴ棬��������Ҫ���øú�����
	* @param sBoardName:Ҫɾ����GameBoardSquare������; bDestroy:�Ƿ�ͬʱ���ڴ���ɾ��
	* @return 0:�ɹ�ɾ��; 1:������ͬ��GameBoardSquare��ɾ��ʧ��
	*/
	int DeleteGameBoardSquare(string sBoardName, bool bDestroy = true);
	/*
	* @brief ��ѯָ�����Ƶ�GameBoardSquare�����������ṩ��ָ��
	* @param sBoardName:Ҫ��ѯ��GameBoardSquare������; result:��ѯ���
	* @return 0:�ɹ���ѯ; 1:������ͬ��GameBoardSquare
	*/
	int QueryGameBoardSquare(string sBoardName, GameBoardSquare* result);
};


#endif
