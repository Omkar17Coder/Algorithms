class Solution {
public:


int Location(string txt,string pat,vector<int>&prefix){


    int n=txt.size();
    int m=pat.size();
    int i=0; // Pointer to txt
    int j=0; // Pointer to pat
    while(i<=n){
        if(j==m){
            return i-m;
        }
        if(txt[i]==pat[j]){
            i++;
            j++;
        }
        else{
            if(j==0){
                i++;
            }
            else{
                j=prefix[j-1];

            }
        }
    }
    return -1;


}


vector<int>CalPrefix(string s){
    int n=s.size();
    vector<int>prefix(n+1,0);
    int i=0;
    int j=1;
    while(j<n){
        if(s[i]==s[j]){
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
    int strStr(string haystack, string needle) {

        int n=haystack.size();
        int m=needle.size();
        if(n==1 && m==1){
            if(haystack[0]==needle[0]){
                return 0;
            }
            else{
                return -1;
            }
        }

        vector<int>prefix=CalPrefix(needle);
        int ans=Location(haystack,needle,prefix);
        return ans;
        
    }
};