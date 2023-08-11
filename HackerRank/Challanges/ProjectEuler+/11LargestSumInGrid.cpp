//https://www.hackerrank.com/contests/projecteuler/challenges/euler011/problem?isFullScreen=true
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <valarray> 
#include <map>
#include <memory>

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

    vector<vector<int>> grid(20);

    for (int i = 0; i < 20; i++) {
        grid[i].resize(20);

        string grid_row_temp_temp;
        getline(cin, grid_row_temp_temp);

        vector<string> grid_row_temp = split(rtrim(grid_row_temp_temp));

        for (int j = 0; j < 20; j++) {
            int grid_row_item = stoi(grid_row_temp[j]);

            grid[i][j] = grid_row_item;
        }
    }

    //find biggest product of 4 in a row up = down, left = right, diagonal left & right
    int max = 0;
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            if(i < 17){
                //right
                int right = grid[i][j]*grid[i+1][j]*grid[i+2][j]*grid[i+3][j];
                max = max > right ? max : right;
                if(j < 17){
                    //right diag
                    int rightdiag = grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3];
                    max = max > rightdiag ? max : rightdiag;
                }
                if(j > 2) {
                    //left diag
                    int leftdiag = grid[i][j]*grid[i+1][j-1]*grid[i+2][j-2]*grid[i+3][j-3];
                    max = max > leftdiag ? max : leftdiag;
                }
            }

            if(j < 17){
                //down
                int down = grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3];
                max = max > down ? max : down;
            }
        }
    }

    cout << max << endl;

    return 0;
}