#include "Data.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "��������� ���� ��� � ������������ �� ��������\n\n\n";
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
	cout << "� ���� " << data << " ���������� 365 ����\n";
	data = data + 365;
	cout << data << "\n\n\n";
	cout << "���� " << data << " ������� ����� " << dataNew << "\n\n\n";
	data = dataNew;
	cout << data << "\n\n\n";
	cout << "��������� �������� == � !=" << "\n";
	if (data == dataNew)
		cout << "== ��������";
	else 
		cout << "== ��  ��������";
	cout << "\n";
	if (data != dataMuch)
		cout << "!= ��������";
	else
		cout << "!= �� ��������";
	cout << "\n";
	cout << "��������� �������� > � <" << "\n";
	if (dataMidle > dataSmall)
		cout << "> ��������";
	else
		cout << "> ��������";
	cout << "\n";
	if (dataMidle < dataLarge)
		cout << "< ��������";
	else
		cout << "< ��������";
	cout << "\n";
	cout << "��������� �������� >= � <=" << "\n";
	if (dataMidle >= dataSmall && dataMidle >= dataMidle)
		cout << ">= ��������";
	else
		cout << ">= �� ��������";
	cout << "\n";
	if (dataMidle <= dataLarge && dataMidle <= dataMidle)
		cout << "<= ��������";
	else
		cout << "<= �� ��������";
	cout << "\n";
	cout << "��������� �������� ++ � --" << "\n";
	Data dataLow;
	cout << dataLow << " ��������� \n";
	cout << dataLow-- << " ���� �� -- \n";
	cout << dataLow++ << " ���� �� ++ \n";
	cout << dataLow << " ���� ����� ���������\n";
	cout << --dataLow << " ���� ����� -- \n";
	cout << ++dataLow << " ���� ����� ++ \n";
	cout << dataLow << " �������� ����\n";
	system("pause");
	return 0;
}