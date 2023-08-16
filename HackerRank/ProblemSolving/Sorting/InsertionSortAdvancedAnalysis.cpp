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

    // key = array val; val = num elems of value arr[i] + all elem that are greater
    map<int,int> stats; // map where we count up all prev to the current element also anz an elems, net swaps
    //stats[arr[1]] = arr[0] < arr[1] ? 0 : 1;
    
    stats[arr[0]] = 1; 
    
    for(int i = 1; i < arr.size(); i++){
        // for(int j = 0; j < i; j++){
        //     if(arr[j] > arr[i])
        //         swaps++;
        // }
        auto it = stats.lower_bound(arr[i]); //first element not less than the given key also >=
        // it >= arr[i]
        if(it == stats.end()){
            //last one no need to swap
            stats[arr[i]] = 1;  //doch 1 passt
            it--;
        }else if(it->first == arr[i]){
              stats[arr[i]] += 1;   //des passt
              auto itNext = next(it,1);
              if(itNext != stats.end())
                swaps += itNext->second;
        } else{
            swaps += it->second;
            stats[arr[i]] = it->second;// + 1;      //hier kann ich genau des prev setzen
        }

        //it--;
        while(it-- != stats.begin()){
            it->second += 1;
            //it--;
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
        cout << result << "\n";
    }

    fout.close();
    /*
    233522831
    128027785
    7351907
    3203642
    839080835
    */
    return 0;
}