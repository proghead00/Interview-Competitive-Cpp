#include <iostream>
using namespace std;

void toh(int  n, char src, char helper, char dest)
{
    if(n==0) // if 0 rings, do nothing
        return;

  
    toh(n-1, src, dest, helper);
    
    cout<< "Moving ring "<< n << " from "<<src<<" to " << dest << endl;

    toh(n-1, helper, src, dest);
}

int main() {
   toh(3,'A','B','C');

   
 }
