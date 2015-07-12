#include <string>
#include <map>
#include "GameBase.h"

using namespace std;

//////////////////////////////�����������//////////////////////////////
/*
* @brief �½�ָ�����Ƶ�������������β���ֵ
* @param sPropertyName:������; nValue:����ֵ
* @return 0:�ɹ��½�; 1:�Ѵ���ͬ������; 2:�Ѵ���ͬ��������; 3:�Ѵ���ͬ���ַ���
*/
int GameBase::AddProperty(string sPropertyName, int nValue)
{
	if (nProperty.count(sPropertyName) == 1)
		return 1;
	if (dProperty.count(sPropertyName) == 1)
		return 2;
	if (sProperty.count(sPropertyName) == 1)
		return 3;
	nProperty[sPropertyName] = nValue;
	return 0;
}

/*
* @brief �½�ָ�����Ƶ�������������β���ֵ
* @param sPropertyName:������; dValue:����ֵ
* @return 0:�ɹ��½�; 1:�Ѵ���ͬ������; 2:�Ѵ���ͬ��������; 3:�Ѵ���ͬ���ַ���
*/
int GameBase::AddProperty(string sPropertyName, double dValue)
{
	if (nProperty.count(sPropertyName) == 1)
		return 1;
	if (dProperty.count(sPropertyName) == 1)
		return 2;
	if (sProperty.count(sPropertyName) == 1)
		return 3;
	dProperty[sPropertyName] = dValue;
	return 0;
}

/*
* @brief �½�ָ�����Ƶ�������������β���ֵ
* @param sPropertyName:������;sValue:����ֵ
* @return 0:�ɹ��½�; 1:�Ѵ���ͬ������; 2:�Ѵ���ͬ��������; 3:�Ѵ���ͬ���ַ���
*/
int GameBase::AddProperty(string sPropertyName, string sValue)
{
	if (nProperty.count(sPropertyName) == 1)
		return 1;
	if (dProperty.count(sPropertyName) == 1)
		return 2;
	if (sProperty.count(sPropertyName) == 1)
		return 3;
	sProperty[sPropertyName] = sValue;
	return 0;
}

/*
* @brief ɾ��ָ�����Ƶ���������ı���
*        ע�⣡��������Ϸ������һ��������ɾ���ˣ�����Ȼ���ܶ���Ϸ����Ӱ�죡
*        ���Գ���һ����Ϸ���׽�����Ҫ�ͷ��ڴ棬��������Ҫ���øú�����
* @param sPropertyName:������
* @return 0:�ɹ�ɾ��; 1:������ͬ������
*/
int GameBase::DeleteProperty(string sPropertyName)
{
	if (nProperty.count(sPropertyName) == 1)
	{
		nProperty.erase(sPropertyName);
		return 0;
	}
	if (dProperty.count(sPropertyName) == 1)
	{
		dProperty.erase(sPropertyName);
		return 0;
	}
	if (sProperty.count(sPropertyName) == 1)
	{
		sProperty.erase(sPropertyName);
		return 0;
	}
	return 1;
}

/*
* @brief ����ָ�����Ƶ�������������ε�ֵ
* @param sPropertyName:������; nValue:����ֵ
* @return 0:�ɹ��½�; 1:������ͬ������;
*/
int GameBase::ChangeProperty(string sPropertyName, int nValue)
{
	if (nProperty.count(sPropertyName) == 1)
		nProperty[sPropertyName] = nValue;
	else
		return 1;
	return 0;
}

/*
* @brief ����ָ�����Ƶ���������ĸ�������ֵ
* @param sPropertyName:������; dValue:����ֵ
* @return 0:�ɹ��½�; 1:������ͬ������;
*/
int GameBase::ChangeProperty(string sPropertyName, double dValue)
{
	if (dProperty.count(sPropertyName) == 1)
		dProperty[sPropertyName] = dValue;
	else
		return 1;
	return 0;
}

/*
* @brief ����ָ�����Ƶ�����������ַ�����ֵ
* @param sPropertyName:������; sValue:����ֵ
* @return 0:�ɹ��½�; 1:������ͬ������;
*/
int GameBase::ChangeProperty(string sPropertyName, string sValue)
{
	if (sProperty.count(sPropertyName) == 1)
		sProperty[sPropertyName] = sValue;
	else
		return 1;
	return 0;
}

/*
* @brief ��ѯָ�����Ƶ�������������ε�ֵ
* @param sPropertyName:������; nValue:��ѯ���ı���ֵ
* @return 0:�ɹ���ѯ; 1:������ͬ������;
*/

//////////////////////////////��ѯ����//////////////////////////////
int GameBase::QueryProperty(string sPropertyName, int* nValue)
{
	if (nProperty.count(sPropertyName) == 0)
		return 0;
	*nValue = nProperty[sPropertyName];
	return 0;
}

/*
* @brief ��ѯָ�����Ƶ���������ĸ�������ֵ
* @param sPropertyName:������; dValue:��ѯ���ı���ֵ
* @return 0:�ɹ���ѯ; 1:������ͬ������;
*/
int GameBase::QueryProperty(string sPropertyName, double* dValue)
{
	if (dProperty.count(sPropertyName) == 0)
		return 0;
	*dValue = dProperty[sPropertyName];
	return 0;
}

/*
* @brief ��ѯָ�����Ƶ�����������ַ�����ֵ
* @param sPropertyName:������; sValue:��ѯ���ı���ֵ
* @return 0:�ɹ���ѯ; 1:������ͬ������;
*/
int GameBase::QueryProperty(string sPropertyName, string* sValue)
{
	if (sProperty.count(sPropertyName) == 0)
		return 0;
	*sValue = sProperty[sPropertyName];
	return 0;
}