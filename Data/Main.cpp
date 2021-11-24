#include "Data.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "ѕровер¤ем ввод дат и коректоность их перевода\n\n\n";
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
	cout << "К дате " << data << " прибовляем 365 дней\n";
	data = data + 365;
	cout << data << "\n\n\n";
	cout << "Дату " << data << " сделаем равно " << dataNew << "\n\n\n";
	data = dataNew;
	cout << data << "\n\n\n";
	cout << "Тестируем операции == и !=" << "\n";
	if (data == dataNew)
		cout << "== работает";
	else 
		cout << "== не  работает";
	cout << "\n";
	if (data != dataMuch)
		cout << "!= работает";
	else
		cout << "!= не работает";
	cout << "\n";
	cout << "Тестируем операции > и <" << "\n";
	if (dataMidle > dataSmall)
		cout << "> работает";
	else
		cout << "> работает";
	cout << "\n";
	if (dataMidle < dataLarge)
		cout << "< работает";
	else
		cout << "< работает";
	cout << "\n";
	cout << "Тестируем операции >= и <=" << "\n";
	if (dataMidle >= dataSmall && dataMidle >= dataMidle)
		cout << ">= работает";
	else
		cout << ">= не работает";
	cout << "\n";
	if (dataMidle <= dataLarge && dataMidle <= dataMidle)
		cout << "<= работает";
	else
		cout << "<= не работает";
	cout << "\n";
	cout << "Тестируем операции ++ и --" << "\n";
	Data dataLow;
	cout << dataLow << " начальная \n";
	cout << dataLow-- << " дата до -- \n";
	cout << dataLow++ << " дата до ++ \n";
	cout << dataLow << " дата после изменений\n";
	cout << --dataLow << " дата после -- \n";
	cout << ++dataLow << " дата после ++ \n";
	cout << dataLow << " итоговая дата\n";
	system("pause");
	return 0;
}