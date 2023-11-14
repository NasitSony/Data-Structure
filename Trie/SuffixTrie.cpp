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

class SuffixTrie{
    public:
    Node * root;
   
    
    SuffixTrie(){
        root = new Node('\0');
    }
    
    void insert_helper(string word){
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
    
    void insert(string word){
        for(int i = 0; word[i]!= '\0'; i++)
            insert_helper(word.substr(i));
    }
};

int main() {
    std::cout << "Hello World!\n";
    
    string input = "hello";
    string suffixes[] ={"lo","ell","hello"};
    SuffixTrie t;
    t.insert(input);
    for(string suffix:suffixes){
        if(t.search(suffix))
            cout<<"yes"<<endl;
    }
  
}
