//https://www.hackerrank.com/contests/projecteuler/challenges/euler012/problem?isFullScreen=true
#include "HelperFunctions/helpers.hpp"


int NumOfDevisors(int n){
   int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are equal,
            // count only one
            if (n / i == i)
                cnt++;
 
            else // Otherwise count both
                cnt = cnt + 2;
        }
    }
    return cnt;
}

int main() {
    
    int anz;
    cin >> anz;
    vector<int> input;
    vector<int> res;
    vector<int> orig_input;
    for(int idx = 0; idx < anz; idx++){
        int n = 0;
        cin >> n;
        input.push_back(n);
        orig_input.push_back(n);
    }

    sort(input.begin(),input.end());

    auto n_it = input.begin();
    int i = 0;
    int trian = 0;
    while(++i){
        trian += i;
        int num = NumOfDevisors(trian);

        while(num > *n_it){
            //cout << trian << endl;
            res.push_back(trian);
            n_it++;
            if(n_it == input.end()){
                break;
            }
        }    
        if(n_it == input.end()){
            break;
        }
    }

    for(i = 0; i < anz; i++){
        for (int j = 0; j < anz; j++)
        {
            if(orig_input[i] == input[j]){
                cout << res[j] << endl;
                break;
            }
        }
    }

    return 0;
}
