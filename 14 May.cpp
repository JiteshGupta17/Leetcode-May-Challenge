class Node {
public:

    vector<Node*> children;
    bool terminal;

    Node()
    {
        children = vector<Node*>(26, NULL);
        terminal = false;
    }

};

class Trie {
public:
    /** Initialize your data structure here. */
    Node* root;
    Trie() {

        root = new Node();

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* temp = root;
        for (char ch : word)
        {
            if (temp->children[ch - 'a'])
            {
                temp = temp->children[ch - 'a'];
            }
            else {
                Node* n = new Node();
                temp->children[ch - 'a'] = n;
                temp = n;
            }
        }

        temp->terminal = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* temp = root;
        for (char ch : word)
        {
            if (temp->children[ch - 'a'])
            {
                temp = temp->children[ch - 'a'];
            }
            else {
                return false;
            }
        }

        return temp->terminal; // whether or not we ent at terminal
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {

        Node* temp = root;

        for (char ch : prefix)
        {
            if (temp->children[ch - 'a'])
            {
                temp = temp->children[ch - 'a'];
            }
            else {
                return false;
            }
        }

        return true; // True if we reach the end of prefix which means it was present
    }
};
