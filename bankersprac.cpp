#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5; 
    int m = 3; 

    // Allocation matrix
    int allocation[5][3] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    // Max matrix
    int maxx[5][3] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    // Available resources
    int available[3] = {3, 3, 2};

   
    int work[m];
    for (int j = 0; j < m; j++) work[j] = available[j];

    bool finish[n];
    for (int i = 0; i < n; i++) finish[i] = false;


    int need[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = maxx[i][j] - allocation[i][j];

    // Step 2-4: Main loop
    while (true) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                bool canRun = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canRun = false;
                        break;
                    }
                }

                if (canRun) {
                   
                    for (int j = 0; j < m; j++)
                        work[j] += allocation[i][j];
                    finish[i] = true;
                    found = true;
                }
            }
        }

        
        if (!found) break;
    }

    
    bool safe = true;
    for (int i = 0; i < n; i++) {
        if (!finish[i]) {
            safe = false;
            break;
        }
    }

    if (safe)
        cout << "System is in a safe state" << endl;
    else
        cout << "System is not in a safe state" << endl;

    return 0;
}
