int longestSubarrayKSum(vector<int> arr,int k){
    int pre =0, len = 0;
    unordered_map<int, int> m;
    for(int i = 0; i<arr.size(); i++){
        pre+=arr[i];
        
        if(pre==k)
            len = max(len, i+1);
        
        if(m.find(pre-k)!=m.end()){
            len = max(len,i-m[pre-k]);
        }else{
            m[pre] = i;
        }
    } return len;
}

int main() {
    
    vector<int> arr = { 0,-2,1,2,3,4,5,15,10,5 };
    int k = 15;
    
    cout<<longestSubarrayKSum(arr,k)<<endl;
   
}
