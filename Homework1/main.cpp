
#include <iostream>
#include "Process.h"
using namespace std;
int main(void)
{

    //homework 1-1
    try {
        Process* firstProcess=new Process();
        Process* firstProcessChild=firstProcess->createNewChild();
        Process* leftChild=firstProcessChild->createNewChild();
        Process* righChildt=firstProcessChild->createNewChild();
    }
    catch (const char* message)
    {
        cout<<message<<endl;

    }
    //homeWork 1-2
    try {
        Process* firstProcess=new Process();
        firstProcess->createNewChild()->createNewChild()->createNewChild();
    }
    catch (const char* message)
    {
        cout<<message<<endl;

    }
    //homeWork 1-3
    try {
        Process* firstProcess=new Process();
        Process* leftChild=firstProcess->createNewChild();
        Process* rightChild=firstProcess->createNewChild();
        Process* secondProssessRightChild=rightChild->createNewChild();

    }
    catch (const char* message)
    {
        cout<<message<<endl;

    }
    /*moeid commit test  */


    return 0;
}
