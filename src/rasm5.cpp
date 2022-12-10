#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <chrono>
#include <string>

using namespace std;

int SIZE = 200000;
extern "C" void asmBubbleSort(int*, int);
extern "C" void asmInsertionSort(int*, int);
long int cBubbleSort (int a[], int length);
long int asmBubbleSortw(int*, int);
void populateArrays(int*, int*, int*, int&);


int main()
{

    int elementCount = 0;
    long int cBubbleTime = 0;
    long int asmBubbleTime = 0;
    long int cInsTime = 0;
    long int asmInsTime = 0;
    char input = '\0';

    int arr[SIZE];
    int asmArr[SIZE];
    int cArr[SIZE];

    int testArr[10] = {2, 93, 38, 7, 12, 88, 93, 200, 1, 5};
    
    asmInsertionSort(testArr, 10);

    for (int i = 0; i < 10; i++)
    {
        cout << testArr[i] << endl;
    }


    /*do
    {
        //cout << "\033[2J\033[1;1H";
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
        case '1': populateArrays(arr, asmArr, cArr, elementCount);
                  break;
        
        case '2': cBubbleTime = cBubbleSort(cArr, SIZE);
                  break;

        case '3': asmBubbleTime = asmBubbleSortw(asmArr, SIZE);
                  break;

        case '4': cout << "case 4";
                  break;

        case '5': cout << "case 5";
                  break;
        }


    }while (input != '6');
*/

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
    cFile.open("./numbers/cSorted.txt", ios::out | ios::trunc);
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
    asmFile.open("./numbers/asmSorted.txt", ios::out | ios::trunc);
    if (asmFile.is_open())
    {
        for (int i = 0; i < size; i++)
            asmFile << arr[i] << '\n';
    }
    asmFile.close();

return duration.count();
}

void populateArrays(int* arr, int* asmArr, int* cArr, int&elementCount)
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
        asmArr[i] = arr[i];
        cArr[i] = arr[i];
    }
    elementCount-= 1;
}






