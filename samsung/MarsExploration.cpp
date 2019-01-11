#define MAX_MAP_SIZE        64
#define BLOCK_SIZE            4
#define BUCKET_SIZE            65536

#define NULL '\0'

#include <iostream>

using namespace std;

extern void brokenCamera(char zone[BLOCK_SIZE][BLOCK_SIZE]);

int X_MOVER[4] = {0, 0, 2, 2};
int Y_MOVER[4] = {0, 2, 0, 2};

class Position {
private:
    int x;
    int y;

public:
    Position(int x, int y) {
        this->x = x;
        this->y = y;

    }

    int getX() {
        return this->x;

    }

    int getY() {
        return this->y;

    }

};

class Node {
private:
    int _key;
    int _hash;
    Position *_position;
    Node *_next;
public:
    Node(int key, int hash, int x, int y, Node *next) {
        this->_key = key;
        this->_hash = hash;
        this->_position = new Position(x, y);
        this->_next = next;

    }

    Node() {
        this->_key = 0;
        this->_hash = 0;
        this->_position = NULL;
        this->_next = NULL;

    }

    int getKey() {
        return this->_key;

    }

    bool isEquals(int key) {
        return this->_key == key;

    }

    Node *getNext() {
        return this->_next;

    }

    void setNext(Node *next) {
        this->_next = next;

    }

    Position *getPosition() {
        return this->_position;

    }

};

class Map {
private:
    Node buckets[BUCKET_SIZE];

    int hash(int value) {
        return value % BUCKET_SIZE;

    }

public:
    Map() {}

    void insert(int key, int x, int y) {
        int _hash = hash(key);
        Node *node = new Node(key, _hash, x, y, buckets[_hash].getNext());
        buckets[_hash].setNext(node);

    }

    Position **find(int key) {
        int _hash = hash(key);
        Node *bucket = buckets[_hash].getNext();
        Position **positions = new Position *[32];
        int last = 0;
        while (bucket != NULL) {
            if (bucket->isEquals(key)) {
                positions[last++] = bucket->getPosition();

            }

            bucket = bucket->getNext();

        }

        return positions;

    }

    int pack(char map[MAX_MAP_SIZE][MAX_MAP_SIZE], int startX, int startY) {
        return (map[startX][startY] << 12) + (map[startX + 1][startY] << 8) + (map[startX][startY + 1] << 4) +
               (map[startX + 1][startY + 1]);

    }

    void init(int N, char map[MAX_MAP_SIZE][MAX_MAP_SIZE]) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (x == 0 || y == 0 || x == N - 2 || y == N - 2) {
                    insert(pack(map, x, y), x, y);

                }

            }

        }

    }

};

class ListNode {
private:
    int *_value = new int[4];
    ListNode *_next;
    ListNode *_before;


public:
    ListNode(int *value, ListNode *next, ListNode *before) : _next(next), _before(before) {
        copy(value, 4);

    }

    ListNode(int *value) {
        copy(value, 4);
        this->_next = NULL;
        this->_before = NULL;

    }

    ListNode() {
        this->_next = NULL;
        this->_before = NULL;

    }

    void copy(int *source, int count) {
        for (int idx = 0; idx < 4; ++idx) {
            _value[idx] = source[idx];

        }

    }

    void setNext(ListNode *next) {
        this->_next = next;

    }

    void setBefore(ListNode *before) {
        this->_before = before;

    }

    int *getValue() const {
        return _value;

    }

    ListNode *getNext() const {
        return _next;

    }

    ListNode *getBefore() const {
        return _before;

    }

};

class List {
private:
    int _size;
    ListNode *front;
    ListNode *rear;
    ListNode *cur;

public:
    List() {
        this->_size = 0;
        this->front = new ListNode();
        this->rear = new ListNode();
        this->front->setNext(this->rear);
        this->rear->setBefore(this->front);
        this->cur = NULL;

    }

    bool isEmpty() {
        return this->_size == 0;

    }

    void insert(int *value) {
        ListNode *node = new ListNode(value);
        node->setNext(this->front->getNext());
        node->setBefore(this->front);
        this->front->getNext()->setBefore(node);
        this->front->setNext(node);
        this->_size++;

    }

    void removeCurrent() {
        if (cur == NULL || this->_size == 0) {
            return;

        }

        ListNode *before = cur->getBefore();
        before->setNext(cur->getNext());
        cur->getNext()->setBefore(before);
        cur->setBefore(NULL);
        cur->setNext(NULL);
        cur = before;
        this->_size--;

    }

    void initCur() {
        cur = front->getNext();

    }

    bool isNext() {
        if (cur == rear) {
            return false;

        }

        cur = cur->getNext();
        return true;

    }

