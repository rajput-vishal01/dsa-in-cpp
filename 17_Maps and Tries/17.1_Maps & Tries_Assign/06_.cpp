// leetcode 648. Replace Words
// from LC--208

class TrieNode{
    public: 
        char data;
        unordered_map<char,TrieNode*> children;
        bool isTerminal;

        TrieNode(char val) {
            data = val;
            isTerminal = false;
        }
};

void insertWord(TrieNode* root, string word) {
    // base case 
    if(word.length() == 0) {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()) {
        // present
        child = root->children[ch];
    }
    else {
        // absent
        child = new TrieNode(ch);
        root->children[ch] = child;
    }
    insertWord(child, word.substr(1));
}

string getRoot(TrieNode* root, string word) {
    TrieNode* curr = root;
    string prefix = "";
    for(char ch : word) {
        if(curr->children.find(ch) == curr->children.end()) break;
        prefix += ch;
        curr = curr->children[ch];
        if(curr->isTerminal) return prefix;
    }
    return word;
}

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        TrieNode* root = new TrieNode('-');
        
        // insert all roots
        for(auto &w : dict){
            insertWord(root, w);
        }

        stringstream ss(sentence);
        string word;
        string ans = "";
        
        // replace each word with its shortest root
        while(ss >> word){
            ans += getRoot(root, word) + " ";
        }

        if(!ans.empty()) ans.pop_back(); // remove trailing space
        return ans;
    }
};
