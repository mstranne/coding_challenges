//https://www.hackerrank.com/contests/projecteuler/challenges/euler013/problem?isFullScreen=true
#include "HelperFunctions/helpers.hpp"

//TODO cleanup
int main() {
    int n;
    cin >> n;
    string t_temp;
    getline(cin, t_temp);

    unsigned int digit = 100000;
    vector<unsigned int> sum;
    for(int i = 0; i < n; i++){
        
        getline(cin, t_temp);

        unsigned int carry = 0;
        int j = 0;
        for(; j < t_temp.size()/5; j++){
            string part = t_temp.substr(t_temp.size()-j*5-5, 5);
            //cout << part;
            unsigned int sub = atoi(part.c_str());
            if(sum.size() < j+1){
                sum.push_back(sub);
            } else {
                sub = sub + sum[j] + carry;
                if(sub >= digit){
                    carry = sub/digit;
                    sum[j] = sub % digit;
                } else {
                    sum[j] = sub % digit;
                    carry = 0;
                }
            }
        }

        while(carry != 0){
            
            unsigned int sub = carry;
            if(sum.size() < j+1){
                sum.push_back(carry);
                carry = 0;
            } else {
                sub = sum[j] + carry;
                if(sub >= digit){
                    carry = sub/digit;
                    sum[j] = sub % digit;
                } else {
                    sum[j] = sub % digit;
                    carry = 0;
                }
            }
            j++;
        }

        //cout << endl << t_temp << endl;
    }

    int digs_printed = 0;
    int curr_vec_pos = sum.size()-1;
    int curr_digi = digit;
    bool leading_zeros = true;
    while (digs_printed < 10)
    {
        if(curr_digi == 1){
            curr_digi = digit;
            curr_vec_pos--;
        }

        unsigned int num = sum[curr_vec_pos];
        num = num % curr_digi;
        curr_digi/=10;
        num = num/curr_digi;
        if(leading_zeros && num == 0){

        } else{
            leading_zeros = false;
            cout << num;
            digs_printed++;
        }
    }
    return 0;
}
