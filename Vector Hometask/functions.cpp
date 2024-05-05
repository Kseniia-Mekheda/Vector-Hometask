#include "functions.h"

void fillVector(vector<int>& v)
{
	int coord;
	for (int i = 0; i < v.size(); ++i)
	{
		cin >> coord;
		v[i] = coord;
	}
}

int scalarProduct(const vector<int>& v1, const vector<int>& v2)
{
	int scalarProd = 0;
	for (int i = 0; i < v1.size(); ++i)
	{
		scalarProd += v1[i] * v2[i];
	}
	return scalarProd;
}

void fillMatrix(vector<vector<int>>& v)
{
	cout << "Fill in elements: ";
	int elem;
	int i = v.size();
	int j = v[0].size();
	for (int row = 0; row < i; ++row)
	{
		for (int col = 0; col < j; ++col)
		{
			cin >> elem;
			v[row][col] = elem;
		}
	}
}

void printMatrix(const vector<vector<int>>& v)
{
	int i = v.size();
	int j = v[0].size();
	for (int row = 0; row < i; ++row)
	{
		for (int col = 0; col < j; ++col)
		{
			cout << v[row][col] << ' ';
		}
		cout << endl;
	}
}

vector<vector<int>> multiplyMatrix(const vector<vector<int>>& v1, const vector<vector<int>>& v2)
{
	vector<vector<int>> result(v1.size(), vector<int>(v2[0].size()));

	for (int i = 0; i < v1.size(); ++i) {
		for (int j = 0; j < v2[0].size(); ++j) {
			for (int k = 0; k < v1[0].size(); ++k) {
				result[i][j] += v1[i][k] * v2[k][j];
			}
		}
	}

	return result;
}