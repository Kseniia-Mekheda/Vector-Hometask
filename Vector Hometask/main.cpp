#include "functions.h"
#include "city.h"

int main() {
	cout << "Choose what you want to do: \n 1) scalar product of vectors; \n 2) multiplication of matrices; \n 3) work with vector and custom type City; \n";
	int choise;
	cin >> choise;
	switch (choise)
	{
	case 1:
	{
		cout << "------------ SCALAR PRODUCT OF VECTORS ------------" << endl;
		vector<int> v1(3);
		cout << "Fill in coordinates for your first vector: ";
		fillVector(v1);

		vector<int> v2(3);
		cout << "Fill in coordinates for your second vector: ";
		fillVector(v2);

		cout << "Scalar product of your vectors is: " << scalarProduct(v1, v2) << endl;
		cout << endl;

		break;
	}

	case 2:
	{
		cout << "------------ MULTIPLICATION OF MATRICES ------------" << endl;

		cout << "Enter quality of rows and columns of the first matrix: ";
		int i, j;
		cin >> i >> j;
		vector<vector<int>> m1(i, vector<int>(j));
		fillMatrix(m1);

		cout << "Enter quality of rows and columns of the second matrix: ";
		cin >> i >> j;
		vector<vector<int>> m2(i, vector<int>(j));
		fillMatrix(m2);

		cout << "Your operands for multiplication: " << endl;
		cout << "Matrix A: ";
		printMatrix(m1);
		cout << "Matrix B: ";
		printMatrix(m2);

		vector<vector<int>> result = multiplyMatrix(m1, m2);
		cout << "Result of A * B = " << endl;
		printMatrix(result);

		break;
	}

	case 3:
	{
		cout << "------------ VECTOR WITH ELEMENTS OF OWN TYPE ------------" << endl;
		vector<City> cities1 = readFromFile("data1.txt");
		vector<City> cities2 = readFromFile("data2.txt");
		vector<City> cities3 = readFromFile("data3.txt");

		cout << "Your containers with cities: " << endl;
		cout << "Vector 1: " << endl;
		printVector(cities1); 
		cout << endl;
		cout << "Vector 2: " << endl;
		printVector(cities2); 
		cout << endl;
		cout << "Vector 3: " << endl;
		printVector(cities3); 
		cout << endl;

		system("pause");
		
		cout << "Result of merging of three vectors: " << endl;
		vector<City> merged = mergeVectors(cities1, cities2, cities3);
		printVector(merged);
		cout << endl;

		system("pause");

		cout << "Sorted vector (by the quantity of inhabitants): " << endl;
		sort(merged.begin(), merged.end());
		printVector(merged);
		cout << endl;

		system("pause");

		cout << "Sorted vector (by the quantity of inhabitants) without repeated cities: " << endl;
		auto last = unique(merged.begin(), merged.end());
		merged.erase(last, merged.end());
		printVector(merged);
		cout << endl;

		system("pause");

		cout << "Created vectors with countries of top-3 cities by quality of inhabitants: " << endl;
		cout << endl;
		cout << "Vector with top-1 country: " << endl;
		vector<City> top1 = onlyOneCountry(merged, merged[merged.size() - 1].getCountry());
		printVector(top1);
		cout << endl;

		cout << "Vector with top-2 country: " << endl;
		vector<City> top2 = onlyOneCountry(merged, merged[merged.size() - 2].getCountry());
		printVector(top2);
		cout << endl;

		cout << "Vector with top-3 country: " << endl;
		vector<City> top3 = onlyOneCountry(merged, merged[merged.size() - 3].getCountry());
		printVector(top3);
		cout << endl;

		system("pause");

		cout << endl;
		cout << "Info about all cities of every country: " << endl;
		cout << endl;
		getInfoByCountry(merged);

		break;
	}
	default:
		break;
	}
	
	return 0;
}