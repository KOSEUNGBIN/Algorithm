/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include <iostream>
#include <vector>

using namespace std;

class Date {
private:
    int hour;
    int minute;

public:
    Date() {}

    Date(string date) {
        setUp(date);

    }

    Date(int hour, int minute) {
        this->hour = hour;
        this->minute = minute;

    }

    Date(Date *date) {
        this->hour = date->getHour();
        this->minute = date->getMinute();

    }

    int toNumber(char ch) {
        return ch - '0';

    }

    void setUp(string date) {
        setHour(toNumber(date[0]) * 10 + toNumber(date[1]));
        setMinute(toNumber(date[3]) * 10 + toNumber(date[4]));

    }

    void setHour(int hour) {
        Date::hour = hour;

    }

    void setMinute(int minute) {
        Date::minute = minute;

    }

    int getHour() const {
        return hour;

    }

    int getMinute() const {
        return minute;

    }

    bool isAfter(Date *date) {
        return (hour > date->getHour()) || (hour == date->getHour() && minute > date->getMinute());

    }

    bool isBefore(Date *date) {
        return (hour < date->getHour()) || (hour == date->getHour() && minute < date->getMinute());

    }

    bool isEquals(Date *date) {
        return hour == date->getHour() && minute == date->getMinute();

    }

    void addTime(int hour, int minute) {
        this->hour += hour;
        this->minute += minute;
        if (this->minute >= 60) {
            this->hour++;
            this->minute %= 60;

        }

    }

    void subtractTime(int hour, int minute) {
        this->hour -= hour;
        this->minute -= minute;
        if (this->minute < 0) {
            this->hour--;
            this->minute += 60;

        }

    }

};

class Friend {
private:
    int id;
    Date *startDate;
    Date *endDate;

public:
    Friend(int id, string start, string end) {
        this->id = id;
        this->startDate = new Date(start);
        this->endDate = new Date(end);

    }

    Friend(int id, Date *start, Date *end) {
        this->id = id;
        this->startDate = start;
        this->endDate = end;

    }

    int getId() const {
        return id;

    }

    Date *getStartDate() const {
        return startDate;

    }

    Date *getEndDate() const {
        return endDate;

    }

};

bool compare(Friend *aFriend, Friend *bFriend) {
    if (aFriend->getEndDate()->isEquals(bFriend->getEndDate())) {
        return aFriend->getId() < bFriend->getId();

    }

    return aFriend->getEndDate()->isBefore(bFriend->getEndDate());

}

void sort(vector<Friend *> &vec) {
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = i + 1; j < vec.size(); ++j) {
            if (compare(vec[j], vec[i])) {
                Friend *temp = vec[j];
                vec[j] = vec[i];
                vec[i] = temp;

            }

        }

    }

}

void init(int &N, int &R, int &S, Date *hotelsClosedTime, Date *wakeUpTime, Date *storeOpenTime) {
    cin >> N;

    // input store open, hotel closed, wake up times
    string date;
    cin >> date;
    hotelsClosedTime->setUp(date);

    cin >> date;
    wakeUpTime->setUp(date);

    cin >> date;
    storeOpenTime->setUp(date);

    // input move, select times
    cin >> R;
    cin >> S;

}

vector<Friend *> makeFriends(int N) {
    string from, to;
    vector<Friend *> friends;
    for (int n = 0; n < N; ++n) {
        cin >> from >> to;
        friends.push_back(new Friend(n + 1, from, to));

    }

    return friends;

}

vector<Friend *>
findPossibleFriends(vector<Friend *> friends, Date *hotelsClosedTime, Date *wakeUpTime, Date *storeOpenTime, int R,
                    int S) {
    Date *startTime, *endTime;
    vector<Friend *> possibleFriends;
    for (Friend *fred : friends) {
        startTime = new Date(storeOpenTime);
        startTime->subtractTime(R / 60, R % 60);
        endTime = new Date(storeOpenTime);
        endTime->addTime((R + S) / 60, (R + S) % 60);
        if (!wakeUpTime->isAfter(startTime) && !fred->getStartDate()->isBefore(endTime)
            && !hotelsClosedTime->isBefore(endTime)) {
            possibleFriends.push_back(new Friend(fred->getId(), startTime, endTime));
            continue;

        }

        startTime = new Date(fred->getEndDate());
        endTime = new Date(startTime);
        endTime->addTime((2 * R + S) / 60, (2 * R + S) % 60);
        if (!hotelsClosedTime->isBefore(endTime)) {
            possibleFriends.push_back(new Friend(fred->getId(), startTime, endTime));

        }

    }

    return possibleFriends;

}

void display(vector<Friend *> possibleFriends) {
    for (Friend *f : possibleFriends) {
        cout << "id = " << f->getId() << ", "
             << "start date = " << f->getStartDate()->getHour() << ":" << f->getStartDate()->getMinute() << ", "
             << "end date = " << f->getEndDate()->getHour() << ":" << f->getEndDate()->getMinute() << endl;
    }

}

int main() {
    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; ++tc) {
        int N, R, S;
        Date *hotelsClosedTime = new Date();
        Date *wakeUpTime = new Date();
        Date *storeOpenTime = new Date();
        init(N, R, S, hotelsClosedTime, wakeUpTime, storeOpenTime);
        vector<Friend *> friends = makeFriends(N);
        vector<Friend *> possibleFriends = findPossibleFriends(friends, hotelsClosedTime, wakeUpTime, storeOpenTime, R,
                                                               S);
        sort(possibleFriends);
        display(possibleFriends);
        cout << "Case " << tc << ": " << (possibleFriends.empty() ? -1 : possibleFriends[0]->getId()) << "\n";

    }

    return 0;

}

//  input
//
//  1
//  5
//  21:30
//  06:00
//  09:00
//  25
//  10
//  07:00 10:00
//  08:30 09:20
//  12:00 13:45
//  06:00 16:00
//  12:05 15:00