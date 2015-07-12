#ifndef _GAME_H_
#define _GAME_H

#include <string>
#include <map>
#include "GameEvent.h"

using namespace std;

/*
* @brief
* Game�����߼����ֵ����ģ�飬����������֮��Ĺ����ظ��������������͵����ˡ�
* �����ظ��Ĺ�����Ҫ��������������Ĺ��������¼��Ĺ��������������ֻʵ������һ���ֵĹ��ܡ�
*/
class GameBase
{
private:
	//����������¼�
	map<int,GameEvent*> event;

	//�������������
	map<string,int> nProperty;
	//��������ĸ���
	map<string,double> dProperty;
	//����������ַ���
	map<string,string> sProperty;

public:	
//////////////////////////////�����������//////////////////////////////
	/*
	* @brief �½�ָ�����Ƶ�������������β���ֵ
	* @param sPropertyName:������; nValue:����ֵ
	* @return 0:�ɹ��½�; 1:�Ѵ���ͬ������; 2:�Ѵ���ͬ��������; 3:�Ѵ���ͬ���ַ���
	*/
	int AddProperty(string sPropertyName, int nValue);
	/*
	* @brief �½�ָ�����Ƶ�������������β���ֵ
	* @param sPropertyName:������; dValue:����ֵ
	* @return 0:�ɹ��½�; 1:�Ѵ���ͬ������; 2:�Ѵ���ͬ��������; 3:�Ѵ���ͬ���ַ���
	*/
	int AddProperty(string sPropertyName, double dValue);
	/*
	* @brief �½�ָ�����Ƶ�������������β���ֵ
	* @param sPropertyName:������;sValue:����ֵ
	* @return 0:�ɹ��½�; 1:�Ѵ���ͬ������; 2:�Ѵ���ͬ��������; 3:�Ѵ���ͬ���ַ���
	*/
	int AddProperty(string sPropertyName, string sValue);
	/*
	* @brief ɾ��ָ�����Ƶ���������ı���
	*        ע�⣡��������Ϸ������һ��������ɾ���ˣ�����Ȼ���ܶ���Ϸ����Ӱ�죡
	*        ���Գ���һ����Ϸ���׽�����Ҫ�ͷ��ڴ棬��������Ҫ���øú�����
	* @param sPropertyName:������
	* @return 0:�ɹ�ɾ��; 1:������ͬ������
	*/
	int DeleteProperty(string sPropertyName);
	/*
	* @brief ����ָ�����Ƶ�������������ε�ֵ
	* @param sPropertyName:������; nValue:����ֵ
	* @return 0:�ɹ��½�; 1:������ͬ������;
	*/
	int ChangeProperty(string sPropertyName, int nValue);
	/*
	* @brief ����ָ�����Ƶ���������ĸ�������ֵ
	* @param sPropertyName:������; dValue:����ֵ
	* @return 0:�ɹ��½�; 1:������ͬ������;
	*/
	int ChangeProperty(string sPropertyName, double dValue);
	/*
	* @brief ����ָ�����Ƶ�����������ַ�����ֵ
	* @param sPropertyName:������; sValue:����ֵ
	* @return 0:�ɹ��½�; 1:������ͬ������;
	*/
	int ChangeProperty(string sPropertyName, string sValue);
	/*
	* @brief ��ѯָ�����Ƶ�������������ε�ֵ
	* @param sPropertyName:������; nValue:��ѯ���ı���ֵ
	* @return 0:�ɹ���ѯ; 1:������ͬ������;
	*/

//////////////////////////////��ѯ����//////////////////////////////
	int QueryProperty(string sPropertyName, int* nValue);
	/*
	* @brief ��ѯָ�����Ƶ���������ĸ�������ֵ
	* @param sPropertyName:������; dValue:��ѯ���ı���ֵ
	* @return 0:�ɹ���ѯ; 1:������ͬ������;
	*/
	int QueryProperty(string sPropertyName, double* dValue);
	/*
	* @brief ��ѯָ�����Ƶ�����������ַ�����ֵ
	* @param sPropertyName:������; sValue:��ѯ���ı���ֵ
	* @return 0:�ɹ���ѯ; 1:������ͬ������;
	*/
	int QueryProperty(string sPropertyName, string* sValue);
};


#endif