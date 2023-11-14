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
};
