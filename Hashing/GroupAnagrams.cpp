vector<int> getHash(string word){
    
    vector<int> freq(26,0);
    
    for(char ch:word){
        freq[ch-'a']++;
    }
    return freq;
}

vector<vector<string>> groupAnagrams(vector<string> strs){
    //Write your code here. Do not modify the function or the parameters. 
  
    map<vector<int>, vector<string>> m;
    
    for(auto word:strs){
        m[getHash(word)].push_back(word);
    }
    
    vector<vector<string>> result;
    
    for(auto elem:m){
        vector<string> res;
        for(auto str :elem.second)
            res.push_back(str);
        result.push_back(res);
    }
    
    return result;
}
