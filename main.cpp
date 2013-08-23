/* Martin J. Minaya Palacio
 * Program in C++ to show the difference in time of different types of declarations of array.
 * Types tested: Static, Stack, and Heap.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void static_array();
void stack_array();
void heap_array();
int array_size = 200;
void startTimer();
int stopTimer();

unsigned int timer;
unsigned int timer2;

int main(int argc, char *argv[])
{
     
    cout<<"Static: "<<endl;
    startTimer();
    int i = 0;
    while (i < 100000) {static_array(); i++;} // Loop to call the fucntion 100000 times.
    stopTimer();
    cout<<"Implementation time: "<<timer<<endl;
    
    timer = 0;
    cout<<"Stack: "<<endl;
    startTimer();
    i = 0;
    while (i < 100000) {stack_array(); i++;}
    stopTimer();
    cout<<"Implementation time: "<<timer<<endl;
    
    timer = 0;
    cout<<"Heap: "<<endl;
    startTimer();
    i = 0;
    while (i < 100000) {heap_array(); i++;}
    stopTimer();
    cout<<"Implementation time: "<<timer<<endl;
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

void static_array()
{
     int i = 0;
     static int thestatic_array[200]; // Declaration of a static array in a subprogram
     while (i<array_size)             // Loop to initialize the array.
     {
           thestatic_array[i] = i+1;
           i++;
     } 
     
     while (i>=0)                     // Loop to make time (SAME ON EACH SUBPROGRAM)
     {    
          i--;
     }
}


void stack_array()
{
     int i = 0;
     int thestack_array[array_size]; // Declaration of a stack array in a subprogram
     while (i<array_size)            // Loop to initialize the array.
     {
           thestack_array[i] = i+1;
           i++;
     } 
     
     while (i>=0)
     {    
          i--;
     }
}

void heap_array()
{
     int i = 0;
     int *theheap_array = new int[array_size]; // Declaration of a heap array in a subprogram
     while (i<array_size)                      // Loop to initialize the array.
     {
           theheap_array[i] = i+1;
           i++;
     } 
     
     while (i>=0)
     {    
          i--;
     }
     delete [] theheap_array;
}

void startTimer()                              // Subprogram that starts the timer to meassure the time
{
    timer = clock();
}
 
int stopTimer()                               // Subprogram that stops the timer and calculate the time of execution
{
    timer2 = clock();
    timer = difftime(timer2, timer);
    return timer;
}
