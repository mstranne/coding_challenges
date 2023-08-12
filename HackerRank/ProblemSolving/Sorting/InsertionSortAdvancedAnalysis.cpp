//https://www.hackerrank.com/challenges/insertion-sort/problem

#include "HelperFunctions/helpers.hpp"

/*
 * Complete the 'insertionSort' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

//haelfte timeout
int insertionSort(vector<int> arr) {
    int swaps = 0;
    map<int,int> stats; // map where we count up all prev to the current element
    stats[arr[1]] = arr[0] < arr[1] ? 0 : 1;
    for(int i = 2; i < arr.size(); i++){
        // for(int j = 0; j < i; j++){
        //     if(arr[j] > arr[i])
        //         swaps++;
        // }
        auto it = stats.lower_bound(arr[i]); //first element not less than the given key
        if(it == stats.end()){
            // highest current elem, no swap

        } else {
            if(--it == stats.begin()){
                //it is first elem
            } else {
                //it is last elem
                
            }
        }

    }
    return swaps;
}

int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));
    ofstream fout("out.txt");

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
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

        start_timer();
        int result = insertionSort(arr);
        stop_timer(); // 18.1326ms-8.4059ms
        fout << result << "\n";
    }

    fout.close();

    return 0;
}