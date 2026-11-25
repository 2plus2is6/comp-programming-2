// #include <bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;

int main(){
    
    int n;
    long long d;
    cin >> n >> d;



    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }


    sort(arr.begin(),arr.end());

    int ans = 0;
    int i = 0;

    while (i < n) {
        long long curr = arr[i];
        ans++;

        while (i<n && arr[i]- curr <=d) {
            i++;
        } 
    
    }

    cout << ans << endl; 


    return 0;
}