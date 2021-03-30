#include <iostream>
using namespace std;

char table[][10] = {
        " ", ".+@$", "abc", "def", "ghi",
        "jkl" , "mno", "pqrs" , "tuv", "wxyz"
    };

void keymap(char *in, char *out, int i, int j)
{
    
    if(in[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return;
    }

    int digit = in[i]-'0';
    
    // if(digit==0 || digit ==1)
    //     keymap(in, out, i+1, j);

    
    
    for(int k=0; table[digit][k] !='\0' ; k++)
    {
        out[j]=table[digit][k];

        keymap(in,out, i+1, j+1);


    }

    return;

}

int main() {

    char in[100];
    cin >> in;

    char out[1000];
    keymap(in, out, 0, 0);
}
