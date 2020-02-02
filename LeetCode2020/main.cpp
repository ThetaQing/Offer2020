#include <iostream>
#include <vector>
#include "MyArray.h"
using namespace std;

int main(int argc, char** argv)
{
	vector<int> row1 = { 1,2,3,4,5,6 };
	vector<int> row2 = { 7,8,9,10,11,12 };
	vector<int> row3 = { 13,14,15,16,17,18 };
	vector<vector<int>> myArray = { row1, row2, row3 };
	Find(16,myArray);
	cout << "hello" << endl;
	cin.get();
	
	return 0;
}