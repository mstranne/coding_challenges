//https://www.hackerrank.com/contests/projecteuler/challenges/euler004/problem?isFullScreen=true

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

bool isPalindrome(int n){
    int temp=n; 
    int sum = 0,r=0;   
    while(n>0)    
    {    
        r=n%10;    
        sum=(sum*10)+r;    
        n=n/10;    
    }    
    if(temp==sum)    
        return true;  
    return false;  
}

inline bool is3Digit(int n) {
    return (99 < n && n < 1000);
}

bool isProdOf3DigitNums(int n){
    int orig = n;
    vector<int> prims;

    while(n % 2 == 0){
        n/=2;
        int len = prims.size();
        for(int i = 0; i < len;i++){
            if(prims[i]*2 < 1000)
                prims.push_back(prims[i]*2);
        }
        prims.push_back(2);
    }

    int prime = 3;
    while(n != prime){
        if(n % prime == 0){
            n /= prime;

            int len = prims.size();
            for(int i = 0; i < len;i++){
                if(prims[i]*prime < 1000)
                    prims.push_back(prims[i]*prime);
            }
            prims.push_back(prime);

            if(prime > 999)
                break;
        }
        else
            prime+=2;
    }
    
    for(int i = 0; i < prims.size();i++){
        if(is3Digit(prims[i]) && is3Digit(orig / prims[i]))
            return true;
    }

    return false;
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

        // A palindromic number reads the same both ways.

        while(n >= 101101){
            if(isPalindrome(n)){
                if(isProdOf3DigitNums(n)){
                    cout << n << endl;
                    break;
                }
            }
            n--;
        }
        

    }

    return 0;
}