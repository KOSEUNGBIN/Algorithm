//
// Created by 고승빈 on 2017. 7. 29..
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
int general , special;
vector<vector<char>> board;
vector<vector<bool>> visit;
string inputRow;

void DFSGen(int x , int y , char col)
{

    if(x < 1 || x > N || y < 1 || y > N)    return;
    if(visit[y][x])                         return;
    if(board[y][x] != col)                  return;

    visit[y][x] = true;

    DFSGen(x-1 , y , col);
    DFSGen(x+1 , y , col);
    DFSGen(x , y-1 , col);
    DFSGen(x , y+1 , col);


}


void DFSSpe(int x , int y , char col)
{
    if(x < 1 || x > N || y < 1 || y > N)    return;
    if(visit[y][x])                         return;
    if(col == 'B')
    {
        if(board[y][x] != 'B')              return;

    } else{

        if(board[y][x] == 'B')              return;

    }


    visit[y][x] = true;

    DFSSpe(x-1 , y , col);
    DFSSpe(x+1 , y , col);
    DFSSpe(x , y-1 , col);
    DFSSpe(x , y+1 , col);

}


int main()
{
    ios::sync_with_stdio(false);

    cin >> N;

    general = special = 0;

    board.assign(N+1,vector<char>(N+1));

    for(int i = 1 ; i <= N ; ++i)
    {
       cin >> inputRow;

        for(int j = 1  ; j <= N ; ++j)
        {
            board[i][j] = inputRow.c_str()[j-1];
        }
    }

    /*
     * general case
     *
     * */
    visit.assign(N+1,vector<bool>(N+1,false));

    for(int y = 1 ; y <= N; ++y)
    {
        for(int x = 1 ; x <= N ; ++x)
        {
            if(!visit[y][x]) ++general, DFSGen(x , y , board[y][x]);
        }
    }

    visit.clear();

    /*
     * special case
     *
     * */

    visit.assign(N+1,vector<bool>(N+1,false));

    for(int y = 1 ; y <= N; ++y)
    {
        for(int x = 1 ; x <= N ; ++x)
        {
            if(!visit[y][x]) ++special, DFSSpe(x , y , board[y][x]);
        }
    }

    visit.clear();

    cout << general << " " << special << "\n";

    return 0;

}