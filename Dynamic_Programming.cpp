#include<include>
using namespace std;


#include<vector>
#include<queue>
#include<algorithm>


/*

Pick and Not Pick Problems


House Robrer  Problem

*/


int Helper(vector<int> & array,int n,int i,vector<int>&dp){


    if(i==0){
        return array[0];
    }
    if(i<0){
        return 0;
    }

    if(dp[i]!=-1){
        return dp[i];
    }
  
    
    // Two cases 

    int NotTake=Helper(array,n,i-1,dp);
    int Take=INT_MIN;
    if(i>=1){
        Take=array[i]+Helper(array,n,i-2,dp);
    }

  return dp[i] =max(Take,NotTake);

 
}

int House_Robber(vector<int>& nums) {
       int n=nums.size();

     vector<int>dp(n+1,-1);

       int ans=Helper(nums,n,n-1,dp);
       return ans; 
    }








int main(){






}