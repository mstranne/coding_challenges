//https://www.hackerrank.com/challenges/absolute-permutation/problem?isFullScreen=true
#include "HelperFunctions/helpers.hpp"

vector<int> absolutePermutation(int n, int k) {
    vector<int> v;
    if( k != 0 && n%(2*k) != 0 ){
        v.push_back(-1);
        return v;
    }

    for(int i = 1; i <= n; i++)
        v.push_back(i);

    if(k == 0)
        return v;
    
    for(int i = 0; i < n ; i += 2*k){
        rotate(v.begin()+i, v.begin()+i+k, v.begin()+i+2*k);
    }
    
    return v;
}

int main()
{
    ofstream fout("out.txt");

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int k = stoi(first_multiple_input[1]);

        vector<int> result = absolutePermutation(n, k);

        for (size_t i = 0; i < result.size(); i++) {
            fout << result[i];
            cout << result[i];
            if (i != result.size() - 1) {
                fout << " ";
                cout << " ";
            }
        }

        cout << endl;
        fout << "\n";
    }

    fout.close();

    return 0;
}