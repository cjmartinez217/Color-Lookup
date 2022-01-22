#pragma once
#include <string>
using namespace std;

class Color
{
	string name, hexVal;
	unsigned char red, green, blue;

	// Helper functions
	unsigned char intToHex(int num);
	void getSetColor(unsigned int x, string color);

public:
	// Given an integer value, convert it to RGB and Hex values
	void SetValue(int value);
	void SetName(const char* name);

	// Accessors
	unsigned char GetR() const;
	unsigned char GetG() const;
	unsigned char GetB() const;
	string GetHexValue() const;
	string GetName() const;
};

