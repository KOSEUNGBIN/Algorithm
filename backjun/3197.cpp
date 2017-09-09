//
// Created by 고승빈 on 2017. 8. 19..
//

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
using namespace std;

int T , R , C;
int sideR , sideC;
string input;

pair<int , int> sour , dest;
bool isSour , isSuccess , isReSour;

vector<vector<bool>> Sea , SeaTemp;
vector<vector<bool>> visit;

queue<pair<int,int>> que;
queue<pair<int,int>> side , sideTemp;

bool bfsImp(pair<int , int> point)
{
    if(point.first > 0)
    {
        if(!visit[point.first - 1][point.second])
        {
            visit[point.first - 1][point.second] = true;
            if(Sea[point.first - 1][point.second])
            {
                if(point.first - 1 == dest.first && point.second == dest.second)
                {
                    return true;
                } else{
                    que.push(make_pair(point.first - 1 , point.second));
                }
            }
        }
    }

    if(point.first < R - 1)
    {
        if(!visit[point.first + 1][point.second])
        {
            visit[point.first + 1][point.second] = true;
            if(Sea[point.first + 1][point.second])
            {
                if(point.first + 1 == dest.first && point.second == dest.second)
                {
                    return true;
                } else{
                    que.push(make_pair(point.first + 1 , point.second));
                }
            }
        }
    }

    if(point.second > 0)
    {
        if(!visit[point.first ][point.second - 1])
        {
            visit[point.first ][point.second- 1] = true;
            if(Sea[point.first ][point.second- 1])
            {
                if(point.first == dest.first && point.second- 1 == dest.second)
                {
                    return true;
                } else{
                    que.push(make_pair(point.first  , point.second- 1));
                }
            }
        }
    }

    if(point.second < C - 1)
    {
        if(!visit[point.first ][point.second + 1])
        {
            visit[point.first ][point.second + 1] = true;
            if(Sea[point.first ][point.second + 1])
            {
                if(point.first == dest.first && point.second + 1 == dest.second)
                {
                    return true;
                } else{
                    que.push(make_pair(point.first  , point.second + 1));
                }
            }
        }
    }

    return false;
}

bool bfs(pair<int , int> point)
{

    if(point.first == dest.first && point.first == dest.second) return true;

    visit[point.first][point.second] = true;

    que.push(point);

    pair<int , int> temp;

    while(!que.empty())
    {
        temp = que.front(); que.pop();

        if(bfsImp(temp))    return true;
    }

    return false;
}


int main()
{
    ios::sync_with_stdio(false);

    cin >> R >> C;

    isReSour = isSuccess = isSour = false;
    T = 0;

    Sea.assign(R , vector<bool>(C));
    SeaTemp.assign(R , vector<bool>(C));
    visit.assign(R , vector<bool>(C , false));

    for(int r = 0 ; r < R ; ++r)
    {
        cin >> input;

        for(int c = 0 ; c < C ; ++c)
        {
            if(input[c] == 'X')
            {
                Sea[r][c] = false;
            }
            else{
                Sea[r][c] = true;

                side.push(make_pair(r,c));

                if(input[c] == 'L')
                {
                    if(!isSour) sour.first = r , sour.second = c , isSour = true;
                    else        dest.first = r , dest.second = c;
                }
            }
        }
    }

    while(!isSuccess)
    {
        visit.assign(R , vector<bool>(C , false));

        if(bfs(sour))
        {
            cout << T << '\n';
            isSuccess = true;
        } else{

            while(!side.empty())
            {
                sideR = side.front().first;
                sideC = side.front().second;
                side.pop();

                    if(Sea[sideR][sideC])
                    {
                        SeaTemp[sideR][sideC] = true;
                        if(sideR > 0)
                        {

                            if(!Sea[sideR - 1][sideC])
                            {
//                                sour.first = sideR - 1 , sour.second = sideC ;
                                sideTemp.push(make_pair(sideR - 1 , sideC));
                            }
                            Sea[sideR - 1][sideC] = true;
                        }
                        if(sideR < R - 1)
                        {

                            if( !Sea[sideR + 1][sideC])
                            {
//                                sour.first = sideR + 1 , sour.second = sideC;
                                sideTemp.push(make_pair(sideR + 1 , sideC));
                            }
                            Sea[sideR + 1][sideC] = true;
                        }
                        if(sideC > 0)
                        {

                            if( !Sea[sideR][sideC - 1])
                            {
//                                sour.first = sideR , sour.second = sideC - 1;
                                sideTemp.push(make_pair(sideR , sideC - 1));
                            }
                            Sea[sideR][sideC - 1] = true;
                        }
                        if(sideC < C - 1)
                        {

                            if( !Sea[sideR][sideC + 1])
                            {
//                                sour.first = sideR , sour.second = sideC + 1;
                                sideTemp.push(make_pair(sideR , sideC + 1));
                            }
                            Sea[sideR][sideC + 1] = true;

                        }

                    }
            }

            while(!sideTemp.empty())
            {

                side.push(make_pair(sideTemp.front().first , sideTemp.front().second));
                sideTemp.pop();
            }


            ++T;
        }

        visit.clear();


        // test
//        for(int r = 0 ; r < R ; ++r) {
//
//            for (int c = 0; c < C; ++c) {
//                cout << (Sea[r][c] ? '.' : 'X') ;
//            }
//            cout << endl;
//        }
    }


    return 0;
}