    int *getValue() {
        return cur->getValue();

    }

    int size() {
        return this->_size;

    }

};

int pack(char map[MAX_MAP_SIZE][MAX_MAP_SIZE], int startX, int startY) {
    return (map[startX][startY] << 12) + (map[startX + 1][startY] << 8) + (map[startX][startY + 1] << 4) +
           (map[startX + 1][startY + 1]);

}

char **unPack(int value[4]) {
    char **result = new char *[4];
    for (int idx = 0; idx < 4; ++idx) {
        result[idx] = new char[4];

    }


    int mask = 15;
    for (int c = 0; c < 4; c++) {
        for (int i = 0; i < 4; ++i) {
            result[X_MOVER[c] + (Y_MOVER[i] / 2)][Y_MOVER[c] + (X_MOVER[i] / 2)] = (value[c] >> (4 * (3 - i))) & mask;

        }

    }

    return result;

}

int *pack(char zone[BLOCK_SIZE][BLOCK_SIZE]) {
    int *packed = new int[4];
    for (int c = 0; c < BLOCK_SIZE; ++c) {
        packed[c] = (zone[X_MOVER[c] + 0][Y_MOVER[c] + 0] << 12) + (zone[X_MOVER[c] + 1][Y_MOVER[c] + 0] << 8) +
                    (zone[X_MOVER[c] + 0][Y_MOVER[c] + 1] << 4) + (zone[X_MOVER[c] + 1][Y_MOVER[c] + 1]);

    }

    return packed;

}


bool isDone(char map[MAX_MAP_SIZE][MAX_MAP_SIZE], int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (map[i][j] == 0) {
                return false;

            }

        }

    }

    return true;

}

bool isMatch(int *packedZone, Position *startPos, char map[MAX_MAP_SIZE][MAX_MAP_SIZE]) {
    int result = 0;
    bool isExistZero = false;
    for (int i = 0; i < 4; ++i) {
        int value = pack(map, startPos->getX() + X_MOVER[i], startPos->getY() + Y_MOVER[i]);
        if (packedZone[i] == value) {
            result++;

        }

        if (value == 0) {
            isExistZero = true;

        }

        if (value != 0 && packedZone[i] != value) {
            return false;

        }

    }

    return 1 < result && result < 4 && isExistZero;

}

Position *searchFirstPosition(Position *positions, int d) {
    return new Position(positions->getX() - (X_MOVER[d]), positions->getY() - (Y_MOVER[d]));

}

void updateMap(Position *position, char map[MAX_MAP_SIZE][MAX_MAP_SIZE], char zone[BLOCK_SIZE][BLOCK_SIZE]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            map[i + position->getX()][j + position->getY()] = zone[i][j];

        }

    }

}

void updateMap(Position *position, char map[MAX_MAP_SIZE][MAX_MAP_SIZE], char **zone) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            map[i + position->getX()][j + position->getY()] = zone[i][j];

        }

    }

}

void update(Position *startPosition, int *packedZone, Map *map, int count) {
    for (int c = 0; c < count; ++c) {
        map->insert(packedZone[c], startPosition->getX() + X_MOVER[c], startPosition->getY() + Y_MOVER[c]);

    }

}

bool checkSection(char map[MAX_MAP_SIZE][MAX_MAP_SIZE], Map &_map, int *packedZone) {
    Position **positions = _map.find(packedZone[0]);
    for (int idx = 0; idx < 32 && positions[idx] != NULL; ++idx) {
        Position *startPos = searchFirstPosition(positions[idx], 0);
        if (isMatch(packedZone, startPos, map)) {
            updateMap(startPos, map, unPack(packedZone));
            update(startPos, packedZone, &_map, 4);
            return true;

        }

    }

    return false;

}

bool checkRestSection(char map[MAX_MAP_SIZE][MAX_MAP_SIZE], List &list, Map &_map) {
    list.initCur();
    while (list.isNext()) {
        int *packedZone1 = list.getValue();
        if (checkSection(map, _map, packedZone1)) {
            return true;

        }

    }

    return false;

}

void completeMap(int N, char map[MAX_MAP_SIZE][MAX_MAP_SIZE]) {
    Map _map;
    _map.init(N, map);
    char zone[BLOCK_SIZE][BLOCK_SIZE];
    List list;
    while (!isDone(map, N)) {
        brokenCamera(zone);
        int *packedZone = pack(zone);
        if (!checkSection(map, _map, packedZone)) {
            if (!checkRestSection(map, list, _map)) {
                list.insert(packedZone);

            } else {
                list.removeCurrent();

            }

        }

    }

}
