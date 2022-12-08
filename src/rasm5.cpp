#include <iostream>
#include <stdlib.h>

using namespace std;

extern "C" void asmBubbleSort(char*, int);
extern "C" void asmInsertionSort(char*, int);

int main()
{

int elementCount = 0;
int cBubbleTime = 0;
int asmBubbleTime = 0;
char input = '\0';

    do
    {
        cout << "\033[2J\033[1;1H";
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
    }while (input != '6');


    return 0;
}
