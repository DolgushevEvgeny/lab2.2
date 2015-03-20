#pragma once

std::string RemoveExtraSpaces(std::string const & processedString);
int ReturnNonSpacePlace(std::string processedString);
void CopyToResultString(std::string &resultString, const std::string &originalString, int elementPosition, int &spacesCounter);