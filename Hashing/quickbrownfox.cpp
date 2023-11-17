int min_bar(string s, unordered_set<string> &m,int idx){
    if(s[idx]=='\0'){
        return 0;
    }
    
    int ans = INT_MAX;
    string current_string = "";
    
    for(int j = idx; s[j]!='\0';j++){
        current_string+=s[j];
        if(m.find(current_string)!= m.end()){
            int remainingAns = min_bar(s,m,j+1);
            if(remainingAns != -1){
                ans = min(ans,1+remainingAns);
            }
        }
    }
    
    if(ans==INT_MAX)
        return -1;
return ans;
}

int main() {
    
    string str = "thequickbrownfox";
    vector<string>  words = {"the", "fox","jumps","lazy","lazyfox","highbridge","the", "over", "bridge", "high", "tall","quick", "brown", "brownfox"};
    
    unordered_set<string> m;
    for(auto word:words){
        m.insert(word);
    }
   int out = min_bar(str,m,0);
    cout<<out<<endl;
}
