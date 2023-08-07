//https://www.hackerrank.com/contests/projecteuler/challenges/euler007/problem?isFullScreen=true

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

inline bool isPrime(int num, const vector<int> primes){
    //fixed timeout by check here with is dividable by all other primes
    for(int i : primes){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}


int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    vector<int> primes;
    primes.push_back(2);
    primes.push_back(3);
    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        if(n < primes.size()){
            cout << primes[n-1] << endl;
        } else{
            int last_p = primes.back();
            while(primes.size() < n){
                last_p += 2;
                if(isPrime(last_p, primes)){
                    primes.push_back(last_p);
                }                
            }
            cout << last_p << endl;
        }
    }
    return 0;
}