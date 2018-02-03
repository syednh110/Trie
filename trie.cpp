struct TreeTrie{
    int freq;
    TreeTrie* arr[26];
    TreeTrie(){
        freq=1;
        for(int i=0;i<26;i++)
            arr[i]=NULL;
    }
};
void add(TreeTrie* trie,string word){
    for(int i=0;i<word.size();i++){
        if(trie->arr[word[i]-'a']==NULL)
            trie->arr[word[i]-'a']=new TreeTrie();
        else
            (trie->arr[word[i]-'a']->freq)++;
        trie=trie->arr[word[i]-'a'];
    }
    //return;
}
string check(TreeTrie* trie,string word){
    string str="";
    for(int i=0;i<word.size();i++){
        if(trie->arr[word[i]-'a']->freq==1){
            str+=word[i];
            break;
        }
        else{
            str+=word[i];
        }
        trie=trie->arr[word[i]-'a'];
    }
    //str+='\0';
    return str;
}
vector<string> Solution::prefix(vector<string> &A) {
    vector<string> ans;
    TreeTrie* trie=new TreeTrie();
    trie->freq=0;
    for(int i=0;i<A.size();i++){
        add(trie,A[i]);
    }
    for(int i=0;i<A.size();i++){
        string str=check(trie,A[i]);
        ans.push_back(str);
    }
    return ans;
}
