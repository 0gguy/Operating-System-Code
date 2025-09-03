#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of process:"<< endl;
    cin>>n;
    int bt[n];
    for(int i=0; i<n; i++)
    {
        cin>> bt[i];
    }
    int wt[n];
    wt[0]=0;
    int counter=0;
    for(int i=1;i<n;i++){

        wt[i]=wt[i-1]+bt[i-1];
        counter+=wt[i];

    }
cout<<"Total waiting time"<<counter<<endl;
cout<<"Average waiting time"<<counter/n<<endl;
    
}