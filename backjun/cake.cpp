//
// Created by 고승빈 on 2018. 3. 31..
//

#include <iostream>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    int T, N, M;
    int S;
    int NCake[1001], MCake[1001];
    int memory[20001];
    int count, NSum, MSum;
    cin >> T;
    while (T--) {
        memset(memory, 0x00, sizeof(int) * 10001);
        cin >> S;
        cin >> N >> M;
        count = 0;
        for (int i = 0; i < N; ++i) {
            cin >> NCake[i];
        }

        for (int i = 0; i < M; ++i) {
            cin >> MCake[i];
        }

        for (int m = 0; m < M; ++m) {
            MSum = 0;
            int usedM = 0;
            while (usedM < M && MSum < S) {
                MSum += MCake[(m + usedM) % M];
                if (MSum == S) {
                    count++;
                    break;
                }

                usedM++;
            }
        }

        for (int n = 0; n < N; ++n) {
            NSum = 0;
            int usedN = 0;
            while (usedN < N && NSum < S) {
                NSum += NCake[(n + usedN) % N];
                if (NSum == S) {
                    count++;
                    break;
                }

                usedN++;
            }
        }

        for (int n = 0; n < N; ++n) {
            NSum = 0;
            int usedN = 0;
            while (usedN < N && NSum <= S) {
                NSum += NCake[(n + usedN) % N];
                if (memory[NSum] > 0) {
                    count += memory[NSum];
                }

                if (memory[NSum] == 0) {
                    for (int m = 0; m < M; ++m) {
                        MSum = 0;
                        int usedM = 0;
                        while (usedM < M && NSum + MSum < S) {
                            MSum += MCake[(m + usedM) % M];
                            if (NSum + MSum == S) {
                                count++;
                                memory[NSum]++;
                                break;
                            }

                            usedM++;
                        }
                    }

                    if (memory[NSum] == 0) memory[NSum] = -1;
                }

                usedN++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}