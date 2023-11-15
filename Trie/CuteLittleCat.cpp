class Node{
    public:
     char data;
     unordered_map<char, Node*> m;
    bool isTerminal ;
    
    Node(char data){
        this->data = data;
        isTerminal = false;
    }
};

class Trie{
    public:
    Node * root;
   
    
    Trie(){
        root = new Node('\0');
    }
    
    void insert(string word){
        Node*temp = root;
        for(char ch:word){
            if(temp->m.count(ch) == 0){
                Node* n = new Node(ch);
                temp->m[ch] = n;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal = true;
    }
    
    bool search(string word){
        Node*temp=root;
        
        for(char ch:word){
            if(temp->m[ch]==0)
                return false;
            temp=temp->m[ch];
        }
        return temp->isTerminal;
    }
    
    
};

void documentSearch_helper(Trie t, string document,int i, unordered_map<string, bool> &m){
  
    Node* temp = t.root;
    for(int j = i; j<document.length(); j++){
        char ch = document[j];
        if(temp->m.count(ch) == 0){
            return;
        }
        temp=temp->m[ch];
        if(temp->isTerminal){
            string out = document.substr(i,j-i+1);
            m[out] = true;
        }
    }
}

void documentSearch(string document, vector<string> words){
    Trie t;
     unordered_map<string, bool> m;
    for(auto w:words){
        t.insert(w);
      //  m[w] = false;
    }
    
   
    
    for(int i = 0; i<document.length(); i++){
        documentSearch_helper(t,document, i,m);
    }
    
    for(auto elem:m){
        if(elem.second){
            cout<<elem.first<<endl;
        }
    }
}

int main() {
    string document = "little cute cat loves to code in c++, java & python";
    vector<string> words{"cute cat", "ttle", "cat", "quick", "big"};
    
    //insert the words;
    //search in the document recursively
    
    documentSearch(document, words);
  
}
