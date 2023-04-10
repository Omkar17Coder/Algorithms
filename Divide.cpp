#include<iostream>
using namespace std;

#include<vector>
#include<queue>
#include<alogorithm>


/**

Time Complexity for Maximum Sub array this code is O(nlogn)






*/


int CalculateCross(vector<int>&array,int n,int l,int h,int mid){


int Leftmax=INT_MIN;
int Rightmax=INT_MIN;

int left=0;

int Right=0;

// Left direction

for(int i=mid;i>=l;i--){

left+=array[i];
Leftmax=max(Leftmax,left);

}

// Right Direction

for(j=mid;j<=h;j++)
{
Right+=array[j];
Rightmax=max(Rightmax,right);

}

return max(max(Rightmax+Leftmax-array[mid],Rightmax),Leftmax);

}


int MaxSumArray(vector<int>&array,int n,int i,int j){

if(i>=j){
    return -1;
}

else{
   int mid=(i+j)/2;
    int Left=MaxSumArray(array,n,i,mid);
    int Right=MaxSumArray(array,n,moid+1,j);
    int cross=CalculateCross(array,n,i,j,mid);

    return max(max(Left,Right),cross);
}


}


/*/

Inversion Count for an array indicates – how far (or close) the array is from being sorted. 
If the array is already sorted, then the inversion count is 0, but if the array is sorted in reverse order,
 the inversion count is the maximum. 

Given an array a[]. The task is to find the inversion count of a[]. Where two elements a[i] and a[j]
 form an inversion if a[i] > a[j] and i < j.

*/





int CountValue(vector<int>&nums,int n,int l,int h,int mid){




int inv_count=0;


vector<int>temp(n,0);
int i=l;
int j=mid;
int k=l;

while(i<=mid-1 && j<=h){



    if(nums[i]<=nums[j]){
        temp[k++]=nums[i++];

    }
    else{
       temp[K++]=nums[j++];
       inv_count+=mid-i;
    }
}

while(i<=mid-1){

    temp[k++]=nums[i++];
}

while(j<=h){
    temp[k++]=nums[j++];
}

// merge back into main array

for(int z=l;z<=h;z++){


    nums[z]=temp[z];

}



return inv_count;

}



int countInversion(vector<int>&nums,int n,int l,int h){

if(l>=h){
    return 0;
}

int mid=(l+h)/2;
int Left=countInversion(nums,n,l,mid);
int Right=countInversion(nums,n,mid+1,h);
int Value=CountValue(nums,n,l,h,mid);

return Left=Right+Value;





}







int main(){





}