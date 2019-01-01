//
// Created by 고승빈 on 2019. 1. 1..
//

#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

int calUnit(int num) {
    int len = 1;
    while (num >= 10) {
        len *= 10;
        num /= 10;

    }

    return len;

}

class Heap {
private:
    int *_node;
    int _size;
    int _capacity;
    int _last;

public:
    Heap(int capacity) {
        init(capacity);
        _size = 0;
        _last = 1;

    }

    void init(int capacity) {
        _capacity = 1;
        while (_capacity <= capacity) {
            _capacity <<= 1;

        }

        _node = new int[_capacity];
        memset(_node, -1, _capacity);

    }

    void push(int value) {
        int index = _last++;
        int parent;
        _node[index] = value;
        while ((parent = (index / 2)) > 0) {
            if (compare(_node[index], _node[parent])) {
                swap(&_node[index], &_node[parent]);
                index = parent;

            } else {
                break;

            }

        }

        _size++;

    }

    int pop() {
        if (empty()) {
            return -1;

        }

        int top = _node[1];
        _node[1] = _node[--_last];
        _node[_last] = -1;
        int index = 1;
        int left, right, max;
        while ((right = (2 * index + 1)) < _capacity) {
            left = right - 1;
            max = compare(_node[left], _node[right]) ? left : right;
            if (_node[max] >= 0 && compare(_node[max], _node[index])) {
                swap(&_node[max], &_node[index]);
                index = max;

            } else {
                break;

            }

        }

        --_size;
        return top;

    }

    int size() {
        return _size;

    }

    bool empty() {
        return _size == 0;

    }

    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;

    }

    bool compare(int a, int b) {
        int aLen = calUnit(a) * 10;
        int bLen = calUnit(b) * 10;
        int aC = a * bLen + b;
        int bC = b * aLen + a;

        return aC > bC;

    }

};

void append(string &str, int num) {
    int unit = calUnit(num);
    while (unit > 0) {
        str += (char) ((num / unit) + 48);
        num %= unit;
        unit /= 10;

    }

}

string removeFrontZero(string input) {
    const char *str = input.c_str();
    int idx = 0, len = strlen(str);
    while (idx < len) {
        if (str[idx] != '0') {
            break;

        }

        ++idx;

    }

    string result = input.substr(idx, len);
    return result.empty() ? "0" : result;

}

string solution(vector<int> numbers) {
    string answer = "";
    Heap heap(numbers.size());
    for (int value : numbers) {
        heap.push(value);

    }

    while (!heap.empty()) {
        int value = heap.pop();
        append(answer, value);

    }

    return removeFrontZero(answer);

}

int main() {
    vector<int> arr
//              = {6, 10, 2};
//              = {3, 30, 34, 5, 9};
            = {0, 0, 0, 0};

    cout << solution(arr) << endl;
    return 0;

}