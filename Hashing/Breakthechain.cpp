class node{
  public:
    int data;
    node*next;
    
    node(int data){
        this->data = data;
    }
};


node*breakChain(node*head){
    node*temp = head;
    unordered_set<node*> m;
    m.insert(temp);
    
    while(temp->next != NULL){
        if(m.find(temp->next)!=m.end()){
            m.insert(temp->next);
            temp = temp->next;
        }else{
            temp->next = NULL;
            return head;
        }
    }
    return head;  
}


int main() {
    node * n = new node(7);
    node*head = n;
    
    n->next = new node(2);
    n->next->next = new node(3);
    n->next->next->next = new node(4);
    n->next->next->next->next = new node(5);
        
    node*temp = breakChain(head);
    cout<<temp->data<<endl;         
}
