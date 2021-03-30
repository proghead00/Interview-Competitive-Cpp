#include <iostream>
using namespace std;

void str_subsequence(char *in, char *out, int i, int j)
{
    if(in[i] =='\0')
    {
        out[j]='\0';
        cout << out <<",";
        return;
    }

    // include curr character
    out[j]=in[i];
    str_subsequence(in, out, i+1, j+1);

    // exclude curr char
    str_subsequence(in,out, i+1, j);
}

int main() {

    char in[]="abc";
    char out[10];

    str_subsequence(in,out,0,0);

    

    
}
