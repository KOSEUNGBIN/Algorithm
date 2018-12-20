//
// Created by 고승빈 on 2018. 12. 20..
//

#include <string>
#include <vector>

using namespace std;

class Map {
private:
    class bucket {
    private:
        int _hash;
        bucket *_next;
        int _value;
        string _key;
    public:
        bucket() {
            _hash = 0;
            _next = NULL;
            _value = 0;

        }

        bucket(int hash, int value, string key) {
            _hash = hash;
            _next = NULL;
            _value = value;
            _key = key;

        }

        bucket *next() {
            return _next;

        }

        void setNext(bucket *bk) {
            _next = bk;

        }

        void setValue(int value) {
            _value = value;

        }

        int getValue() {
            return _value;

        }

        bool equals(string key) {
            return _key.compare(key) == 0;

        }

    };

    int _size;
    int _capacity;
    bucket *_buckets;

    int hash(string key) {
        int hash = 0;
        int mask = 0xF0000000;
        for (int i = 0; i < key.length(); ++i) {
            hash = (hash << 4) + key[i];
            int x = hash & mask;
            if (x != 0) hash ^= (x >> 24);
            hash &= ~x;

        }

        return hash;

    }

    void init() {
        _size = 0;
        _capacity = 10;
        _buckets = new bucket[_capacity];

    }

public:
    Map() {
        init();

    }

    void put(string key, int value) {
        int hash = this->hash(key);
        bucket *bk = &_buckets[hash % _capacity];
        while (bk->next() != NULL) {
            bk = bk->next();
            if (bk->equals(key)) {
                bk->setValue(value);
                return;

            }

        }

        bucket *newBk = new bucket(hash, value, key);
        bk->setNext(newBk);
        _size++;

    }

    int get(string key) {
        int hash = this->hash(key);
        bucket *bk = &_buckets[hash % _capacity];
        while (bk->next() != NULL) {
            bk = bk->next();
            if (bk->equals(key)) {
                return bk->getValue();

            }

        }

        return 0;

    }

    int *getAllValue() {
        int *values = new int[_size];
        int cur = 0;
        for (int idx = 0; idx < _capacity; ++idx) {
            bucket *bk = &_buckets[idx];
            while (bk->next() != NULL) {
                bk = bk->next();
                values[cur++] = bk->getValue();

            }

        }

        return values;

    }

    int size() {
        return _size;

    }

};

int solution(vector<vector<string>> clothes) {
    Map partition;
    for (vector<string> cloth : clothes) {
        int value = partition.get(cloth[1]);
        partition.put(cloth[1], value + 1);

    }

    int result = 1;
    int *values = partition.getAllValue();
    for (int idx = 0, len = partition.size(); idx < len; ++idx) {
        result *= (values[idx] + 1);

    }

    return result - 1;

}