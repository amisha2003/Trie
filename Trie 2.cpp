
struct Node{
    Node* Link[26];
    int ew=0;
    int cp=0;
    bool containKey(char ch){
        return Link[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        Link[ch-'a']=node;
    }
    void incr(){
        cp++;
    }
    Node* get(char ch){
        return Link[ch-'a'];
    }
    void end(){
        ew++;
    }
    int totalword(){
        return ew;
    }
    int totalstart(){
        return cp;
    }
    void eraseChar(){
        cp--;
    }
    void eraseend(){
        ew--;
    }
};

class Trie{
private:
    Node* root;
    public:

    Trie(){
        root=new Node();
    }

    void insert(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->incr();
        }
        node->end();
    }

    int countWordsEqualTo(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i]))return 0;
            node=node->get(word[i]);
        }
        return node->totalword();
    }

    int countWordsStartingWith(string &word){
       Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i]))return 0;
            node=node->get(word[i]);
        }
        return node->totalstart();
    }

    void erase(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            node=node->get(word[i]);
            node->eraseChar();
            
        }
        node->eraseend();
    }
};
