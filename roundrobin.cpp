#include<bits/stdc++.h>
using namespace std;
#define SIZE 10
int queueArr[SIZE];
int front = -1, rear = -1;

// Queue
bool isEmpty() { return (front == -1); }
void enqueue(int value) {
    if (rear == SIZE - 1) return;
    if (isEmpty()) front = 0;
    queueArr[++rear] = value;
}
int dequeue() {
    int val = queueArr[front];
    if (front == rear) front = rear = -1;
    else front++;
    return val;
}
//
int main(){
int n=5;
int at[5]={0,1,2,3,4};
int bt[5]={5,3,1,2,3};
int rt[5]={5,3,1,2,3};//duplicate array
int ct[5];
int time=0;
int tq=2;
int completed=0;

//0 entry
for (int i =0 ; i <n ; i ++){

    if (at[i]<=time){
        enqueue(i);
    }

}
//main loo[p]
while(completed <5 ){
    //
    int proid= dequeue();
    int execution= min (tq,rt[proid]);

    time = time + execution;
    rt[proid]-= execution;

    for(int i =0 ; i < n ; i++){

        if ( at[i]> (time-execution) && at[i]<= time ){
            enqueue(i);
        }

    }
    
    if (rt[proid]>0){
        enqueue(proid);
    }
    else{
        completed++;
        ct[proid]=time;
    }

}
int tat[n],wt[n];

//calcgg
for (int i =0 ; i < n ; i++){

    tat[i]=ct[i]-at[i];
    wt[i]=tat[i]-bt[i];

}
//finalcalcgg
double avgwt;
double count=0;
for(int i = 0 ; i < n ; i++){

    count+=wt[i];

}
avgwt=count/n;
cout<<"The average waiting time is "<<avgwt<<endl;





}
