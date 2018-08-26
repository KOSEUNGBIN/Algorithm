//
// Created by 고승빈 on 2018. 8. 26..
//

#include <iostream>
using namespace std;
int split(int n, int m, int cache[][301]);

int main() {
    int N, M;
    int cache [301][301] = {0,};
    scanf("%d %d", &N, &M);

    printf("%d\n", split(N, M, cache));
    return 0;
}

int split(int n, int m, int cache[][301]) {
    if(cache[n][m] > 0) {
        return cache[n][m];

    } else if(n > 1) {
        int token = n / 2;
        return cache[n][m] = split(token, m, cache) + split(n - token, m, cache) + 1;

    } else if(m > 1) {
        int token = m / 2;
        return cache[n][m] = split(n, token, cache) + split(n, m - token, cache) + 1;

    } else {
        return 0;

    }

}