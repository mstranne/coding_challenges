
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

class BigInt {
    private :
        vector<int> chunks;
        int chunk_size = 100000; // must be 10er schiritte
    
    public:
        BigInt() {}
        BigInt(int a){
            if(a < chunk_size)
                chunks.push_back(a);
            else {
                int pos = 0;
                do{
                    int uebertrag = 0;
                    int curr = a % chunk_size;
                    if(chunks.size() == pos){
                        chunks.push_back(curr);
                    } else{ // gibs im construktor net nur fes adden
                        chunks[pos] += curr;
                        if(chunks[pos] > chunk_size){
                            uebertrag = chunks[pos] / chunk_size; // kann net mehr als 1 sein ?
                            chunks[pos] = chunks[pos] % chunk_size;
                        }
                    }
                    a = a/chunk_size;
                    a+=uebertrag;
                    pos++;
                }while( a > 0 );
            }
        }

        BigInt operator+(const BigInt b){
            BigInt ret;
            int pos = 0;
            int uebertrag = 0;
            do{
                int curr = uebertrag;
                if(pos < chunks.size())
                    curr += chunks[pos];
                if(pos < b.chunks.size())
                    curr += b.chunks[pos];

                //int curr = chunks[pos] + b.chunks[pos] + ;

                if(ret.chunks.size() == pos){
                    if (curr < chunk_size){
                        ret.chunks.push_back(curr);
                        uebertrag = 0;
                    } else {
                        uebertrag = curr / chunk_size;
                        curr = curr % chunk_size;
                        ret.chunks.push_back(curr);
                    }
                } 

                pos++;

            }while(uebertrag > 0 || pos < chunks.size() || pos < b.chunks.size());

            return ret;
        }

        void print(){
            bool first = true;
            for (int i = chunks.size()-1; i >= 0; i--)
            {
                if(first)
                {
                    cout << chunks[i];
                    first = false;
                } else {
                    for(int j = chunk_size/10; j > 0; j = j/10){
                        if(chunks[i] < j)
                            cout << "0";
                    }
                    cout << chunks[i];
                }
            }
            cout << endl;
            
        }
};


void extraLongFactorials(int n) {
    BigInt erg(n);
    for (int i = n-1; i > 0; i--)
    {
        BigInt curr = erg;
        for(int j = 1; j < i; j++){ //mit 1 weil erste mal steht bereits in curr
            erg = erg+curr;
        }
    }
    erg.print();
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
