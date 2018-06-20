//
// Created by 고승빈 on 2018. 6. 20..
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int M, N, H;
int raw = 0, minimum = 0;
vector<vector<vector<int>>> box;
typedef struct vertex {
    int h, n, m, day;
    vertex(int h, int n, int m, int day) {
        this->h = h;
        this->n = n;
        this->m = m;
        this->day = day;
    }
} Vertex;



void bfs(queue<Vertex>& que) {
    Vertex front = que.front();
    if(front.h + 1 < H) {
        if(box[front.h + 1][front.n][front.m] == 0 || box[front.h + 1][front.n][front.m] > front.day + 1) {
            box[front.h + 1][front.n][front.m] = front.day + 1;
            que.push(Vertex(front.h + 1, front.n, front.m, front.day + 1));
        }

    }

    if(front.h - 1 >= 0) {
        if(box[front.h - 1][front.n][front.m] == 0 || box[front.h - 1][front.n][front.m] > front.day + 1) {
            box[front.h - 1][front.n][front.m] = front.day + 1;
            que.push(Vertex(front.h - 1, front.n, front.m, front.day + 1));
        }

    }

    if(front.n + 1 < N) {
        if(box[front.h][front.n + 1][front.m] == 0 || box[front.h][front.n + 1][front.m] > front.day + 1) {
            box[front.h][front.n + 1][front.m] = front.day + 1;
            que.push(Vertex(front.h, front.n + 1, front.m, front.day + 1));
        }

    }

    if(front.n - 1 >= 0) {
        if(box[front.h][front.n - 1][front.m] == 0 || box[front.h][front.n - 1][front.m] > front.day + 1) {
            box[front.h][front.n - 1][front.m] = front.day + 1;
            que.push(Vertex(front.h, front.n - 1, front.m, front.day + 1));
        }

    }

    if(front.m + 1 < M) {
        if(box[front.h][front.n][front.m + 1] == 0 || box[front.h][front.n][front.m + 1] > front.day + 1) {
            box[front.h][front.n][front.m + 1] = front.day + 1;
            que.push(Vertex(front.h, front.n, front.m + 1, front.day + 1));
        }

    }

    if(front.m - 1 >= 0) {
        if(box[front.h][front.n][front.m - 1] == 0 || box[front.h][front.n][front.m - 1] > front.day + 1) {
            box[front.h][front.n][front.m - 1] = front.day + 1;
            que.push(Vertex(front.h, front.n, front.m - 1, front.day + 1));
        }

    }

    que.pop();
}

void bfsInter(Vertex vtx) {
    queue<Vertex> vertexQue;
    vertexQue.push(vtx);
    while(!vertexQue.empty()) {
        bfs(vertexQue);
    }

}



void dfs(vector<vector<vector<int>>>& box, int h, int n, int m, int day) {
    if (h < 0 || n < 0 || m < 0 || h >= H || n >= N || m >= M)
        return;

    if (box[h][n][m] < 0) {
        return;
    }

    if (box[h][n][m] == 0) {
        box[h][n][m] = day + 1;
    } else {
        if(box[h][n][m] > day + 1) {
            box[h][n][m] = day + 1;
        } else {
            return;
        }

    }

    dfs(box, h + 1, n, m, day + 1);
    dfs(box, h - 1, n, m, day + 1);
    dfs(box, h, n + 1, m, day + 1);
    dfs(box, h, n - 1, m, day + 1);
    dfs(box, h, n, m + 1, day + 1);
    dfs(box, h, n, m - 1, day + 1);


}

int main() {
    scanf("%d %d %d", &M, &N, &H);
    box.resize(H, vector<vector<int>>(N, vector<int>(M)));

    for (int h = 0; h < H; ++h) {
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                scanf("%d", &box[h][n][m]);
                if(!box[h][n][m]) {
                    ++raw;
                }
            }
        }
    }

    if(!raw) {
        printf("0\n");
        return 0;
    }

    for (int h = 0; h < H; ++h) {
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                if (box[h][n][m] == 1) {
                    bfsInter(Vertex(h, n, m, box[h][n][m]));
                }
            }
        }
    }

    for (int h = 0; h < H; ++h) {
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                if(box[h][n][m] == 0) {
                    printf("-1\n");
                    return 0;
                }

                if (box[h][n][m] > 0) {
                    minimum = max(minimum, box[h][n][m]);
                }
            }
        }
    }

    printf("%d\n", minimum - 1);
    return 0;
}