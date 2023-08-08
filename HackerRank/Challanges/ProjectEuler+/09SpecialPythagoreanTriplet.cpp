//https://www.hackerrank.com/contests/projecteuler/challenges/euler009/problem?isFullScreen=true

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

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        //Pythagorean triplet:
        // a < b < c where:
        // a^2 + b^2 = c^2
        // Given N, check if Triple with a + b + c = N
        // find the one with max a*b*c 
        // umformen und 1 in 2 einfuegen -> 2ab - 2aN - 2bN + N = 0
        // lagrange mit 1/2 nebenbedingunen? max a*b*c unter 2ab - 2aN - 2bN + N = 0 / a < b < c wobei sich des ja eh von a^2+b^2=c^2 ableitet

        int max = -1;
        for(int a = 1; a < n/3; a++){ //a is max 1/3-2 right?
            if((a*n) % (a-n) == 0) {        // von 2ab - 2aN - 2bN + N = 0
                //we got a possible int solution
                int b = abs((n*(a-n/2))/(a-n));  // TODO wie arrive ich hier ?
                int c = n - a - b;          // a + b + c = N
                
                if((a < b) && (b < c) && pow(a,2) + pow(b,2) == pow(c,2)){    //  a^2 + b^2 = c^2 also true ?
                    if(max < a*b*c)
                        max = a*b*c;
                }
            }
        }

        cout << max << endl;
    }

    return 0;
}