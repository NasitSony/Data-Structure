class Node{
    public:
     Node*left, *right;
};

class Trie{
    public:
    Node * root;
   
    
    Trie(){
        root = new Node();
    }
    
    void insert(int n){
        
        Node*temp = root;
        
       for(int i = 31; i>=0; i--){
           int bit = (n>>i)&1;
           if(bit == 1){
               if(temp->right == NULL){
                   temp->right= new Node();
               }
               temp = temp->right;
           }else{
                if(temp->left == NULL){
                   temp->left= new Node();
               }
               temp = temp->left;
           }
       }
       
    }
    
    int max_xor_helper(int number){
        Node *temp=root;
        int currentAns = 0;
        
        for(int i = 31; i>=0; i--){
            int bit = (number>>i)&1;
            
            if(bit == 1){
                if(temp->left != NULL){
                    temp=temp->left;
                    currentAns += (1<<i);
                }else{
                    temp=temp->right;
                }
            }else{
                if(temp->right != NULL){
                    temp=temp->right;
                    currentAns += (1<<i);
                }else{
                    temp=temp->left;
                }
            }
        }
        
        return currentAns;
    }
    
    int max_xor(vector<int> numbers){
        int n = numbers.size(), max_xor = 0;
        
        for(int i = 0; i<n; i++){
            int number = numbers[i];
            insert(number);
            int current_xor = max_xor_helper(number);
            max_xor = max(max_xor, current_xor);
        }
        
        return max_xor;
    }
};

int main() {
    vector<int> numbers = {3,10,5,25,9,2};
    Trie t;
    cout<<t.max_xor(numbers)<<endl;
}
