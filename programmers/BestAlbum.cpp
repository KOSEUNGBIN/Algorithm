//
// Created by 고승빈 on 2018. 10. 16..
//
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Info {
private :
    int maxPlay;
    int secMaxPlay;
    int maxId;
    int secMaxId;
    int plays;
public:
    Info(int maxId, int maxPlay) : maxPlay(maxPlay), maxId(maxId) {
        this->maxId = maxId;
        this->maxPlay = maxPlay;
        secMaxPlay = -1;
        secMaxPlay = 0;
        plays = 0;

    }

    int getMaxPlay() const {
        return maxPlay;
    }

    void setMaxPlay(int maxPlay) {
        Info::maxPlay = maxPlay;
    }

    int getSecMaxPlay() const {
        return secMaxPlay;
    }

    void setSecMaxPlay(int secMaxPlay) {
        Info::secMaxPlay = secMaxPlay;
    }

    int getMaxId() const {
        return maxId;
    }

    void setMaxId(int maxId) {
        Info::maxId = maxId;
    }

    int getSecMaxId() const {
        return secMaxId;
    }

    void setSecMaxId(int secMaxId) {
        Info::secMaxId = secMaxId;
    }

    void addPlays(int plays) {
        Info::plays += plays;
    }

    void pushMaxInfo(int id, int play) {
        setSecMaxPlay(getMaxPlay());
        setSecMaxId(getMaxId());
        setMaxPlay(play);
        setMaxId(id);

    }

    void pushSecMaxInfo(int id, int play) {
        setSecMaxPlay(play);
        setSecMaxId(id);

    }

    bool operator <(const Info& c)  const {
        return this->plays < c.plays;

    }

};

map<string, Info> makeGroups(vector<string> genres, vector<int> plays) {
    map<string, Info> groups;
    int size = genres.size();
    for(int id = 0; id < size; ++id) {
        int play = plays[id];
        string genre = genres[id];
        map<string, Info>::iterator iter = groups.find(genre);
        if(iter == groups.end()) {
            Info newInfo(id, play);
            newInfo.addPlays(plays[id]);
            groups[genre] = newInfo;

        } else {
            Info info = iter->second;
            info.addPlays(play);
            if(info.getMaxPlay() < play) {
                info.pushMaxInfo(id, play);

            } else if(info.getSecMaxPlay() < play) {
                info.pushSecMaxInfo(id, play);

            }

            groups[genre] = info;

        }

    }

    return groups;

}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, Info> groups =  makeGroups(genres, plays);
    priority_queue<Info> pq;
    for(map<string, Info>::iterator iter = groups.begin(); iter != groups.end(); ++iter) {
        pq.push(iter->second);

    }

    while(!pq.empty()) {
        Info info = pq.top();
        if(info.getMaxId() >= 0) {
            answer.push_back(info.getMaxId());

        }

        if(info.getSecMaxId() >= 0) {
            answer.push_back(info.getSecMaxId());

        }

        pq.pop();

    }

    return answer;

}
