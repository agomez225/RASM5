#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

extern "C" void asmBubbleSort(int*, int);
extern "C" void asmInsertionSort(int*, int);
void cBubbleSort (int a[], int length);

int main()
{

    int elementCount = 0;
    int cBubbleTime = 0;
    int asmBubbleTime = 0;
    char input = '\0';

    //ifstream 

    int numbers[10] = {83, 2, 94, 5, 20, 8, 25, 9000, 1000, 8347};
    
    asmBubbleSort(numbers, 10);
    //cBubbleSort(numbers, 10);

        for (int i = 0; i < 10; i++)
    {
        cout << numbers[i] << '\n';
    }

    /*do
    {
        //cout << "\033[2J\033[1;1H";
        cout << "\tRASM5 C vs Assembly\n\tFile Element Count: " << elementCount << " secs\n";
        cout << "-----------------------------------------------\n";
        cout << "C\t Bubblesort Time: " << cBubbleTime << " secs\n";
        cout << "Assembly Bubblesort Time: " << asmBubbleTime << " secs\n";
        cout << "-----------------------------------------------\n";

        cout << "<1> Load input file (integers)\n";
        cout << "<2> Sort using C Bubblesort algorithm\n";
        cout << "<3> Sort using Assembly Bubblesort algorithm\n";
        cout << "<4> Sort using C insertionSort algorithm\n";
        cout << "<5> Sort using Assembly insertionSort algorithm\n";
        cout << "<6> Quit\n";
        cout << "\n\tSelect a number: ";

    cin >> input;

    switch (input)
        {
        case '1': cout << "case 1";
                  break;
        
        case '2': cout << "case 2";
                  break;

        case '3': cout << "case 3";
                  break;

        case '4': cout << "case 4";
                  break;

        case '5': cout << "case 5";
                  break;
        }


    }while (input != '6');*/


    return 0;
}

void cBubbleSort (int a[], int length)
{
	int i, j, temp;
	
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
}

