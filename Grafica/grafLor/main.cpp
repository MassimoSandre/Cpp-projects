#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
int main()
{
    int n,k,l;

    scanf("%d %d\n",&n,&k);
    string w/*[n]*/;

    /*for(int i = 0; i < n;i++) {
        getline(cin,w[i]);
    }*/

    int inl=0;
    l=0;
    while(n > 0) {
        getline(cin,w);
        if(inl+w/*[l]*/.length() > k) {
            printf("\n");
            inl = 0;
        }
        else {
            cout << w/*[l]*/ << " ";
            inl += w/*[l++]*/.length()+1;
            n--;
        }
    }

    return 0;
}
