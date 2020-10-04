#include "NumberConverter.h"
#include <iostream>

/**
 * returns a number 0-15 based off of a hex char
 * This uses ascii to figure out number it corresponds to
 * @param input
 * @return
 */
int NumberConverter::hexCharToNumber(char input) {
	// this means it is [A,B,C,D,E,F]
	if (input > 57) {
		return input - (65 - 10);
	} else {
		// this is a digit in ascii
		return input - 48;
	}
}

/**
 * returns the character that is the given hex number
 * only valid on 0-15
 * @param input
 * @return
 */
char NumberConverter::numberToHexChar(int input) {
	if (input < 10) {
		// it is a digit
		return input + 48;
	} else {
		return (input - 10) + 65;
	}
}

/**
 * returns the inputted binary number in base 10
 * @param input the binary number to covert
 * @return the input converted to base 10
 */
int NumberConverter::binaryToDecimal(std::string input) {
	int output = 0;
	for (int i = 0; i < input.size(); ++i) {
		output += pow(2, i) * hexCharToNumber(input[input.size() - i - 1]);
	}
	return output;
}

/**
 * returns the inputted hex number in base 10
 * @param input the hex number to covert
 * @return the input converted to base 10
 */
int NumberConverter::hexToDecimal(std::string input) {
	int output = 0;
	for (int i = 0; i < input.size(); ++i) {
		output += pow(16, i) * hexCharToNumber(input[input.size() - i - 1]);
	}
	return output;
}

/**
 * returns the inputted binary number in base 16
 * @param input the binary number to convert
 * @return the input converted to base 16
 */
std::string NumberConverter::binaryToHex(std::string input) {
	std::string inputReversed = "";
	for (int i = 0; i < input.size(); ++i) {
		inputReversed = input[i] + inputReversed;
	}
	input = inputReversed;
	int groupSum = 0;
	std::string output = "";
	for (int i = 0; i < input.size(); ++i) {
		char binaryChar = input[i];
		if (binaryChar == '1') {
			groupSum += pow(2, i % 4);
		}
		if (i % 4 == 3 || i == input.size() - 1) {
			output = numberToHexChar(groupSum) + output;
			groupSum = 0;
		}
	}
	return output;
}

/**
 * returns the inputted decimal number in base 16
 * @param input the decimal number to convert
 * @return the input converted to base 16
 */
std::string NumberConverter::decimalToHex(int input) {
	std::string output = "";
	while (input > 0) {
		int remainder = input % 16;
		output = numberToHexChar(remainder) + output;
		input /= 16;
	}
	return output;
}

/**
 * returns the inputted decimal number in base 2
 * @param input the decimal number to convert
 * @return the input converted to base 2
 */
std::string NumberConverter::decimalToBinary(int input) {
	std::string output = "";
	while (input > 0) {
		int remainder = input % 2;
		output = numberToHexChar(remainder) + output;
		input /= 2;
	}
	return output;
}

/**
 * returns the inputted hex number in base 2
 * @param input the hex number to convert
 * @return the input converted to base 2
 */
std::string NumberConverter::hexToBinary(std::string input) {
	int decimal = hexToDecimal(input);
	return decimalToBinary(decimal);
}