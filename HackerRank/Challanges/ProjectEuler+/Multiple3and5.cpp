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

//TODO getten timeout bei 1 testcase
int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    vector<int> n_;
    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));
        n_.push_back(n);
    }
    
    vector<int> n_orig = n_;
    sort(n_.begin(), n_.end());
    
    long sum = 0;
    vector<long> sums;
    for (int i = 0; i < n_.size(); i++) {
        
        int n = n_[i];
        int x = 3;
        if(i > 0){
            x = n_[i-1];
            while(x % 3 != 0)
                x++;
        }
        for(;x < n; x+=3){
            sum+=x;
        }
        
        x = 5;
        if(i > 0){
            x = n_[i-1];
            while(x % 5 != 0)
                x++;
        }
        for(;x < n; x+=5){
            if(x % 3 != 0)
                sum+=x;
        }
        
        //cout << sum << endl;
        sums.push_back(sum);
    }
    
    for(int n : n_orig){
        for(int i = 0; i < n_orig.size(); i++){
            if(n == n_[i]){
                cout << sums[i] << endl;
                break;
            }
        }
    }
    
    
    return 0;

    return 0;
}

