//https://leetcode.com/problems/decoded-string-at-index/description/?envType=daily-question&envId=2023-09-27

#include "HelperFunctions/helpers.hpp"

// memory limit exeeded, so look 4 a solution where we do not write the whole string ? 
string decodeAtIndex(string s, int k) {
    int tape_size = 0;
    int i = 0;
    do {
        char c = s[i];
        if('a' <= c && c <= 'z')  {  //is it letter ?
            tape_size++;
        }
        else {                      // its a digit !!
            int d = char_to_int(c);
            tape_size *= d;
        }
        if(tape_size >= k)
            break;

    } while(i++ < s.size());

    k--;
    while(k >= 0 && i >= 0){
        int idx = i;
        if(k < i){
            idx = k;
        }  
        char c = s[idx];
        if('a' <= c && c <= 'z')  {  //is it letter ?
            //if(idx == k)
            return s.substr(idx,1);
            
            k--;
            tape_size--;
        }
        else {
            int d = char_to_int(c);
            assert(tape_size % d == 0);
            int repeads = tape_size/d;
            tape_size-=repeads*(d-1);
            k = k % repeads;
        }
        i--;
    }

    return "should not get here";
}

int main() {

    string s_in = "vk6u5xhq9v";
    int k = 554;
    cout << decodeAtIndex(s_in, k) << endl; // should be x

    return 0;
}