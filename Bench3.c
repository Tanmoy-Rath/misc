#include <stdio.h>
#include <string.h>// for memset


#include <conio.h>
void PRINT(long* s, size_t L){
    long I = 0;
    printf("\n\n");
    while(I < L)
    {
        printf(" %ld",*(s+I));
        I++;
    }
    printf("\n\n ...press to continue...");
    //getch();
}
long* Radix_18_ac_long(long *A, size_t N, long *Temp){
    // optimization points in comments, start wits OPSC
    long Z1[256] ;
    long Z2[256] ;
    long Z3[256] ;
    long Z4[256] ;
    memset(Z1, 0, 256*sizeof(long)) ;
    memset(Z2, 0, 256*sizeof(long)) ;
    memset(Z3, 0, 256*sizeof(long)) ;
    memset(Z4, 0, 256*sizeof(long)) ;
    int Jump, Jump2, Jump3, Jump4;
    // Sort-circuit set-up
    Jump = (*A) & 255 ;
    Z1[Jump] = 1;
    Jump2 = (*A >> 8) & 255 ;
    Z2[Jump2] = 1;
    Jump3 = (*A >> 16) & 255 ;
    Z3[Jump3] = 1;
    Jump4 = (*A >> 24) & 255 ;
    Z4[Jump4] = 1;

    // Frequency distribution creation
    long *swp ;
    long *i = A + N;
    while(--i != A){
        ++Z1[(*i) & 255];
        ++Z2[(*i >> 8) & 255];
        ++Z3[(*i >> 16) & 255];
        ++Z4[(*i >> 24) & 255];
    }

    // 1st LSB byte sort
    if( Z1[Jump] == N );
    else
    {
        i = Z1 ;
        swp = Z1 + 256 ;
        while(++i != swp){
            *i = *(i-1) + *i ;
        }
        i = A + N ;
        while(i != A){
            --i;
            *(--Z1[(*i) & 255] + Temp) = *i ;
            //*(--Z1[*i & 255] + Temp) = *(--i) ;
        }
        A = Temp ;
        Temp = i ;
    }

    // 2nd LSB byte sort
    if( Z2[Jump2] == N );
    else
    {
        i = Z2 ;
        swp = Z2 + 256 ;
        while(++i != swp){
            *i = *(i-1) + *i ;
        }
        i = A + N ;
        while(i != A){
            --i ;
            *(--Z2[(*i >> 8) & 255] + Temp) = *i ;
            //*(--Z2[(*i >> 8) & 255] + Temp) = *(--i) ;
        }
        A = Temp ;
        Temp = i ;
    }

    // 3rd LSB byte sort
    if( Z3[Jump3] == N );
    else
    {
        i = Z3 ;
        swp = Z3 + 256 ;
        while(++i != swp){
            *i = *(i-1) + *i ;
        }
        i = A + N ;
        while(i != A){
            --i ;
            *(--Z3[(*i >> 16) & 255] + Temp) = *i ;
            //*(--Z3[(*i >> 16) & 255] + Temp) = *(--i) ;
        }
        A = Temp ;
        Temp = i ;
    }
    // 4th LSB byte sort & -ve numbers sort
    if( Z4[Jump4] == N );
    else
    {
        i = Z4 + 128 ;
        swp = Z4 + 256 ;
        while(++i != swp){
            *i = *(i-1) + *i ;
        }
        *Z4 = *Z4 + *(Z4+255) ;
        i = Z4 ;
        swp = Z4 + 128 ;
        while(++i != swp){
            *i = *(i-1) + *i ;
        }
        i = A + N ;
        while(i != A){
            --i ;
            *(--Z4[(*i >> 24) & 255] + Temp) = *i ;
            //*(--Z4[(*i >> 24) & 255] + Temp) = *(--i) ;
        }
        return Temp ;
    }

    return A;
}
long* Radix_10_ac_long(long *A, size_t N, long *Temp){
    // optimization points in comments, start wits OPSC
    long Z1[256] ;
    long Z2[256] ;
    long Z3[256] ;
    long Z4[256] ;
    memset(Z1, 0, 256*sizeof(long)) ;
    memset(Z2, 0, 256*sizeof(long)) ;
    memset(Z3, 0, 256*sizeof(long)) ;
    memset(Z4, 0, 256*sizeof(long)) ;
    size_t Jump, Jump2, Jump3, Jump4;
    // Sort-circuit set-up
    Jump = *A & 255 ;
    Z1[Jump] = 1;
    Jump2 = (*A >> 8) & 255 ;
    Z2[Jump2] = 1;
    Jump3 = (*A >> 16) & 255 ;
    Z3[Jump3] = 1;
    Jump4 = (*A >> 24) & 255 ;
    Z4[Jump4] = 1;
    // Frequency distribution creation
    long *swp = A + N;
    long *i = A + 1;
    for( ; i != swp ; ++i)
    {
        ++Z1[*i & 255];
        ++Z2[(*i >> 8) & 255];
        ++Z3[(*i >> 16) & 255];
        ++Z4[(*i >> 24) & 255];
    }
    // 1st LSB byte sort
    if( Z1[Jump] == N );
    else
    {
        swp = Z1+256 ;
        for( i = Z1+1 ; i != swp ; ++i )
        {
            *i = *(i-1) + *i;
        }
        swp = A-1;
        for( i = A+N-1 ; i != swp ; --i )
        {
            *(--Z1[*i & 255] + Temp) = *i;
        }
        swp = A;
        A = Temp;
        Temp = swp;
    }
    // 2nd LSB byte sort
    if( Z2[Jump2] == N );
    else
    {
        swp = Z2+256 ;
        for( i = Z2+1 ; i != swp ; ++i )
        {
            *i = *(i-1) + *i;
        }
        swp = A-1;
        for( i = A+N-1 ; i != swp ; --i )
        {
            *(--Z2[(*i >> 8) & 255] + Temp) = *i;
        }
        swp = A;
        A = Temp;
        Temp = swp;
    }
    // 3rd LSB byte sort
    if( Z3[Jump3] == N );
    else
    {
        swp = Z3 + 256 ;
        for( i = Z3+1 ; i != swp ; ++i )
        {
            *i = *(i-1) + *i;
        }
        swp = A-1;
        for( i = A+N-1 ; i != swp ; --i )
        {
            *(--Z3[(*i >> 16) & 255] + Temp) = *i;
        }
        swp = A;
        A = Temp;
        Temp = swp;
    }
    // 4th LSB byte sort and negative numbers sort
    if( Z4[Jump4] == N );
    else
    {
        swp = Z4 + 256 ;
        for( i = Z4+129 ; i != swp ; ++i )// -ve values frequency starts after 895, i.e at 896 ( = 768 + 128 )
        {
            *i = *(i-1) + *i;
        }
        *Z4 = *Z4 + *(Z4+255) ;
        swp = Z4 + 128 ;
        for( i = Z4+1 ; i != swp ; ++i )
        {
            *i = *(i-1) + *i;
        }
        swp = A - 1;
        for( i = A+N-1 ; i != swp ; --i )
        {
            *(--Z4[(*i >> 24) & 255] + Temp) = *i;
        }
        return Temp;
    }
    return A;
}
int main(){
    long arr[] = {2147483647,2147483646,2147483645,16777218,16777217,16777216,16777215,16777214,16777213,65538,65537,65536,65535,65534,65533,258,257,256,255,254,253,2,1,0,-1,-2,-3,-2147483646,-2147483647,-2147483648};
    //long arr[] = {16777215,16777214,16777213,65538,65537,65536,65535,65534,65533,258,257,256,255,254,253,2,1,0};
    //long arr[] = {65535,65534,65533,258,257,256,255,254,253,2,1,0};

    //long arr[] = {255,254,253};
    size_t ln = sizeof(arr)/sizeof(arr[0]);
    long brr[ln];
    long *ast;
    PRINT(arr,ln);
    ast = Radix_10_ac_long(arr, ln, brr);
    PRINT(ast,ln);
    printf("\n** %u  ....END...\n",ln);
    //getch();

    return 0;
}
