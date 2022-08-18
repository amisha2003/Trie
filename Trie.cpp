/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

struct Node{
    Node* list[26];
    bool flag=false;
      bool containKey(char ch){
        return (list[ch-'a']!=NULL);
    }

    void put(char ch, Node* node){
        list[ch-'a']=node;
    }

    Node* get(char ch){
        return list[ch-'a'];
    }

    bool setEnd(){
        flag=true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie {
private: 
    Node* root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root=new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node=root;
        
        for(int i=0;i<word.size();i++)
        {
            if(!node->containKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
          Node* node=root;
          for(int i=0;i<word.size();i++)
          {
              if(!node->containKey(word[i]))return false;
              node=node->get(word[i]);
          }
        
        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
         Node* node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containKey(prefix[i]))return false;
            node=node->get(prefix[i]);
        }
        return true;
    }
};