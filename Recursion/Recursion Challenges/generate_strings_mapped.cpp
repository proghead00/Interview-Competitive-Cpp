#include <iostream>
using namespace std;

void gen_string(char *in, char *out, int i, int j)
{
    if(in[i]=='\0'){
        out[j]='\0';
        cout << out<< endl;
        return;
    }

    // single char
    int digit = in[i]-'0';
    char ch = digit + 'A' - 1;
    out[j]=ch;
    gen_string(in, out, i+1, j+1);

    // double
    if(in[i+1]!='\0')
    {
        int second_digit = in[i+1]-'0';
        int no = digit*10 + second_digit;

        if(no<=26)
        {
            ch = no + 'A' - 1;
            out[j]=ch;

            gen_string(in,out,i+2,j+1);

        }
    }
    return;
}


int main() {
    char in[100];
    cin >> in;

    char out[100];
    gen_string(in,out, 0,0);

    

    
}
