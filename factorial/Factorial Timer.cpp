#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;
long double factorial_I(int n);
long double factorial_R(int n);

int main(int argc, char *argv[])
{
    clock_t start, end;
    double elapsed;
     
    cout<<"Iterative: "<<endl;
    long double test = 0;
    start = clock();
    for (int k=0;k<100000;k++)
    {
        test = factorial_I(100);
        }
    end = clock();
    cout<<test<<endl;
    elapsed = (double(end-start)/CLOCKS_PER_SEC);
    cout<<"Implementation time: "<<elapsed<<endl;
    
    cout<<endl<<"Recursive: "<<endl;
    test = 0;
    start = clock();
    for (int k=0;k<100000;k++)
        test = factorial_R(100);
        
    end = clock();
    cout<<test<<endl;
    elapsed = (double(end-start)/CLOCKS_PER_SEC);
    cout<<"Implementation time: "<<elapsed<<endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

long double factorial_I(int n)
{
    long double fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
   
    return fact;
}
long double factorial_R(int n)
{
    if (n <= 1)
       return 1;
    else
       return n * factorial_R(n-1);
}
