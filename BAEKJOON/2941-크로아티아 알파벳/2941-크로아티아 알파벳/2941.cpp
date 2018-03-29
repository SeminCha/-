#include <iostream>
#include <string>
using namespace std;

int checkCroatia(string str, int index)
{
	int result;

	string two[7] = { "c=","c-","d-","lj","nj","s=","z=" };
	string three[1] = {"dz="};

	// 2글자 비교
	string parseStr = str.substr(index,2);	
	for (int i = 0; i < 7; i++)
	{
		if (two[i] == parseStr)
			return 2;
	}

	// 3글자 비교
	parseStr = str.substr(index, 3);
	if (three[0] == parseStr)
		return 3;

	return 1;
}

int checkAlphabet(string str)
{
	int count = 0;
	int i = 0;
	int result;

	while (str[i] != NULL)
	{
		if (str[i] == 'c' || str[i] == 'd' || str[i] == 'l' || str[i] == 'n' || str[i] == 's' || str[i] == 'z')
		{
			result = checkCroatia(str, i);
			count++;
			i = i + result;
		}
		else
		{
			count++;
			i++;
		}
	}

	return count;
}

int main()
{
	string str;
	cin >> str;	
	int result = checkAlphabet(str);
	cout << result << endl;
	
	return 0;
}