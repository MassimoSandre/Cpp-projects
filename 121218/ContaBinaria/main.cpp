#include <iostream>

void incrementa(int v[],int i){
  if(i == 8) {
    for(int k=0;k<8;k++) {
      v[k]=0;
    }
  }
  else {
    if(v[i]==0) {
      v[i]=1;
      for(int k=i-1;k>=0;k--){
        v[k]=0;
      }
    }
    else {
      incrementa(v,i+1);
    }
  }
}

int main()
{
    int n = 0;
    int v[8]={0,0,0,0,0,0,0,0};
    for(int i = 0;i<512;i++) {
        for(int j =7;j>=0;j--) {
            printf("%d",v[j]);
        }
        if(n>255) n=0;
        printf("\t%d\n",n++);
        incrementa(v,0);
    }
}
