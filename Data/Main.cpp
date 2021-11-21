#include "Data.h"
using namespace std;
int main()
{
	Data data;
	Data dataNew(31, 12, 2021);
	Data dataMuch(40, 15, 2020);
	Data dataLeap(60, 1, 2024);
	Data dataNotLeap(60, 1, 2025);
	Data dataSmall (1, 1, 2000);
	Data dataMidle(31, 12, 2010);
	Data dataLarge(31, 12, 2100);
	cout << data << "\n";
	cout << dataNew << "\n";
	cout << dataMuch << "\n";
	cout << dataLeap << "\n";
	cout << dataNotLeap << "\n";
	cout << data << "\n";
	//cin >> data;
	//data = data + 365;
	data = dataNew;
	cout << data << "\n";
//Тестируем операции == и !=
	if (data == dataNew)
		cout << "Work";
	else 
		cout << "Dont Work";
	cout << "\n";
	if (data != dataMuch)
		cout << "Work";
	else
		cout << "Dont Work";
	cout << "\n";
//Тестируем операции > и <
	if (dataMidle > dataSmall)
		cout << "Work";
	else
		cout << "Dont Work";
	cout << "\n";
	if (dataMidle < dataLarge)
		cout << "Work";
	else
		cout << "Dont Work";
	cout << "\n";
//Тестируем операции >= и <=
	if (dataMidle >= dataSmall && dataMidle >= dataMidle)
		cout << "Work";
	else
		cout << "Dont Work";
	cout << "\n";
	if (dataMidle <= dataLarge && dataMidle <= dataMidle)
		cout << "Work";
	else
		cout << "Dont Work";
	cout << "\n";
//Тестируем операции ++ и --
	Data dataLow;
	cout << dataLow << "\n";
	cout << dataLow-- << " Date befor -- \n";
	cout << dataLow++ << " Date befor ++ \n";
	cout << dataLow << "\n";
	cout << --dataLow << " Date after -- \n";
	cout << ++dataLow << " Date after ++ \n";
	cout << dataLow << "\n";
	system("pause");
	return 0;
}