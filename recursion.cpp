#include <iostream>
using namespace std;

void printNaturals(int n)
{
    if(n > 0){
        printNaturals(n-1);
        cout<<n<<" ";
    }
}

void printNaturalsInReverse(int n){
    if(n > 0)
    {
        cout<<n<<" ";
        printNaturalsInReverse(n-1);
    }
}

void PrintOddNumbers(int n)
{
    if(n >= 1)
    {
        PrintOddNumbers(n-1);
        cout<<n*2-1<<" ";
    }
}

void PrintOddNumberInReverse(int n)
{
    if(n >= 1)
    {
        cout<<n*2-1<<" ";
        PrintOddNumberInReverse(n-1);
    }
}

void PrintEvenNumbers(int n)
{
    if(n >= 1)
    {
        PrintEvenNumbers(n-1);
        cout<<n*2<<" ";
    }
}

void PrintEvenInReverse(int n)
{
    if(n >= 1)
    {
        cout<<n*2<<" ";
        PrintEvenInReverse(n-1);
    }
}

void printSquareNaturals(int n)
{
    if(n > 0){
        printSquareNaturals(n-1);
        cout<<n*n<<" ";
    }
}

void printSquareNaturalsInReverse(int n)
{
    if(n > 0){
        cout<<n*n<<" ";
        printSquareNaturalsInReverse(n-1);
    }
}

int fib(int n)
{
    if((n == 1 || n == 0))
       return n;
    return fib(n-1)+fib(n-1);
}
int main()
{
    cout<<"5th term of fibonacci number is "<<fib(2);
    return 0;
}