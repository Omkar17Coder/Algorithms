#include<iostream>
using namespace std;

#include<vector>
#include<queue>
#include<limits.h>
#include<algorithm>



vector<int>Cal(string txt,int n){

vector<int>prefix(n);
prefix[0]=0;

int i=0;
int j=1;
while(j<n){

    if(txt[i]==txt[j]){
        prefix[j]=i+1;
        i++;
        j++;
    }
    else{
        if(i==0){
            j++;
        }
        else{
            i=prefix[i-1];
        }
    }
}
return prefix;

}



int Location(string txt,string pat,int n,int m,vector<int>&prefix){


int  i=0;
int j=0;
while(j<m){
if(j==m){
    return i-m;
}
    if(txt[i]==pat[j]){
        i++;
        j++;
    }
    else{

        if(j!=0){
            j=prefix[j-1];
        }
        else{
            i++;
        }
    }
}
return -1; // Not Found.

}



int KMP(string txt,string pat){
    int n=txt.size();
    int m=pat.size();

    vector<int>prefix(n)=Cal(txt,n);

    int ans=Location(txt,pat,n,n,prefix);
    return ans;

}





int main(){

}