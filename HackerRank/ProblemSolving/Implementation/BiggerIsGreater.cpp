//https://www.hackerrank.com/challenges/bigger-is-greater/problem?isFullScreen=true

#include "HelperFunctions/helpers.hpp"

string biggerIsGreater(string w) {

    int idx = -1;
    int i = w.size()-2;
    for(;i >= 0 && idx == -1; i--){
        for(int j = w.size()-1; j > i; j--){
            if(w[i] < w[j] && (idx == -1 || w[idx] > w[j])){
                idx = j;
            }
        }
    }
    i++;
    if(idx == -1){
        return "no answer";
    }

    iter_swap(w.begin()+i, w.begin()+idx);
    sort(w.begin()+i+1, w.end());
    return w;
}

int main()
{
    ofstream fout("out.txt");

    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        cout << result << "\n";
        fout << result << "\n";
    }

    fout.close();

    return 0;
}