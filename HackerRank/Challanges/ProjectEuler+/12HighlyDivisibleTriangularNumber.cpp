//https://www.hackerrank.com/contests/projecteuler/challenges/euler012/problem?isFullScreen=true
#include "HelperFunctions/helpers.hpp"

int NumOfDevisors(int n){
    if(n == 1)
        return 1;
    
    int num = 2;
    for(int i = 2; i < n; i++){
        if(n % i == 0)
            num++;
    }
    return num;

    if(n == 1)
        return 1;
    if(n < 4)
        return 2;

    //int num = 2;
    while(n % 2 == 0){
        n/=2;
        num++;
    }
    if(n == 1)
        return num;

    long prime = 3;
    while(n != prime){
        if(n % prime == 0){
            n /= prime;
            num++;
        }
        else
            prime+=2;
    }
    return num;
}

//timeout
int main() {
    
    int anz;
    cin >> anz;

    for(int idx = 0; idx < anz; idx++){
        int n = 0;
        cin >> n;

        
        
        int i = 0;
        int trian = 0;
        while(++i){
            trian += i;
            int num = NumOfDevisors(trian);

            if(num > n){
                cout << trian << endl;
                break;
            }
        }
        
    }

    return 0;
}
