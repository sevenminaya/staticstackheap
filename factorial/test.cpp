#include <windows.h>
#include <iostream>

using namespace std;
double factorial_I(int n);
double factorial_R(int n);

double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
        cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

int main()
{
    StartCounter();
    cout<<"Iterative: "<<endl;
    double test = 0;
    test = factorial_I(100);
    cout<<test<<endl;
    cout<<"Implementation time: "<<GetCounter()<<endl;

    StartCounter();
    cout<<endl<<"Recursive: "<<endl;
    test = 0;
    test = factorial_R(100);
    cout<<test<<endl;
    cout<<"Implementation time: "<<GetCounter()<<endl;
   
    system("PAUSE");
    return EXIT_SUCCESS;
    
}

double factorial_I(int n)
{
    double fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
   
    return fact;
}
double factorial_R(int n)
{
    if (n <= 1)
       return 1;
    else
       return n * factorial_R(n-1);
}
