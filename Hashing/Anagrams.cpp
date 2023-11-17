vector<int> getHash(string s){
    vector<int> freq(26,0);
    
    for(char ch:s){
        freq[ch-'a']++;
    }
    return freq;
}
int main() {
    
    string s = "abba";
    map<vector<int>,int> m;
     for(int i = 0; i<=s.size(); i++){
         for(int j = i; j<s.size(); j++){
             vector<int> hash = getHash(s.substr(i,j));
             m[hash]++;
         }
     }
    int ans = 0;
    
    for(auto p:m){
        if(p.second>=2)
            ans += (p.second*(p.second-1))/2;
    }
  
    cout<<ans<<endl;
}
