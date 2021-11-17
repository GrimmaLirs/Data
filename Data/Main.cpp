#include "Data.h"
using namespace std;
int main()
{
	Data data;
	Data dataNew(31, 12, 2021);
	Data dataMuch(40, 15, 2020);
	Data dataLeap(60, 1, 2024);
	Data dataNotLeap(60, 1, 2025);
	cout << data << "\n";
	cout << dataNew << "\n";
	cout << dataMuch << "\n";
	cout << dataLeap << "\n";
	cout << dataNotLeap << "\n";
	system("pause");
	return 0;
}