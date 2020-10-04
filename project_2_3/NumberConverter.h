#pragma once

#include <iostream>

class NumberConverter {
public:
	static int binaryToDecimal(std::string input);
	static int hexToDecimal(std::string input);
	static std::string binaryToHex(std::string input);
	static std::string decimalToHex(int input);
	static std::string decimalToBinary(int input);
	static std::string hexToBinary(std::string input);

private:
	static int hexCharToNumber(char input);
	static char numberToHexChar(int input);
};