//https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem?isFullScreen=true

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
 * Complete the 'organizingContainers' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts 2D_INTEGER_ARRAY container as parameter.
 */

string organizingContainers(vector<vector<int>> container) {
    // The challange is, you get N containers filled with N different kind of balls
    // each container is filled with different balls, but can contain different amount of balls lets say mi
    // it is only possilbe to sort via 1-1 swap from different containers
    // solution is easy, since we onlz need to say if its possible or not
    // if there are x amount of ni type balls overall, there must also be one container with
    // x amount of balls at the beginning, since we can never change the amount of balls
    // so calc row and col sums and check if each row sum has one equal col sum
    // deep back in my brain I remember there was a specific name if a matrix fulfills this
    // Permutation matrix ? TODO check in stochastik script

    int len = container.size();
    vector<int> t(len, 0);
    vector<int> C(len, 0);

    for(int n = 0; n < len; n++){
        for(int m = 0; m < len; m++){
            t[m] += container[n][m];
            C[n] += container[n][m];
        }
    }
    sort(t.begin(), t.end());
    sort(C.begin(), C.end());

    for(int i = 0; i < len; i++){
        if(t[i] != C[i]) {
            return "Impossible";
        }
    }

    return "Possible";
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));
    ofstream fout("out.txt");

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<int>> container(n);

        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            string container_row_temp_temp;
            getline(cin, container_row_temp_temp);

            vector<string> container_row_temp = split(rtrim(container_row_temp_temp));

            for (int j = 0; j < n; j++) {
                int container_row_item = stoi(container_row_temp[j]);

                container[i][j] = container_row_item;
            }
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

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