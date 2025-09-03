#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of process: " << endl;
    cin >> n;
    
    int P[n];
    int BT[n];
    
    cout << "Enter burst time: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> BT[i];
        P[i] = i + 1;
    }
    
    int AT[n];
    
    cout << "Enter arrival time: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> AT[i];
    }
    
    int RT[n], CT[n], TAT[n], WT[n];
    
    for(int i = 0; i < n; i++)
    {
        RT[i] = BT[i];
    }
    
    int complete = 0, time = 0;
    
    while(complete < n)
    {
        int smallest = -1;
        
        for(int i = 0; i < n; i++)
        {
            if(AT[i] <= time && RT[i] > 0)
            {
                if(smallest == -1 || RT[i] < RT[smallest])
                {
                    smallest = i;
                }
            }
        }
        
        if(smallest == -1)
        {
            time++;
            continue;
        }
        
        RT[smallest]--;
        time++;
        
        if(RT[smallest] == 0)
        {
            complete++;
            CT[smallest] = time;
            TAT[smallest] = CT[smallest] - AT[smallest];
            WT[smallest] = TAT[smallest] - BT[smallest];
        }
    }
    
    cout << "P\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t" << AT[i] << "\t" << BT[i] << "\t" << CT[i] << "\t" << TAT[i] << "\t" << WT[i] << endl;
    }
    
    return 0;
}