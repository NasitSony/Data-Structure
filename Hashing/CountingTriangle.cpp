int main() {
    
   unordered_map<int,int> freqX, freqY;
    vector<vector<int>> points = {{1,2},{1,3},{2,2},{2,3}};
    for(auto p:points){
        freqX[p[0]]++;
        freqY[p[1]]++;
    }
    int ans = 0;
    
    for(auto p:points){
        ans +=(freqX[p[0]]-1)*freqY[p[1]-1];
    }
    cout<<ans;
    
}
