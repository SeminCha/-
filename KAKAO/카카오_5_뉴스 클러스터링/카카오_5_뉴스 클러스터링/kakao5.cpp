#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 1
#include <hash_map>
#include <stdio.h>
#include <string> 
#include <algorithm>
#include <iostream>
using namespace std;
using namespace stdext;

bool isEnglish(char ch)
{
	if ((0x61 <= ch && ch <= 0x7A) || (0x41 <= ch && ch <= 0x5A))
		return true;
	else
		return false;
}

int main()
{
	hash_map<string, int> str1HashMap;
	hash_map<string, int> str2HashMap;

	string str1, str2;
	string temp;
	double jacard, numOfUnion = 0, numOfInsec = 0;
	int numOfStr1 = 0, numOfStr2 = 0;	

	cout << "str1 �Է� : ";
	getline(cin, str1);
	cout << "str2 �Է� : ";
	getline(cin, str2);
	transform(str1.begin(), str1.end(), str1.begin(), tolower);
	transform(str2.begin(), str2.end(), str2.begin(), tolower);

	for (int i = 0; i < str1.length() - 1; i++)
	{
		if (isEnglish(str1[i]) && isEnglish(str1[i + 1]))
		{
			temp = str1.substr(i, 2);
			//Ű�� �������� ������ ����
			if (!str1HashMap.count(temp))
				str1HashMap.insert(pair<string, int>(temp, 1));
			//Ű�� �̹� �����ϸ� �� ���� +1
			else
			{
				auto it = str1HashMap.find(temp);
				if (it != str1HashMap.end())
					it->second = ++it->second;
			}
		}
	}

	for (int i = 0; i < str2.length() - 1; i++)
	{
		if (isEnglish(str2[i]) && isEnglish(str2[i + 1]))
		{
			temp = str2.substr(i, 2);
			//Ű�� �������� ������ ����
			if (!str2HashMap.count(temp))
				str2HashMap.insert(pair<string, int>(temp, 1));
			//Ű�� �̹� �����ϸ� �� ���� +1
			else
			{
				auto it = str2HashMap.find(temp);
				if (it != str2HashMap.end())
					it->second = ++it->second;
			}
		}
	}

	for (const auto &istr1 : str1HashMap) {
		numOfStr1 = numOfStr1 + istr1.second;
		numOfStr2 = 0;
		for (const auto &istr2 : str2HashMap) {
			//str1�� str2�� �������� �߰ߵǾ��� ���
			if (istr1.first == istr2.first)
			{
				//�� ���� ���� ����
				if (istr1.second < istr2.second)			
					numOfInsec = numOfInsec + istr1.second;				
				else
					numOfInsec = numOfInsec + istr2.second;
			}
			numOfStr2 = numOfStr2 + istr2.second;
		}
		//cout << " str1HashMap[" << p.first << "] = " << p.second << '\n';
	}
	
	//������ ���� ���ϱ�
	numOfUnion = numOfStr1 + numOfStr2 - numOfInsec;

	if (numOfUnion == 0)
		jacard = 1;
	else
		jacard = numOfInsec / numOfUnion;

	cout << "answer : " << int(jacard*65536) << '\n';
	/*cout << "numOfStr1 : " << numOfStr1 << " numOfStr2 = " << numOfStr2 << '\n';
	cout << "������ : " << numOfInsec << " ������ = " << numOfUnion << '\n';*/

	return 0;
}

