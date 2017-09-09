

#include <iostream>
using namespace std;

int N , M;

int main()
{
    scanf("%d %d" , &N , &M);

    if (N == 1)                 printf("1");
    else if (N == 2 && M < 7)   printf("%d", (M + 1) / 2);
    else if(N == 2 )            printf("4");
    else if(M <= 4)             printf("%d", M);
    else if (M == 5 || M == 6)  printf("4");
    else                        printf("%d", M - 2);

    return 0;

}
