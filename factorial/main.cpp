#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;
double factorial_I(int n);
double factorial_R(int n);

int main(int argc, char *argv[])
{
    clock_t start, end;
    double elapsed;
     
    cout<<"Iterative: "<<endl;
    double test = 0;
    start = clock();
    test = factorial_I(20);
    end = clock();
    cout<<test<<endl;
    elapsed = (end-start);
    cout<<"Implementation time: "<<elapsed<<endl;
    
    cout<<endl<<"Recursive: "<<endl;
    test = 0;
    start = clock();
    test = factorial_R(20);
    end = clock();
    cout<<test<<endl;
    elapsed = (end-start);
    cout<<"Implementation time: "<<elapsed<<endl;
    
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
