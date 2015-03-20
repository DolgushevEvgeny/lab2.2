#include "stdafx.h"
#include "ProcessString.h"
#include "string"
#include <fstream>
using namespace std;

int ReturnNonSpacePlace(string processedString)
{
	for (unsigned int nonSpacePlace = 0; nonSpacePlace < processedString.size(); ++nonSpacePlace)
	{
		if (processedString[nonSpacePlace] != ' ')
		{ 
			return nonSpacePlace;
		}
	}
	return 0;
}

void CopyToResultString(string &resultString, const string &originalString, int elementPosition, int &spacesCounter)
{
	if (originalString[elementPosition] == ' ')
	{
		++spacesCounter;
	}
	else
	{
		if (spacesCounter > 1)
		{
			resultString += " ";
			resultString += originalString[elementPosition];
			spacesCounter = 0;
		}
		else
		{
			resultString += originalString[elementPosition];
			spacesCounter = 0;
		}
	}
}

string RemoveExtraSpaces(string const & processedString)
{
	string resultString;
	if (processedString.size())
	{
		int spacesCounter = 0;
		auto nonSpacePlace = ReturnNonSpacePlace(processedString);
		for (unsigned int stringElementPosition = nonSpacePlace; stringElementPosition < processedString.size(); ++stringElementPosition)
		{
			CopyToResultString(resultString, processedString, stringElementPosition, spacesCounter);
		}
	}
	return resultString;
}