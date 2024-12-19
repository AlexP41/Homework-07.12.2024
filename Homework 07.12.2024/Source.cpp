/*
�������� 1. �������������� ��� ��������� �� ����� ����� �����, ��������� ���� ����� � �����. 
��������������� � ������� ���������� ��������� ��� ���������� �� ������, � ����� �������� ������������.

�������� 2. �������������� �������� �� ����� ����� �����, ������ ������� ����������� �������� ������ �� �����������.
��������������� � ������� ���������� ��������� ��� ���������� �� ������, � ����� �������� ������������.

�������� 3. �������������� ��� ��������� �� ������ ����� �����, ��������� 
���� ����� � ����� ���, ��� �
������� ����� �������� ����������� � ���������� �������.
��������������� � ������� ���������� ��������� ��� ���������� �� ������, 
� ����� �������� ������������.


��������� ������: ��������� �� GitHub ������ ������
*/
 
#include <iostream>
#include <locale>
#include <iomanip>
#include <ctime>
#include <type_traits>

using namespace std;

void autoFillArray(int length, int* arr);
void outputArray(int length, int number, int* arr);

int main() 
{
	system("chcp 1251>null");
	srand(time(NULL));
	setlocale(LC_ALL, "ukr");

	const int LENGTH = 5 + rand() % 16;


	int* arr1 = new int[LENGTH];
	int* arr2 = new int[LENGTH];

	autoFillArray(LENGTH, arr1);
	outputArray(LENGTH, 1, arr1);

	autoFillArray(LENGTH, arr2);
	outputArray(LENGTH, 2, arr2);

	return 0;
}

void autoFillArray(int length, int* arr)
{
	for (int i = 0; i < length; i++)
	{
		arr[i] = -100 + rand() % 201;
	}
}

void outputArray(int length, int number, int* arr)
{
	cout << "\t\t\t\t\033[033m ��������� ������ " << number << " \033[0m" << endl << endl;
	for (int i = 0; i < length; i++)
	{
		cout << setw(5) << arr[i];
	}
	cout << endl;
}

template <typename typeOfArrayToCopy, typename typeArrayCopyIn>
void copuArrayIntoAnotherArray(typeOfArrayToCopy* arrToCopy, typeArrayCopyIn* arrCopyIn)
{

}


