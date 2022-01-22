#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <map>
#include "Color.h"
using namespace std;

void ReadFile(const char* filename, map<string, Color>& colors);
void PrintColors(const map<string, Color>& colors);
void PrintColor(const Color& color);
void SearchForColor(map<string, Color>& colors);

int main()
{
	cout << "1-6: Load colors1/2/3/4/5/6.txt" << endl;
	cout << "7. Load all 6 files" << endl;
	int choice;
	cin >> choice;

	map<string, Color> colors;
	if (choice >= 1 && choice <= 6)
	{
		string file = "colors" + to_string(choice) + ".txt";
		ReadFile(file.c_str(), colors);
	}
	else if (choice == 7)
	{
		for (int i = 1; i <= 6; i++)
		{
			string file = "colors" + to_string(i) + ".txt";
			ReadFile(file.c_str(), colors);
		}

	}

	// Secondary menu
	cout << "1. Show all colors" << endl;
	cout << "2. Search for a color" << endl;
	cin >> choice;

	if (choice == 1)
		PrintColors(colors);
	else if (choice == 2)
		SearchForColor(colors);
	return 0;
}

void ReadFile(const char* filename, map<string, Color>& colors)
{
	// TODO: Read the file, create and store some Color objects
	string colorName;
	int colorValue;
	ifstream inFile(filename);
	if (inFile.is_open())
	{
		while (inFile >> colorName)
		{
			Color color;
			inFile >> colorValue;
			char* newString = new char[colorName.size() + 1];
			for (unsigned int i = 0; i < colorName.size(); i++)
			{
				newString[i] = colorName[i];
			}
			newString[colorName.size()] = '\0';
			color.SetName(newString);
			delete[] newString;
			color.SetValue(colorValue);
			colors.emplace(colorName, color);
		}
	}
	inFile.close();
}
void PrintColors(const map<string, Color>& colors)
{
	// TODO: iterate through all entries in the map and print each color, one at a time
	// Print out the color count afterward
	map<string, Color>::const_iterator iter;
	for (iter = colors.begin(); iter != colors.end(); iter++)
		PrintColor(iter->second);
	cout << "Number of colors: " << colors.size() << endl;
}
void PrintColor(const Color& color)
{
	cout << left << setw(20) << color.GetName();
	cout << right << setw(10) << color.GetHexValue();
	cout << "\t\t" << (int)color.GetR() << "," << (int)color.GetG() << "," << (int)color.GetB() << endl;
}
void SearchForColor(map<string, Color>& colors)
{
	// TODO: Get some input, check if that key exists, then print out the color (or an error message)
	string key;
	cin >> key;
	map<string, Color>::const_iterator iter;
	if (colors.find(key) == colors.end())
		cout << key << " not found!\n";
	else
	{
		iter = colors.find(key);
		PrintColor(iter->second);
	}
}

