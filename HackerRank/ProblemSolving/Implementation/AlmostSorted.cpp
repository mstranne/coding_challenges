//https://www.hackerrank.com/challenges/almost-sorted/problem?isFullScreen=true

#include "HelperFunctions/helpers.hpp"

//9 aus 25 failen
void almostSorted(vector<int> arr) {
    int l = -1, r = -1;
    bool swap = true;

    for(int i = 0; i < arr.size()-1; i++){
        if(arr[i] > arr[i+1]){
            if(l != -1 && r != -1){
                cout << "no" << endl;
                return;
            }

            if(l != -1){
                r = i;
                //may need a check ?
                continue;
            }
            l = i;
            int j = 1;
            bool all_same = true;
            while(i+j < arr.size()-1 && arr[i+j] >= arr[i+j+1]) {
                if(all_same && arr[i+j] != arr[i+j+1]){
                    all_same = false;
                }
                j++;
            }
            
            if(j > 1){
                r = i + j;
                i = i + j;
            }

            if(!all_same && j >= 3){
                swap = false;
            }
        }
    }

    if(l != -1 && r == -1){
        if(l+1 == arr.size()-1 || arr[l] < arr[l+2]){
            r = l+1;
        } else {
            cout << "no" << endl;
            return;
        }
    }

    cout << "yes" << endl;
    if(l != -1 && r != -1){
        if(swap)
            cout << "swap ";
        else    
            cout << "reverse ";

        cout << l+1 << " " << r+1 << endl;
    }

}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    almostSorted(arr);

    return 0;
}