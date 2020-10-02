#pragma once
#include <iostream>
#include <vector>

class convolution {
public: 
	static std::vector<double> applyConvolution(std::vector<double> x, std::vector<double> w, bool pack_with_zeros);
};
