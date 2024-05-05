#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class City {
private: 
	string city_country;
	string city_name;
	int city_inhabitants;

public:
	City(string country = " ", string name = " ", int inhabitants = 0);
	City(const City& C);
	
	string getCountry() const;
	string getName() const;
	int getInhabitantsQuantity() const;

	void readFrom(istream& in);
	void writeTo(ostream& out) const; 

	bool operator<(const City& C) const;
	bool operator==(const City& C) const;
};

istream& operator>>(istream& in, City& C);
ostream& operator<<(ostream& out, const City& C);

vector<City> readFromFile(const string& fileName);
void printVector(const vector<City>& cities);
vector<City> mergeVectors(vector<City>& first, const vector<City>& second, const vector<City>& third);

vector<City> onlyOneCountry(const vector<City>& general, const string& country);

void getInfoByCountry(const vector<City>& general);
