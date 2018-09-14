//
// Created by 고승빈 on 2018. 9. 13..
//

#include <iostream>
#include <string.h>
using namespace std;

typedef struct member {
    int age;
    char name[101];
} Member;
Member members[100001];

void sort(int start, int end, Member sections[]);

int main() {
    int N;
    cin >> N;

    for(int i = 1; i <= N; ++i) {
        cin >> members[i].age >> members[i].name;

    }

    Member* acceptedMembers = new Member[ N + 1 ];
    sort(1, N, acceptedMembers);
    for(int i = 1; i <= N; ++i) {
        cout << acceptedMembers[i].age << " " << acceptedMembers[i].name << "\n";

    }


    return 0;
}

bool compare(Member a, Member b) {
    return a.age <= b.age;

}

void assign(Member* a, Member* b) {
    a->age = b->age;
    strcpy(a->name, b->name);

}



void sort(int start, int end, Member sections[]) {
    if(start == end)  {
        assign(&sections[1], &members[start]);
        return;

    }

    int mid = (start + end) / 2;
    int aCnt = mid - start + 1;
    int bCnt = end - mid;
    Member* aMembers = new Member[ aCnt + 1 ];
    Member* bMembers = new Member[ bCnt + 1 ];
    sort(start, mid, aMembers);
    sort(mid + 1, end, bMembers);

    int firstIdx = 1;
    int secondIdx = 1;
    int idx = 1;
    while(firstIdx <= aCnt || secondIdx <= bCnt) {
        if(firstIdx > aCnt) {
            assign(&sections[idx], &bMembers[secondIdx]);
            secondIdx++;

        } else if(secondIdx > bCnt) {
            assign(&sections[idx], &aMembers[firstIdx]);
            firstIdx++;

        } else {
            if(compare(aMembers[firstIdx], bMembers[secondIdx])) {
                assign(&sections[idx], &aMembers[firstIdx]);
                firstIdx++;

            } else {
                assign(&sections[idx], &bMembers[secondIdx]);
                secondIdx++;

            }

        }

        idx++;

    }

}