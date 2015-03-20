// delete_spaces_tests.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../delete_spaces/ProcessString.h"

using namespace std;

bool StringsAreEqual(string & x, const char *y)
{
	return x == y;
}

bool StringsAreEqual(string & x, string & y)
{
	return x == y;
}

BOOST_AUTO_TEST_CASE(EmptyStringProducesEmptyString)
{
	string emptyString;
	auto copy = emptyString;
	RemoveExtraSpaces(emptyString);
	BOOST_CHECK(StringsAreEqual(emptyString, copy));
}

BOOST_AUTO_TEST_CASE(StringWithSpacesInTheBeginning)
{
	string processedString = "    test-beginning";
	string resultString = RemoveExtraSpaces(processedString);
	BOOST_CHECK(StringsAreEqual(resultString, "test-beginning"));
}

BOOST_AUTO_TEST_CASE(StringWithSpacesInTheBeginningAndInTheMiddle)
{
	string processedString = "  test-beginning  test-middle";
	string resultString = RemoveExtraSpaces(processedString);
	BOOST_CHECK(StringsAreEqual(resultString, "test-beginning test-middle"));
}

BOOST_AUTO_TEST_CASE(StringWithSpacesInTheBeginningInTheMiddleInTheEnd)
{
	string processedString = "  test-beginning  test-middle  test-end     ";
	string resultString = RemoveExtraSpaces(processedString);
	BOOST_CHECK(StringsAreEqual(resultString, "test-beginning test-middle test-end"));
}

BOOST_AUTO_TEST_CASE(StringWithSpacesProduceEmptyString)
{
	string processedString = "       ";
	string resultString = RemoveExtraSpaces(processedString);
	BOOST_CHECK(StringsAreEqual(resultString, ""));
}

BOOST_AUTO_TEST_CASE(StringWithOutSpacesProduceGoodString)
{
	string processedString = "test-beginning";
	string resultString = RemoveExtraSpaces(processedString);
	BOOST_CHECK(StringsAreEqual(resultString, "test-beginning"));
}