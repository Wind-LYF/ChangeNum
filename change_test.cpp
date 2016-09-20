// change_test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include "iostream"
#include <cstring>
#include <string>
#include <stdlib.h>
#include <atlstr.h>
using namespace std;
int ChangeNum(string BigNum);

int _tmain(int argc, _TCHAR* argv[])
{
	string test;
	cin >> test;
	cout<<ChangeNum(test)<<endl;
	system("pause");
	return 0;
}

int ChangeNum(string BigNum)
{
	int Num = 0;
	CString unit = _T("十百千万"), number = _T("零一二三四五六七八九十");
	int tem;//存放单位
	CString BigNum_Cstring = BigNum.c_str();
	for (int i = 0; i <= BigNum_Cstring.GetLength(); i++)
	{
		int tete = BigNum_Cstring.GetLength();
		tem = 1;
		if (i == BigNum_Cstring.GetLength()-1)
		{
			for (int j = 0; j < 11; j++)
			{
				if (number[j] == BigNum_Cstring[i])
				{
					Num += j;
					break;
				}
			}
			break;
		}
		for (int k = 0; k < 11; k++)
		{
			if (number[k] == BigNum_Cstring[i])
			{
				if (k == 0){ break; }
				else
				{
					for (int l = 0; l < 5; l++)
					{
						if (unit[l] == BigNum_Cstring[i + 1])
						{
							switch (l)
							{
							case 0:
								Num += k * 10;
								i++;
								break;
							case 1:
								Num += k * 100;
								i++;
								break;
							case 2:
								Num += k * 1000;
								i++;
								break;
							case 3:
								Num += k * 10000;
								i++;
								break;
							}
							break;//退出寻找单位循环
						}
					}
					break;//退出当前字符转换，开始下一个
				}
			}
		}
	}
	return Num;
}