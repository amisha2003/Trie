struct Node{
    Node* links[26];
    
    
    bool containKey(char ch){
        return links[ch-'a']!=NULL;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
  
    
};


int countDistinctSubstrings(string &word)
{
    Node* root=new Node();
   int ans=0;
        for(int i=0;i<word.size();i++)
        {
            Node* node=root;
            
            for(int j=i;j<word.size();j++)
            {
                if(!node->containKey(word[j])){
                    node->put(word[j],new Node());
                    ans++;
                }
                node=node->get(word[j]);
            }
        }
        return ++ans;   
    
}
