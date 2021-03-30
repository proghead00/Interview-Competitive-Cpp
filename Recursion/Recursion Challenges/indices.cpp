#include <iostream>
using namespace std;

void idx(int *a, int n, int i, int x)
{
    if(n==0)
        return;

    if(a[i]==x)
    {
        cout<<i<<",";
        idx(a,n-1,i+1,x);
    }
    else{
    idx(a,n-1,i+1,x);
}
}

int main() {
   int a[]={1,2,3,2,2,3};
   int x=3;

   idx(a,6,0,x);

   
 }
