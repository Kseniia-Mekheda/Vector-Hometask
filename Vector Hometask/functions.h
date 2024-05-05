#pragma once
#include <iostream>
#include <vector>
using namespace std; 

void fillVector(vector<int>& v);
int scalarProduct(const vector<int>& v1, const vector<int>& v2);

void fillMatrix(vector<vector<int>>& v);
void printMatrix(const vector<vector<int>>& v);
vector<vector<int>> multiplyMatrix(const vector<vector<int>>& v1, const vector<vector<int>>& v2);