//https://www.hackerrank.com/contests/projecteuler/challenges/euler014/problem?isFullScreen=true
#include "HelperFunctions/helpers.hpp"

map<int,int> collSubSeqLens;

int CollazSequenzLength(int n){
    if(n <= 1)
        return 1;

    if(collSubSeqLens.find(n) != collSubSeqLens.end())
        return collSubSeqLens[n];

    int ret;
    if(n % 2 == 0){
        ret = CollazSequenzLength(n/2) + 1;
    } else {
        ret = CollazSequenzLength(3*n+1) + 1;
    }
    collSubSeqLens[n] = ret;
    return ret;
}



//TODO Timeout
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int n;
    cin >> n;

    vector<pair<int,int>> prev_erg;
    prev_erg.push_back(pair<int,int>(0,0));
    prev_erg.push_back(pair<int,int>(1,1));
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        //cout << CollazSequenzLength(input) << endl;

        if(input < prev_erg.size()){
            cout << prev_erg[input].first << endl;
            continue;
        } 
        int max = prev_erg.back().second;
        int in = prev_erg.back().first;
        int j = prev_erg.size();
        for(; j <= input; j++)
        {
            int erg = CollazSequenzLength(j);
            if(erg >= max) {
                max = erg;
                in = j;
            }
            prev_erg.push_back(pair<int,int>(in, max));
        }
        cout << in << endl;
    }

    return 0;
}
