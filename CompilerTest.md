```C
#include <stdio.h>

int main(void) {
  
    int MRR[] = {0,10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200};//21
    int SRR[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0};//21
    int Q = 16;
    while(Q >= 5)
    {
        SRR[Q--] = MRR[Q--];
    }
    Q = 0;
    while(Q < 21)
    {
        printf("  %d : %d\n",Q,SRR[Q]);
        ++Q;
    }

    return 0;
}
```
![](https://github.com/Tanmoy-Rath/misc/blob/master/CompilerTest.jpg)
