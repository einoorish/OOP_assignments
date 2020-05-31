#pragma once
#include <iostream>

class �oordinates {

public:

	int x = 0, y = 0, z = 0;
	�oordinates() = default;
	�oordinates(int x, int y, int z) : x(x), y(y), z(z) {};

	bool operator>(const �oordinates& rhs) {
		return (x-y-z) > (rhs.x - rhs.y - rhs.z);
	}

	bool operator<(const �oordinates& rhs) {
		return (x - y - z) < (rhs.x - rhs.y - rhs.z);
	}

	bool operator==(const �oordinates& rhs) {
		return (x - y - z) == (rhs.x - rhs.y - rhs.z);
	}

	friend std::ostream& operator<<(std::ostream& os, const �oordinates& c) {
		os << "(" << c.x << ";" << c.y << ";" << c.z << ")";
		return os;
	}

};