//https://www.hackerrank.com/contests/projecteuler/challenges/euler005/problem?isFullScreen=true

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <valarray> 
#include <queue>

using namespace std;

string& ltrim(string &);
string& rtrim(string &);
vector<string> split(const string &);


string &ltrim(string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c) {return !isspace(c);}));
    return s;
}

string &rtrim(string &s) {
    s.erase((++s.rbegin()).base(), std::find_if((++s.rbegin()).base(), s.rbegin().base(), [](int c) {return !isspace(c);}));
    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

bool isValid(long num, int n) {
    for(int i = 2; i <= n; i++){
        if(num % i != 0){
            return false;
        }
    }
    return true;
}

//TODO Timeou problemo
void getSmallestMultiple(int n){
    vector<long> pos;
    long last = 1;
    for(int i = 2; i <= n; i++)
        last *= i;
    pos.push_back(last);

    do {
        last = pos.back(); pos.pop_back();

        for(int i = 2; i <= n; i++) {            
            if((last % i == 0) & isValid(last/i,n)){
                pos.push_back(last/i);
            }
        } 
        if(pos.size() == 0)
            pos.push_back(last);

        sort(pos.begin(), pos.end());
    } while(pos.size() > 1);

    cout << pos[0] << endl;
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        //smallest num dividable by 1, 2, ... n
        getSmallestMultiple(n);
    }

    return 0;
}