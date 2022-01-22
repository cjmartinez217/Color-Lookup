#include "Color.h"
#include <iostream>

void Color::SetValue(int value)
{
	//shift number and get only 8 rightmost bites
	hexVal = "0x000000";
	int tempVal = value & 255;
	getSetColor(tempVal, "blue");
	value = value >> 8;
	tempVal = value & 255;
	getSetColor(tempVal, "green");
	value = value >> 8;
	tempVal = value & 255;
	getSetColor(tempVal, "red");
}

void Color::SetName(const char* name)
{
	this->name = name;
}

//Accessors
unsigned char Color::GetR() const
{
	return red;
}

unsigned char Color::GetG() const
{
	return green;
}

unsigned char Color::GetB() const
{
	return blue;
}

string Color::GetHexValue() const
{
	return hexVal;
}

string Color::GetName() const
{
	return name;
}

unsigned char Color::intToHex(int num)
{
	char tempChar;
	switch (num)
	{
	case 10:
		tempChar = 'A';
		break;
	case 11:
		tempChar = 'B';
		break;
	case 12:
		tempChar = 'C';
		break;
	case 13:
		tempChar = 'D';
		break;
	case 14:
		tempChar = 'E';
		break;
	case 15:
		tempChar = 'F';
		break;
	}
	return tempChar;
}

void Color::getSetColor(unsigned int x, string color)
{
	//converting int to hex
	int num1 = x / 16;
	char char1;
	int num2 = x % 16;
	char char2;
	if (num1 > 9) //check to make sure int isnt a letter in hex
		char1 = intToHex(num1);
	else
		char1 = num1 + '0'; //turn char to int
	if (num2 > 9)
		char2 = intToHex(num2);
	else
		char2 = num2 + '0';
	
	//assign to color depending on which color we are on
	if (color == "red")
	{
		hexVal[2] = char1;
		hexVal[3] = char2;
		red = x;
	}
	if (color == "green")
	{
		hexVal[4] = char1;
		hexVal[5] = char2;
		green = x;
	}
	if (color == "blue")
	{
		hexVal[6] = char1;
		hexVal[7] = char2;
		blue = x;
	}
}