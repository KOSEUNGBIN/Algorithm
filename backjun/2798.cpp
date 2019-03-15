//
// Created by 고승빈 on 2019-03-15.
//

#include <iostream>
#include <vector>

using namespace std;

int trace(vector<int> &cards, int index, int count, int score, int limit) {
    if (count >= 3) {
        return score <= limit ? score : 0;

    }

    if (score >= limit) { return 0; }

    int maximum = 0;
    for (int idx = index; idx < cards.size(); ++idx) {
        int ret = trace(cards, idx + 1, count + 1, score + cards[idx], limit);
        if (ret <= limit) { maximum = max(maximum, ret); }

    }

    return maximum;

}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> cards(static_cast<unsigned long>(N));
    for (int n = 0; n < N; ++n) {
        cin >> cards[n];

    }

    sort(cards.begin(), cards.end());
    cout << trace(cards, 0, 0, 0, M) << "\n";
    return 0;

}