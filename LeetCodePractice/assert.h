#pragma once
#include<vector>
#include<string>
using namespace std;

class Assert {
public:
	static void assertVector(vector<string> source, string dst[], int size);
	static void assertInt(int src, int dst);
};