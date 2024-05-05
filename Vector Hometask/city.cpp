#include "city.h"

City::City(string country, string name, int inhabitants)
	:city_country(country),
	city_name(name),
	city_inhabitants(inhabitants)
{}

City::City(const City& C)
	:city_country(C.city_country),
	city_name(C.city_name),
	city_inhabitants(C.city_inhabitants)
{}

string City::getCountry() const
{
	return city_country;
}

string City::getName() const
{
	return city_name;
}

int City::getInhabitantsQuantity() const
{
	return city_inhabitants;
}

void City::readFrom(istream& in)
{
	in >> city_name >> city_country >> city_inhabitants;
}

void City::writeTo(ostream& out) const
{
	out << city_name << ", " << city_country << " (" << city_inhabitants << " inhabitants)" << endl;
}

bool City::operator<(const City& C) const
{
	return city_inhabitants < C.city_inhabitants;
}

bool City::operator==(const City& C) const
{
	return city_country == C.city_country && city_name == C.city_name && city_inhabitants == C.city_inhabitants;
}

istream& operator>>(istream& in, City& C)
{
	C.readFrom(in);
	return in;
}

ostream& operator<<(ostream& out, const City& C)
{
	C.writeTo(out);
	return out;
}

vector<City> readFromFile(const string& fileName)
{
	ifstream fin(fileName);
	vector<City> cities;
	while (!fin.eof())
	{
		copy(istream_iterator<City>(fin), istream_iterator<City>(), back_inserter(cities));
	}
	return cities;
}

void printVector(const vector<City>& cities)
{
	copy(cities.cbegin(), cities.cend(), ostream_iterator<City>(cout, ""));
}

vector<City> mergeVectors(vector<City>& first, const vector<City>& second, const vector<City>& third)
{
	first.insert(first.begin(), second.begin(), second.end());
	first.insert(first.end(), third.begin(), third.end());
	return first;
}

vector<City> onlyOneCountry(const vector<City>& general, const string& country)
{
	vector<City> result;
	for (int i = 0; i < general.size(); ++i)
	{
		if (general[i].getCountry() == country)
		{
			result.push_back(general[i]);
		}
	}

	return result;
}

void getInfoByCountry(const vector<City>& general)
{
	vector<string> used;
	int counter = 0;
	int sum = 0;
	while (counter != general.size())
	{
		if (find(used.cbegin(), used.cend(), general[counter].getCountry()) != used.cend())
		{
			++counter;
		}
		else
		{
			cout << "All cities for country " << general[counter].getCountry() << ':' << endl;
			for (int i = 0; i < general.size(); ++i)
			{
				if (general[i].getCountry() == general[counter].getCountry())
				{
					cout << general[i];
					sum += general[i].getInhabitantsQuantity();
				}
			}
			cout << "Inhabitants Quantity: " << sum << endl;
			cout << endl;
			used.push_back(general[counter].getCountry());
			++counter;
			sum = 0;
		}	
	}
}