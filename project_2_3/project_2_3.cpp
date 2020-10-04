#include "NumberConverter.h"

/*std::vector<double> readInVector(std::string s) {
	int prev_location = 0;
	int next_location = 0;
	std::vector<double> result;
	while (s.find(',', prev_location) != std::string::npos) {
		next_location = s.find(',', prev_location);
		//std::cout << "prev_location: " << prev_location << std::endl;
		//std::cout << "next_location: " << next_location << std::endl;
		// substr [,]
		//std::cout << s.substr(prev_location, next_location - prev_location) << std::endl;
		result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
		next_location++;
		prev_location = next_location;
	}
	result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
	return result;
}*/

int main() {
	std::string convertTo;
	std::cin >> convertTo;

	std::string number;
	std::cin >> number;

	std::string output;
	std::string input;

	if (number.size() > 1 && number[0] == 'b') {
		// Converting from binary
		input = number.substr(1);
		if (convertTo == "d") {
			// Converting to decimal
			output = std::to_string(NumberConverter::binaryToDecimal(input));
		} else {
			// Converting to hex
			output = NumberConverter::binaryToHex(input);
		}
	} else if (number.size() > 2 && number[1] == 'x') {
		// Converting from hex
		input = number.substr(2);
		if (convertTo == "b") {
			// Converting to binary
			output = NumberConverter::hexToBinary(input);
		} else {
			// Converting to decimal
			output = std::to_string(NumberConverter::hexToDecimal(input));
		}
	} else {
		// Converting from decimal
		input = number;
		if (convertTo == "b") {
			// Converting to binary
			output = NumberConverter::decimalToBinary(std::stoi(input));
		} else {
			// Converting to hex
			output = NumberConverter::decimalToHex(std::stoi(input));
		}
	}

	std::cout << "input: " << input << std::endl;
	std::cout << "output type: " << convertTo << std::endl;
	std::cout << "result: " << output << std::endl;

	return 0;
}
