//https://www.hackerrank.com/challenges/queens-attack-2/problem?isFullScreen=true

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
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {

    //check if point on line
    // Ax + By - C = 0
    // -> A = (y1 - y2)
    // -> B = (x2 - x1)
    // -> C = x1y2 - x2y1 

    

    //l1 nach rechts, und dann gegen uhrzeiger sin? also l5 <-
    int min_dis[8] = {
        n-r_q,
        min(n-r_q, n-c_q),
        n-c_q,
        min(n-r_q, c_q-1),
        c_q-1,
        min(r_q-1, c_q-1),
        r_q-1,
        min(r_q-1, n-c_q)
    };
    
    for(auto o : obstacles){
        if( (o[1] - c_q) == 0){
            //cout << "obst in senk" << endl;
            if(o[0] > r_q){
                min_dis[0] = min(min_dis[0], o[0]-r_q-1);
            } else {
                min_dis[4] = min(min_dis[4], r_q-o[0]-1);
            }
        } else if( (o[0] - r_q) == 0){
            //cout << "obst in wag" << endl;
            if(o[1] > c_q){
                min_dis[2] = min(min_dis[2], o[1]-c_q-1);
            } else {
                min_dis[6] = min(min_dis[6], c_q-o[1]-1);
            }
        } else if(abs(o[1] - c_q) == abs(o[0] - r_q)) {
            //cout << "obst in diag" << endl;
            if(o[1] > c_q && o[0] > r_q){
                min_dis[1] = min(min_dis[1], o[1] - c_q-1);
            } else if(o[0] < c_q && o[1] > r_q) {
                min_dis[3] = min(min_dis[3], c_q - o[1]-1);
            } else if(o[0] < c_q && o[1] < r_q) {
                min_dis[5] = min(min_dis[5], c_q - o[1]-1);
            } else{
                min_dis[7] = min(min_dis[7], o[1] - c_q-1);
            }
        }
    }

    int res = 0;
    for(auto dis : min_dis)
        res += dis;

    return res;
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

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    vector<vector<int>> obstacles(k);

    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int obstacles_row_item = stoi(obstacles_row_temp[j]);

            obstacles[i][j] = obstacles_row_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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
