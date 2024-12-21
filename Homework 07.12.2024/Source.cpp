/*
Завдання 1. Використовуючи два покажчики на масив цілих чисел, скопіювати один масив у інший. 
Використовувати в програмі арифметику покажчиків для просування по масиву, а також оператор розіменування.

Завдання 2. Використовуючи покажчик на масив цілих чисел, змінити порядок проходження елементів масиву на протилежний.
Використовувати в програмі арифметику покажчиків для просування по масиву, а також оператор розіменування.

Завдання 3. Використовуючи два покажчики на масиви цілих чисел, скопіювати 
один масив у інший так, щоб у
другому масиві елементи знаходилися у зворотному порядку.
Використовувати в програмі арифметику покажчиків для просування по масиву, 
а також оператор розіменування.


Результат роботи: посилання на GitHub вашого проєкта
*/
 
#include <iostream>
#include <locale>
#include <iomanip>
#include <ctime>
#include <type_traits>

using namespace std;

void autoFillArray(int length, int* arr);
void outputArray(int length, int number, int* arr);

template <typename typeOfArrayToCopy, typename typeArrayCopyIn>
void copyArrayIntoAnotherArray(int lengthOfArrays, typeOfArrayToCopy* arrToCopy, typeArrayCopyIn* arrCopyIn);

template <typename typeOfArray>
void invertArray(int lengthOfArray, int number, typeOfArray* array);

int main() 
{
	system("chcp 1251>null");
	srand(time(NULL));
	setlocale(LC_ALL, "ukr");

	cout << "\t\t\t\t\t\033[035mЗАВДАННЯ 1\033[0m" << endl << endl;

	const int LENGTH = 5 + rand() % 16;


	int* arr1 = new int[LENGTH];
	int* arr2 = new int[LENGTH];

	autoFillArray(LENGTH, arr1);
	outputArray(LENGTH, 1, arr1);

	autoFillArray(LENGTH, arr2);
	outputArray(LENGTH, 2, arr2);

	char* arr3 = new char[4] { 'c', 'b', '+'};


	copyArrayIntoAnotherArray(LENGTH, arr1, arr2);

	cout << endl << "\033[033mДані масиву arr1 скопійовані у масив arr2: \033[0m" << endl << endl;
	outputArray(LENGTH, 1, arr1);
	outputArray(LENGTH, 2, arr2);




	cout << endl << endl << endl << "\t\t\t\t\t\033[035mЗАВДАННЯ 2\033[0m" << endl << endl;

	const int LENGTH_2_1 = 5 + rand() % 16;

	int* arr_2_1 = new int[LENGTH_2_1];

	autoFillArray(LENGTH_2_1, arr_2_1);
	outputArray(LENGTH_2_1, 1, arr_2_1);

	invertArray(LENGTH_2_1, 1, arr_2_1);




	cout << endl << endl << endl << "\t\t\t\t\t\033[035mЗАВДАННЯ 3\033[0m" << endl << endl;

	const int LENGTH_3 = 5 + rand() % 16;


	int* arr_3_1 = new int[LENGTH_3];
	int* arr_3_2 = new int[LENGTH_3];

	autoFillArray(LENGTH_3, arr_3_1);
	outputArray(LENGTH_3, 1, arr_3_1);

	autoFillArray(LENGTH_3, arr_3_2);
	outputArray(LENGTH_3, 2, arr_3_2);

	copyArrayIntoAnotherArray(LENGTH, arr_3_1, arr_3_2);
	invertArray(LENGTH_3, 2, arr_3_2);
	cout << endl << "\033[033mДані масиву arr_3_1 скопійовані навпаки у масив arr_3_2: \033[0m" << endl << endl;
	outputArray(LENGTH_3, 1, arr_3_1);
	outputArray(LENGTH_3, 2, arr_3_2);







	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr_2_1;
	delete[] arr_3_1;
	delete[] arr_3_2;

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
	cout << endl << "\t\t\t\t\033[033m Виведення масиву " << number << " \033[0m" << endl << endl;
	for (int i = 0; i < length; i++)
	{
		cout << setw(5) << arr[i];
	}
	cout << endl;
}

template <typename typeOfArrayToCopy, typename typeArrayCopyIn>
void copyArrayIntoAnotherArray(int lengthOfArrays, typeOfArrayToCopy* arrToCopy, typeArrayCopyIn* arrCopyIn)
{
	if ( ! is_same_v<decltype(arrToCopy), decltype(arrCopyIn)>)
	{
		cout << "\n\033[031mТипи масивів не співпадають!\033[0m" << endl;
		return;
	}

	

	typeOfArrayToCopy* ptrFor_arrToCopy = &arrToCopy[0];
	typeArrayCopyIn* ptrFor_arrCopyIn = &arrCopyIn[0];


	for (int i = 0; i < lengthOfArrays; i++)
	{
		*ptrFor_arrCopyIn = *ptrFor_arrToCopy; 
		ptrFor_arrCopyIn++;                   
		ptrFor_arrToCopy++;                  
	}

	cout << endl << "\033[032mМасиви успішно скопійовано.\033[0m" << endl;
}

template <typename typeOfArray>
void invertArray(int lengthOfArray, int number, typeOfArray* array)
{
	typeOfArray* ptr = array;

		for (int i = lengthOfArray-1; i >= lengthOfArray / 2; i--)
		{
			typeOfArray* auxptr = &array[i];
			typeOfArray temp = *auxptr;
			*auxptr = *ptr;
			*ptr = temp;
			ptr++;
		}
		
		cout <<endl << endl << "\033[033mМасив \"навпаки\":\033[0m" << endl;

		outputArray(lengthOfArray, number, array);
	
}
