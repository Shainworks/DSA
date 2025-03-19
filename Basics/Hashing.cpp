#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    string s;
    cin >>s;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //precompute:
    int hash[13] = {0};
    for (int i = 0; i < n; i++) {
        hash[arr[i]] += 1;
    }
    //for hashing chracters
    int hash[256] = {0};
    for (int i = 0; i < s.size(); i++) {
        hash[s[i]]++;       //The values will be typecasted into ASCII Values
    }

    int q;
    cin >> q;
    while (q--) {
        int number;
        cin >> number;
        // fetching:
        cout << hash[number] << endl;
    }
    //for hashing characters
    while (q--) {
        char c;
        cin >> c;
        // fetch:
        cout << hash[c] << endl;
    }
    //Hashing theory using map
    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }

    // //precompute:
    // map<int, int> mp;
    // for (int i = 0; i < n; i++) {
    //     mp[arr[i]]++;
    // }

    // // iterate over the map:
    // /* for(auto it : mp){
    //         cout << it.first << "->" << it.second << endl;
    //     }
    // */

    // int q;
    // cin >> q;
    // while (q--) {
    //     int number;
    //     cin >> number;
    //     // fetch:
    //     cout << mp[number] << endl;
    // }
    return 0;
}

//Code for the max and min frequency in an array
// #include <bits/stdc++.h>
// using namespace std;

// void Frequency(int arr[], int n)
// {
//     unordered_map<int, int> map;

//     for (int i = 0; i < n; i++)
//         map[arr[i]]++;

//     int maxFreq = 0, minFreq = n;
//     int maxEle = 0, minEle = 0;
//     // Traverse through map to find the elements.
//     for (auto it : map) {
//         int count = it.second;
//         int element = it.first;

//         if (count > maxFreq) {
//             maxEle = element;
//             maxFreq = count;
//         }
//         if (count < minFreq) {
//             minEle = element;
//             minFreq = count;
//         }
//     }

//     cout << "The highest frequency element is: " << maxEle << "\n";
//     cout << "The lowest frequency element is: " << minEle << "\n";
// }

// int main()
// {
//     int arr[] = {10, 5, 10, 15, 10, 5};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     Frequency(arr, n);
//     return 0;
// }