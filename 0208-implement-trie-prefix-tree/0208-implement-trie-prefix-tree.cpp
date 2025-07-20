// Striver Implementation (Little hard)
class Trie {
public:
    // Node structure for Trie
    struct Node {
        // Array to store links to child nodes,each index represents a letter
        Node* links[26];
        // Flag indicating if the node marks the end of a word
        bool flag = false;

        // Check if the node contains a specific key (letter)
        bool containsKey(char ch) { return links[ch - 'a'] != NULL; }

        // Insert a new node with a specific key (letter) into the Trie
        void put(char ch, Node* node) { links[ch - 'a'] = node; }

        // Get the node with a specific key (letter) from the Trie
        Node* get(char ch) { return links[ch - 'a']; }

        // Set the current node as the end of a word
        void setEnd() { flag = true; }

        // Check if the current node marks the end of a word
        bool isEnd() { return flag; }
    };
    Node* root;
    // Constructor to initialize the Trie with an empty root node
    Trie() { root = new Node(); }

    // Inserts a word into the Trie
    // Time Complexity O(len), where len is the length of the word
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                // Create a new node for the letter if not present
                node->put(word[i], new Node());
            }
            // Move to the next node
            node = node->get(word[i]);
        }
        // Mark the end of the word
        node->setEnd();
    }

    // Returns if the word is in the trie
    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                // If a letter is not found, the word is not in the Trie
                return false;
            }
            // Move to the next node
            node = node->get(word[i]);
        }
        // Check if the last node marks the end of a word
        return node->isEnd();
    }

    // Returns if there is any word in the trie that starts with the given prefix
    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containsKey(prefix[i])) {
                // If a letter is not found, there is no word with the given prefix
                return false;
            }
            // Move to the next node
            node = node->get(prefix[i]);
        }
        // The prefix is found in the Trie
        return true;
    }
};

// A little shorter and easier code - 
/*
class Trie {
public:
    struct TrieNode {
        bool isWord;
        TrieNode* children[26];
        TrieNode() {
            isWord = false;
            memset(children, 0, sizeof(children)); // Initialize all children to null
        }
    };
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isWord = true;
    }
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index])
                return false;
            node = node->children[index];
        }
        return node->isWord;
    }
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!node->children[index])
                return false;
            node = node->children[index];
        }
        return true;
    }
};
*/

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */



// Implement Trie II
// Striver Implementation (Little hard)
/** 
// Define a class for the trie data structure
class Trie {
public:
    // Define a struct for each node in the trie
    struct Node {
        // Array to store links to child nodes
        Node* links[26];
        // Counter for number of words that end at this node
        int cntEndWith = 0;
        // Counter for number of words that have this node as a prefix
        int cntPrefix = 0;

        // Function to check if the node contains a specific key
        bool containsKey(char ch) {
            // Check if the link corresponding to the character exists
            return (links[ch - 'a'] != NULL);
        }
        // Function to get the child node corresponding to a key
        Node* get(char ch) {
            // Return the link corresponding to the character
            return links[ch - 'a'];
        }
        // Function to insert a child node with a specific key
        void put(char ch, Node* node) {
            // Set the link corresponding to the character to the provided node
            links[ch - 'a'] = node;
        }
        // Function to increment the count of words that end at this node
        void increaseEnd() {
            // Increment the counter
            cntEndWith++;
        }
        // Function to increment the count of words that have this node as a
        // prefix
        void increasePrefix() {
            // Increment the counter
            cntPrefix++;
        }
        // Function to decrement the count of words that end at this node
        void deleteEnd() {
            // Decrement the counter
            cntEndWith--;
        }
        // Function to decrement the count of words that have this node as a
        // prefix
        void reducePrefix() {
            // Decrement the counter
            cntPrefix--;
        }
    };
    // Pointer to the root node of the trie
    Node* root;
    // Constructor to initialize the trie with an empty root node
    Trie() {
        // Create a new root node
        root = new Node();
    }

    // Function to insert a word into the trie
    void insert(string word) {
        // Start from the root node
        Node* node = root;
        // Iterate over each character in the word
        for (int i = 0; i < word.size(); i++) {
            // If the character is not already in the trie
            if (!node->containsKey(word[i])) {
                // Create a new node for the character
                node->put(word[i], new Node());
            }
            // Move to the child node corresponding to the character
            node = node->get(word[i]);
            // Increment the prefix count for the node
            node->increasePrefix();
        }
        // Increment the end count for the last node of the word
        node->increaseEnd();
    }

    // Function to count the number of words equal to a given word
    int countWordsEqualTo(string word) {
        // Start from the root node
        Node* node = root;
        // Iterate over each character in the word
        for (int i = 0; i < word.size(); i++) {
            // If the character is found in the trie
            if (node->containsKey(word[i])) {
                // Move to the child node corresponding to the character
                node = node->get(word[i]);
            } else {
                // Return 0 if the character is not found
                return 0;
            }
        }
        // Return the count of words ending at the node
        return node->cntEndWith;
    }

    // Function to count the number of words starting with a given prefix
    int countWordsStartingWith(string word) {
        // Start from the root node
        Node* node = root;
        // Iterate over each character in the prefix
        for (int i = 0; i < word.size(); i++) {
            // If the character is found in the trie
            if (node->containsKey(word[i])) {
                // Move to the child node corresponding to the character
                node = node->get(word[i]);
            } else {
                // Return 0 if the character is not found
                return 0;
            }
        }
        // Return the count of words with the prefix
        return node->cntPrefix;
    }

    // Function to erase a word from the trie
    void erase(string word) {
        // Start from the root node
        Node* node = root;
        // Iterate over each character in the word
        for (int i = 0; i < word.size(); i++) {
            // If the character is found in the trie
            if (node->containsKey(word[i])) {
                // Move to the child node corresponding to the character
                node = node->get(word[i]);
                // Decrement the prefix count for the node
                node->reducePrefix();
            } else {
                // Return if the character is not found
                return;
            }
        }
        // Decrement the end count for the last node of the word
        node->deleteEnd();
    }
};
*/

// A little shorter and easier code - 
/*
class Trie {
public:
    struct TrieNode {
        TrieNode* children[26];
        int cntEndWith;
        int cntPrefix;

        TrieNode() {
            memset(children, 0, sizeof(children));
            cntEndWith = 0;
            cntPrefix = 0;
        }
    };

    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
            node->cntPrefix++;
        }
        node->cntEndWith++;
    }

    int countWordsEqualTo(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index])
                return 0;
            node = node->children[index];
        }
        return node->cntEndWith;
    }

    int countWordsStartingWith(string prefix) {
        TrieNode* node = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (!node->children[index])
                return 0;
            node = node->children[index];
        }
        return node->cntPrefix;
    }

    void erase(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index])
                return;
            node = node->children[index];
            node->cntPrefix--;
        }
        node->cntEndWith--;
    }
};
*/