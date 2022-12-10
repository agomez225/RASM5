// Attached: RASM5.cpp, asmBubbleSort.s , asmInsertionSort.s
// ==============================================================
//Program: RASM5
// ===============================================================
//Programmer: Adrian Gomez
//Class: CS3B - 3:30 to 5:30 PM
// ================================================================
//Description:
// This assignment consisted of the creation of a menu driven program in C/C++ that aims
// to demonstrate calling Assembly language macros from C/C++. There is no automatic laoding, only via the menu.
// There is an input file "input.txt" with 200,000 random integers that will be read from.
// Finally, after every sort, an array of sorted numbers will be written to a text file named after it's respective sort
//==================================================================
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <chrono>
#include <string>

using namespace std;

int SIZE = 200000;
extern "C" void asmBubbleSort(int*, int);
extern "C" void asmInsertionSort(int*, int);

long int cBubbleSort(int a[], int length);
long int cInsertionSort(int a[], int length);

long int asmBubbleSortw(int*, int);
long int asmInsertionSortw(int*, int);

void populateArrays(int*, int*, int*, int*, int*, int&);


int main()
{

    int elementCount = 0;
    long int cBubbleTime = 0;
    long int cInsTime = 0;
    long int asmBubbleTime = 0;
    long int asmInsTime = 0;
    char input = '\0';

    int arr[SIZE];
    int asmBubArr[SIZE];
    int asmInsArr[SIZE];
    int cBubArr[SIZE];
    int cInsArr[SIZE];

    

    do
    {
        cout << "\033[2J\033[1;1H";
        cout << "\tRASM5 C vs Assembly\n\tFile Element Count: " << elementCount <<endl;
        cout << "-----------------------------------------------\n";
        cout << "C\t Bubblesort Time: " << cBubbleTime << " secs\n";
        cout << "Assembly Bubblesort Time: " << asmBubbleTime << " secs\n";
        cout << "\nC\t Insertion sort Time: " << cInsTime << " secs\n";
        cout << "Assembly Insertion sort Time: " << asmInsTime << " secs\n";
        cout << "-----------------------------------------------\n";

        cout << "<1> Load input file (integers)\n";
        cout << "<2> Sort using C Bubblesort algorithm\n";
        cout << "<3> Sort using Assembly Bubblesort algorithm\n";
        cout << "<4> Sort using C Insertion sort algorithm\n";
        cout << "<5> Sort using Assembly insertion Sort algorithm\n";
        cout << "<6> Quit\n";
        cout << "\n\tSelect a number: ";

    cin >> input;

    switch (input)
        {
        case '1': populateArrays(arr, asmBubArr, asmInsArr, cBubArr, cInsArr, elementCount);
                  break;
        
        case '2': cBubbleTime = cBubbleSort(cBubArr, SIZE);
                  break;

        case '3': asmBubbleTime = asmBubbleSortw(asmBubArr, SIZE);
                  break;

        case '4': cInsTime = cInsertionSort(cInsArr, SIZE);
                  break;

        case '5': asmInsTime = asmInsertionSortw(asmInsArr, SIZE);
                  break;
        }


    }while (input != '6');

    return 0;
}

long int cBubbleSort (int a[], int length)
{
	int i, j, temp;
	
  auto start = std::chrono::high_resolution_clock::now();

    for (i = 0; i < length; i++)
    {
        for (j = 0; j < length - i - 1; j++)
        {
            if (a[j + 1] < a[j])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);

    ofstream cFile;
    cFile.open("./numbers/cBubbleSort.txt", ios::out | ios::trunc);
    if (cFile.is_open())
    {
        for (i = 0; i < length; i++)
            cFile << a[i] << '\n';

    }
    cFile.close();

return duration.count();

}

long int asmBubbleSortw(int* arr, int size)
{
  auto start = std::chrono::high_resolution_clock::now();
    asmBubbleSort(arr, size);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
    

    ofstream asmFile;
    asmFile.open("./numbers/asmBubbleSort.txt", ios::out | ios::trunc);
    if (asmFile.is_open())
    {
        for (int i = 0; i < size; i++)
            asmFile << arr[i] << '\n';
    }
    asmFile.close();

return duration.count();
}

void populateArrays(int* arr, int* asmBubArray, int* asmInsArray,  int* cBubArray, int* cInsArray,  int& elementCount)
{

    ifstream file;

    int temp =0;
    file.open("./numbers/numbers.txt", ios::in);
    while (!file.eof())
    {
        file >> temp;
        arr[elementCount] = temp;
        elementCount++;
        
    }
    file.close();
    
    for (int i= 0; i < SIZE; i++) 
    {
        asmBubArray[i] = arr[i];
        cBubArray[i] = arr[i];
        asmInsArray[i] = arr[i];
        cInsArray[i] = arr[i];
    }
    elementCount-= 1;
}

long int cInsertionSort (int a[], int length)
{
  auto start = std::chrono::high_resolution_clock::now();
    
  int i, temp, j;
  for (int i = 1; i < length; i++)
  {
      temp = a[i];
      j = i-1;

      while (j >= 0 && temp < a[j])
      {
          a[j+1] = a[j];
          j = j-1;
      }

      a[j+1] = temp;
  }
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);

    ofstream cFile;
    cFile.open("./numbers/cInsertionSort.txt", ios::out | ios::trunc);
    if (cFile.is_open())
    {
        for (i = 0; i < length; i++)
            cFile << a[i] << '\n';

    }
    cFile.close();

return duration.count();

}

long int asmInsertionSortw(int* arr, int size)
{
  auto start = std::chrono::high_resolution_clock::now();
  asmInsertionSort(arr, size);
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
    

    ofstream asmFile;
    asmFile.open("./numbers/asmInsertionSort.txt", ios::out | ios::trunc);
    if (asmFile.is_open())
    {
        for (int i = 0; i < size; i++)
            asmFile << arr[i] << '\n';
    }
    asmFile.close();

return duration.count();
}





