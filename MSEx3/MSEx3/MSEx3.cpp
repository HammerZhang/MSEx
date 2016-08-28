// MSEx3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 分割字符串,返回string vector
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

// 倒序显示字符串,参数为字符串vector
void reverseDisplayStr(vector<string> str)
{
	int size = str.size();
	std::cout << "倒序显示字符串: ";
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

