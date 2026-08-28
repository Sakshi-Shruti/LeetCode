class TrieNode {
public:
    TrieNode* children[26];
    int childCount; //no need
    bool eow;

    TrieNode() {
        childCount = 0; //no need
        eow = false;
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr; //allocate some memory
        }
    }
};

class Solution {
public:
    TrieNode* root;

    void insert(const string& word) { //we take a single word here and then perform a loop
        TrieNode* node = root;

        for(int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';

            if(!node->children[idx]) { //if child is not present then add a new node
                node->children[idx] = new TrieNode();
            }

            node = node->children[idx]; //if child is present change the root(node) and then add the char of this root(node)
            node->childCount++; //increase the count as we have more than 1 count here (no need)

        }
        node->eow = true;
    }

    string longestCommonPrefix(vector<string>& strs) { //walk the trie to find the answer
        if(strs.empty()) return "";

        root = new TrieNode(); //Create a fresh, empty root node before we start inserting anything.
        int n = strs.size();

        // i = 0 → insert("flower")
        // i = 1 → insert("flow")
        // i = 2 → insert("flight")
        for (int i = 0; i < n; i++) {
            insert(strs[i]);
        }

        string ans = "";
        TrieNode* node = root; // Start walking from the root, same as we did during insertion.

        while(true) {
            int childIndex = -1;  //initialize the count
            int totalChildren = 0;

            for (int i = 0; i < 26; i++) {
                if (node->children[i]) {
                    childIndex = i;
                    totalChildren++;
                }
            }

            // STOP CONDITION 1: 
            // If there are 0 children → dead end, nothing more to add.
            // If there are 2+ children → strings disagree here (branching),
            //    so we can't extend the prefix further.
            // ALSO stop if "eow" is true here — meaning some string already
            //    ended at this node, so it has no more letters to offer.
            if (totalChildren != 1 || node->eow) {
                break;
            }

            if (node->children[childIndex]->childCount != n) { //not important, can skip also
                break;
            }

            ans += (char)('a' + childIndex);// Convert the index back to a character and add it to our answer.
            node = node->children[childIndex];// Move one level deeper into the Trie to check the next character.
        }
        return ans;
    }
};

// totalChildren (computed fresh in the loop) answers:

// "At this node, how many different next letters do strings branch into?"

// childCount (stored inside each TrieNode, filled during insert) answers:

// "Out of all n strings, how many actually pass through this specific node?"

// These aren't redundant in general — but here's the subtlety in this specific algorithm:

// Given how the Trie is built, if a node has eow == false (no string ends there) and it's already been confirmed that all n strings reach this node, then logically, all of them must continue into whichever children exist. So if totalChildren == 1, that one child's childCount will always equal n automatically — there's nowhere else for those strings to go.

// Important = so yes we can skip this part also