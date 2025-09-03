#include<bits/stdc++.h>
using namespace std;

void bubblesort(int btime[],int artime[],int n){

for(int i=0;i<n-1;i++){

    for(int j=0;j<n-i-1;j++){

        if(artime[j]>artime[j+1]){
            swap(artime[j],artime[j+1]);
            swap(btime[j],btime[j+1]);

        }

    }


}



}

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
  


int artime[n];
for(int i=0;i<n;i++){

    cin>>artime[i];

}
int t=sizeof(bt)/sizeof(bt[0]);
    bubblesort(bt,artime,t);
    int wt[n];
    wt[0]=0;
    int counter=0;
    for(int i=1;i<n;i++){

        wt[i]=wt[i-1]+bt[i-1];
        counter+=wt[i];

    }
    //test1
    // for(int i=0;i<n;i++){

    //     cout<<"sort"<<bt[i]<<endl;
        

    //         }
           //test2
            // for(int i=0;i<n;i++){

            //     cout<<"sort"<<artime[i]<<endl;
                
            //         }
            cout<<"Total waiting time"<<counter<<endl;
cout<<"Average waiting time"<<counter<<endl;
    
}