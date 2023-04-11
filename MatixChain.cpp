#include<iostream>
uisng namespace std;
#include<vector>
#incude<queue>
#include<algorithm>



int f(int i,int j,vector<int>&nums){

if(i==j){
    return 0;
}

int mini=1e9;

for(int k=i;k<j;k++)
{
  int step=nums[i-1]*nums[k]*numsp[j];

  int left=f(i,k,nums)+f(k+1,j,nums);


  int value=step+left;


  mini=min(mini,value);



}

return mini;

}



// if i==j print a++


// cout<<"("

// int shift=dp[i][j];

// pinrtFmaryx(i,shift,dp);
// pinrtFmaryx(shift+1,j,dp);

// cout<<")"




int MatrixChian(vector<int>&nums,int n){

int ans=f(1,n-1,nums);

return ans;

}


/*

Partision Into Equal Sunsets
*/
class Solution {
public:

int f(vector<int>&nums,int i,int n,int sum,vector<vector<int>> &dp){

if(sum==0){
    return true;
}
if(i==0){

return nums[0]==sum;

}


if(dp[i][sum]!=-1){
    return dp[i][sum];
}
int notake=f(nums,i-1,n,sum,dp);

int take=false;
if(nums[i]<=sum){
    take=f(nums,i-1,n,sum-nums[i],dp);
}
return dp[i][sum]=notake||take;



}


    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++){

            sum+=nums[i];
        }
if(sum&1){
    return false;
}
vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        int k=(sum)/2;
        return f(nums,n-1,n,k,dp);
    }
};

/*

Coin Change Problem

*/

class Solution {
public:

int f( vector<vector<int>>&dp,vector<int>&coins,int ind,int tar){

if(ind==0){
    if(tar%coins[ind]==0){
        return tar/coins[ind];
    }
    else{
        return 1e9;
    }
}
if(dp[ind][tar]!=-1){
    return dp[ind][tar];
}

    // Nottake and take

    int nottake=f(dp,coins,ind-1,tar);
    int take=1e9;
    if(coins[ind]<=tar){
        take=1+f(dp,coins,ind,tar-coins[ind]);
    }
    dp[ind][tar]=min(nottake,take);
    return dp[ind][tar];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));

    int ans= f(dp,coins,n-1,amount);
if(ans==1e9){
    return -1;

}
else{
    return ans;
}
    }
};




/*

Longest Palindromic

*/











int main(){




}