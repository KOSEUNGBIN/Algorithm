//
// Created by 고승빈 on 2018. 6. 2..
//

#include <iostream>
#include <string.h>
using namespace std;

struct Student {
    char name[10];
    int kor;
    int eng;
    int math;
};

int main() {
    ios::sync_with_stdio(false);
    int N;
    scanf("%d", &N);
    Student students[N];
    for(int i = 0; i < N; ++i) {
        scanf("%s %d %d %d %d",students[i].name, &students[i].kor, &students[i].eng, &students[i].math);
    }

    Student cur;
    for(int i = 1; i < N; ++i) {
        cur = students[i];
        int index = i - 1;
        while(index >= 0) {
            if(cur.kor > students[index].kor) {
                students[index + 1] = students[index];
                index--;
            } else if(cur.kor < students[index].kor) {
                break;
            } else if(cur.eng < students[index].eng) {
                students[index + 1] = students[index];
                index--;
            } else if(cur.eng > students[index].eng) {
                break;
            } else if(cur.math > students[index].math) {
                students[index + 1] = students[index];
                index--;
            } else if(cur.math < students[index].math) {
                break;
            } else if(strcmp(cur.name, students[index].name) < 0){
                students[index + 1] = students[index];
                index--;
            } else {
                break;
            }
        }

        students[index + 1] = cur;
    }

    for(int i = 0; i < N; ++i) {
        printf("%s\n", students[i].name);
    }

    return 0;
}