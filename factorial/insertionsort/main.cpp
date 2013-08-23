#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int arr[4] = {4,1,3,2};
    
    int i, j, tmp;
      for (i = 1; i < 5; i++) {
            j = i;
            for (int t = 0; t <4; t++){
                      cout<<arr[t];}
                      cout<<endl;
            while (j > 0 && arr[j - 1] > arr[j]) {
                  tmp = arr[j];
                  for (int t = 0; t <4; t++){
                      cout<<arr[t];}
                      cout<<endl;
                  arr[j] = arr[j - 1];
                  arr[j - 1] = tmp;
                  j--;
            }
      }
    system("PAUSE");
    return EXIT_SUCCESS;
}
