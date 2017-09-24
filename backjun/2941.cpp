//
// Created by 고승빈 on 2017. 9. 24..
//

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int total = 0 , len;
    char input[100];

    scanf("%s", &input);

    len = strlen(input);

    for(int i = 0 ; i < len ; )
    {
        if(i == len - 1)     ++total;
        else if(input[i] == 'c')
        {
            if(input[i+1] == '=' || input[i+1] == '-')  ++i;

            ++total;
        }
        else if(input[i] == 'd')
        {
            if(i < len - 2)
            {
                if(input[i+1] == 'z' && input[i+2] == '=')  i += 2;
                else if(input[i+1] == '-')  ++i;
            }
            else
            {
                if(input[i+1] == '-')   ++i;
            }

            ++total;
        }
        else if(input[i] == 'l')
        {
            if(input[i+1] == 'j')   ++i;

            ++total;
        }
        else if(input[i] == 'n')
        {
            if(input[i+1] == 'j')   ++i;

            ++total;
        }
        else if(input[i] == 's')
        {
            if(input[i+1] == '=')   ++i;

            ++total;
        }
        else if(input[i] == 'z')
        {
            if(input[i+1] == '=')   ++i;

            ++total;
        }
        else
        {
            ++total;
        }

        ++i;
    }

    printf("%d\n" , total);

    return 0;
}