// MSEx3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// �ָ��ַ���,����string vector
vector<string> SplitStr(string str, string pattern)
{
	string::size_type pos;
	str += pattern;
	int size = str.size();
	string subs;
	vector<string> resVec;

	for (int i = 0; i < size; i++)
	{
		pos = str.find(pattern,i);
		subs = str.substr(i, pos - i);
		resVec.push_back(subs);
		i = pos + pattern.size()-1;
	}

	return resVec;
}

// ������ʾ�ַ���,����Ϊ�ַ���vector
void reverseDisplayStr(vector<string> str)
{
	int size = str.size();
	std::cout << "������ʾ�ַ���: ";
	for (int i = size - 1; i >= 0; i--)
	{
		cout << str[i] << "->";
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	string str = "I am not a real hammer, may name is hammer";
	vector<string> strVec = SplitStr(str, " ");
	reverseDisplayStr(strVec);

	return 0;
}

