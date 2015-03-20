// delete_spaces.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "ProcessString.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	vector<string> stringsVector;
	while (!cin.eof())
	{
		string processedString;
		if (getline(cin, processedString))
		{
			stringsVector.push_back(processedString);
		}
		else
		{
			break;
		}
	}
	for (vector<string>::iterator processedString = stringsVector.begin(); processedString != stringsVector.end(); ++processedString)
	{
		string resultString = RemoveExtraSpaces(*processedString);
		cout << resultString << "\n";
	}
	system("pause");
	return 0;
}

