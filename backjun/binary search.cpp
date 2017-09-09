//
// Created by 고승빈 on 2017. 9. 5..
//

#include <iostream>
#include <algorithm>
using namespace std;

const int ssize = 100;
int arr[ssize];
int sleft , sright , smid;
int result;

int main()
{
    for(int i = 0 ; i < ssize ; ++i)
    {
        scanf("%d",&arr[i]);
    }

    sort(arr , arr + ssize);

    sleft = 0 , sright = ssize - 1;

    if(arr[sleft] == 8388)  result = sleft;
    else if(arr[sright] == 8388) result = sright;
    else
    {
        while(sleft <= sright)
        {
            smid = (sleft + sright) / 2;

            if(arr[smid] == 8388)
            {
                result = smid;  break;
            }
            else if(arr[smid] < 8388)
            {
                sleft = smid + 1;
            }
            else {
                sright = smid - 1;
            }
        }
    }

    printf("%d\n",result);

    return 0;
}