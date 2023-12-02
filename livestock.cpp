#include <bits/stdc++.h>
using namespace std; 

int n; 
vector<pair<string, string> > constraints; 
vector<string> cows; 

int where(string c) {
    for (int i = 0; i < 8; i++) {
        if (cows[i] == c) {
            return i; 
        }
    }
    return -1; 
}

bool satisfies(void) {
    for (int i = 0; i < n; i++) {
        if (abs(where(constraints[i].first) - where(constraints[i].second)) != 1) {
            /*
            cout << constraints[i].first << " " << constraints[i].second << endl; 
            cout << where(constraints[i].first) << " " << where(constraints[i].second) << endl; 
            cout << "diff = " << abs(where(constraints[i].first) - where(constraints[i].second)) << endl; 
            cout << endl; 
            */
            return false; 
        } 
    }
    return true; 
}

int main() {
    freopen ("lineup.in", "r", stdin); 
    freopen ("lineup.out", "w", stdout); 

    cin >> n; 

    // vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"}; 
    for (int i = 0; i < n; i++) {
        string temp1; 
        string temp; 
        string temp2; 
        cin >> temp1 >> temp >> temp >> temp >> temp >> temp2; 
        constraints.push_back(make_pair(temp1, temp2)); 
        // cout << temp1 << " " << temp2 << endl; 
    }
    
    cows.push_back("Beatrice");
    cows.push_back("Belinda");
    cows.push_back("Bella");
    cows.push_back("Bessie");
    cows.push_back("Betsy");
    cows.push_back("Blue");
    cows.push_back("Buttercup");
    cows.push_back("Sue");


    for (int i = 0; i < n; i++) {
        cout << constraints[i].first << " " << constraints[i].second << endl; 
    }


   do {
    if (satisfies()) {
        for (int i = 0; i < 8; i++) {
            cout << cows[i] << endl; 
            break; 
        }
    }
    
   } while (next_permutation(cows.begin(), cows.end())); 

    return 0;
}