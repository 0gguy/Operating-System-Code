#include <bits/stdc++.h>
using namespace std;
void hitcase(int arr[],int n,int t){

    cout<<"hit!! for "<<t<<" . Current Memory frames : "<<endl;
     
    for(int i=0 ; i<n ; i++){
        cout <<arr[i]<<endl;

    }

}
void misscase(int arr[],int n,int t){

     cout<<"Miss!!for "<<t<<" . Current Memory frames : "<<endl;
    for(int i=0 ; i<n ; i++){
        cout <<arr[i]<<endl;

    }

}
void hitcasespc(int arr[],int n,int t){
    cout<<"hit!! for "<<t<<" . Current Memory frames : "<<endl;
     
    for(int i=0 ; i<n ; i++){
       if (arr[i]==-1){
        continue;
       }
       
        cout <<arr[i]<<endl;

    }
}
void misscasespc(int arr[],int n,int t){
cout<<"Miss!! for "<<t<<" . Current Memory frames : "<<endl;
    for(int i=0 ; i<n ; i++){
         if (arr[i]==-1){
        continue;
       }
        cout <<arr[i]<<endl;

    }

}
int main (){

int len,n,t;
int countinitalentry=0,countinitailpointer=0;

cout << "enter Length of page reference string :";
cin >>len;
int arr[len];
cout << "enter  Page reference string values : ";
for(int i =0 ; i <len ; i++){

    cin >> arr[i];
}
cout << "enter number of frames :";
cin >> n;
int frames[n];
for (int i = 0; i < n; i++) {
    frames[i] = -1;
}
int hit=0,miss=0;
int helper=0;
for ( int i = 0 ; i < len ; i++){
helper=0;
miss ++;
countinitailpointer++;
    // hit  
    for (int j=0 ; j <n ;j++){

            if(frames[j]==arr[i]){
            hit++;
            miss--;
            helper=1;
            t=arr[i];
            hitcasespc(frames,n,t);
            break;

            }

        }
        // not hit
        if (helper==1){
            continue;
        }
        frames[countinitalentry]=arr[i];
        countinitalentry++;
        t=arr[i];
        misscasespc(frames,n,t);
        if(countinitalentry==n)
        break;

}

int point=-1,helper2=0,biggie=-1;
for (int i = countinitailpointer ; i < len ; i++){
biggie=-1;
    helper2=0;
    for(int j=0 ; j < n ; j++){

        if (arr[i]==frames[j]){
            hit++;
            t=arr[i];
            hitcase(frames,n,t);
            helper2=1;
            break;

        }

    }
    if (helper2==1){
        continue;

    }
    int last=-1,replii=-1;
    for(int a=0 ; a<n ; a++){
        int next=-1;
        for(int k = i+1 ; k<len ;k++){
            if(frames[a]==arr[k]){
                
                   next=k;
                   break;
                
            }
            
        }
        if (next==-1){
            replii=a;
            break;
        }
        if(next>last){
            last=next;
            replii=a;
        }
    }
   
frames[replii]=arr[i];

miss++;
t=arr[i];
misscase(frames,n,t);


}
cout<<"Total miss : "<<miss<<endl;
cout<<"Total hit : "<<hit<<endl;

}