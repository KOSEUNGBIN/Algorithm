//
// Created by 고승빈 on 2017. 8. 7..
//

#include <iostream>
#include <string>
#include <functional>
#include <set>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    int N;
    string name , state;

    cin >> N;

    set<string , greater<string>> company;

    for(int i = 0 ; i < N; ++i)
    {
        cin >> name >> state;
        if(company.find(name) == company.end()) company.insert(name);
        else                                    company.erase(name);

    }

    for(set<string>::iterator iter = company.begin() ; iter != company.end() ; ++iter)  cout << *iter << "\n";



    return 0;
}
