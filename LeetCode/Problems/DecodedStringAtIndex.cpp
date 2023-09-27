//https://leetcode.com/problems/decoded-string-at-index/description/?envType=daily-question&envId=2023-09-27

#include "HelperFunctions/helpers.hpp"

// memory limit exeeded, so look 4 a solution where we do not write the whole string ? 
string decodeAtIndex(string s, int k) {
    stringstream ss;
    int k_ = k;
    
    for(char c : s) {
        if('a' <= c && c <= 'z')  {  //is it letter ?
            //ss << c;
            k--;
        }
        else {                      // its a digit !!
            int d = char_to_int(c);

            string repeat = ss.str();
            while(--d > 0 && k >= 0){
                //ss << repeat;
                k-=repeat.size();
            }
        }

        //cout << ss.width() << endl;
        if(k <= 0){
            string back = ss.str();
            return back.substr(k_-1, 1);
        }
    }

    assert("should never get here");

}

int main() {

    string s_in = "cpmxv8ewnfk3xxcilcmm68d2ygc88daomywc3imncfjgtwj8nrxjtwhiem5nzqnicxzo248g52y72v3yujqpvqcssrofd99lkovg";
    int k = 480551547;
    cout << decodeAtIndex(s_in, k) << endl;

    return 0;
}