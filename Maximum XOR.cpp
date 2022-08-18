struct Node{
    Node* links[2];
    bool containKey(int bit){
        return links[bit]!=NULL;
    }
    void put(int bit,Node* node){
        links[bit]=node;
    }
    Node* get(int bit){
        return links[bit];
    }
};
class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->containKey(bit)){
                node->put(bit,new Node());
            }
           node= node->get(bit);
        }
    }
    
    int getmax(int num){
        Node* node=root;
        int maxNum=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containKey(1-bit)){
                maxNum=maxNum | (1<<i);
                node=node->get(1-bit); 
            }
            else node=node->get(bit);
        }
        return maxNum;
    }
    
};
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    Trie trie;
    for(auto & it:arr1)trie.insert(it);
    
    int maxi=0;
    for(auto &it:arr2){
        maxi=max(maxi,trie.getmax(it));
    }
    return maxi;
    
}
