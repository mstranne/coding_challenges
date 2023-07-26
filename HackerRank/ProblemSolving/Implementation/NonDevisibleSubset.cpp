//https://www.hackerrank.com/challenges/non-divisible-subset/problem?isFullScreen=true

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

/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */

vector<vector<int>> GenCombinations(const unsigned int N, const unsigned int K) {
    vector<vector<int>> idxs;
    if(N == K){
        vector<int> idx;
        for(int xi = 0; xi < K; xi++)
            idx.push_back(xi);
        idxs.push_back(idx);
        return idxs;
    }

    unsigned int *ka = new unsigned int [K];  //dynamically allocate an array of UINTs
    unsigned int ki = K-1;                    //Point ki to the last elemet of the array
    ka[ki] = N-1;                             //Prime the last elemet of the array.
    vector<int> idx;

    while (true) {
        unsigned int tmp = ka[ki];  //Optimization to prevent reading ka[ki] repeatedly

        while (ki)                  //Fill to the left with consecutive descending values (blue squares)
            ka[--ki] = --tmp;
        
        idx.clear();
        for(int xi = 0; xi < K; xi++)
            idx.push_back(ka[xi]);
        idxs.push_back(idx);
    
        while (--ka[ki] == ki) {    //Decrement and check if the resulting value equals the index (bright green squares)
            //OutputArrayChar(ka, K, alphabet);
            idx.clear();
            for(int xi = 0; xi < K; xi++)
                idx.push_back(ka[xi]);
            idxs.push_back(idx);
            if (++ki == K) {      //Exit condition (all of the values in the array are flush to the left)
                delete[] ka;
                return idxs;
            }                   
        }
    }
}
   
bool check_condition(vector<int> s, vector<int> idxs, int k){
    for(int i = 0; i < idxs.size()-1; i++){
        for(int j = i+1; j < idxs.size(); j++){
            if((s[idxs[i]]+s[idxs[j]])%k == 0)
                return false;
        }    
    }
    return true;
}

int nonDivisibleSubset(int k, vector<int> s) {
    int N = s.size();
    int curr_max = 0;


    vector<int> idx;
    for(int xi = 0; xi < N; xi++)
        idx.push_back(xi);
    if(check_condition(s, idx, k))
                return N;
    
    //Top Down
    for(int m = N-1; m > 1; m--){
        unsigned int *ka = new unsigned int [m];  //dynamically allocate an array of UINTs
        unsigned int ki = m-1;                    //Point ki to the last elemet of the array
        ka[ki] = N-1;                             //Prime the last elemet of the array.
        

        bool contin = true;
        while (contin) {
            unsigned int tmp = ka[ki];  //Optimization to prevent reading ka[ki] repeatedly

            while (ki)                  //Fill to the left with consecutive descending values (blue squares)
                ka[--ki] = --tmp;
            
            idx.clear();
            for(int xi = 0; xi < m; xi++)
                idx.push_back(ka[xi]);
            if(check_condition(s, idx, k))
                return k;

        
            while (--ka[ki] == ki) {    //Decrement and check if the resulting value equals the index (bright green squares)
                //OutputArrayChar(ka, K, alphabet);
                idx.clear();
                for(int xi = 0; xi < m; xi++)
                    idx.push_back(ka[xi]);
                if(check_condition(s, idx, k))
                    return k;

                if (++ki == m) {      //Exit condition (all of the values in the array are flush to the left)
                    delete[] ka;
                    contin = false;
                    break;
                }                   
            }
        }
    }

    return 0;

    //Bottom UP
    queue<vector<int>> to_check;

    for(int i = 0; i < N-1; i++){
        for(int j = i+1; j < N; j++){
            vector<int> idx = {i,j}; 
            to_check.push(idx);
        }
    }

    while(to_check.size() > 0){
        vector<int> current_idxs = to_check.front();
        to_check.pop();

        if(check_condition(s, current_idxs, k)){
            if(curr_max < current_idxs.size())
                curr_max = current_idxs.size();

            for(int i = 0; i < N; i++){
                if (find(current_idxs.begin(), current_idxs.end(), i) != current_idxs.end()) {
                    
                } else {
                    vector<int> to_add = current_idxs;
                    to_add.push_back(i);
                    to_check.push(to_add);
                    // ACHTUNG STILL DOPPELTE !!!!
                }
            }
        }

    }

    return curr_max;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));
    ofstream fout("out.txt");

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    int result = nonDivisibleSubset(k, s);

    fout << result << "\n";

    fout.close();

    return 0;
}

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
