struct Trie{
    // current node structure's serialized representation
    string serial;
    // current node's child nodes
    unordered_map<string, Trie*> children;
};

class Solution {
public:
    // hash table records the occurrence times of each serialized
    unordered_map<string, int> freq;
    // record the path from the root node to the current node.
    vector<string> path;

    vector<vector<string>> ans;

    // post-order traversal based on depth-first search, calculate the serialized representation of each node structure
    void construct(Trie* node){
        if( node->children.empty() )
            return;
        
        vector<string> v;
        // if it is not a leaf node, the serialization representation of the child node structure needs to be calculated first.
        for(auto& [folder, child]: node->children){
            construct(child);
            v.push_back(folder+"("+child->serial+")");
        }
        // to prevent issues with order, sorting is needed
        sort(v.begin(),v.end());
        for(string& s:v){
            node->serial += move(s);
        }
        // add to hash table
        freq[node->serial]++;
    }

    void operate(Trie* node){
        // if the serialization appears more than once in the hash table, it needs to be deleted.
        if(freq[node->serial] > 1){
            return;
        }
        if(!path.empty()){
            ans.push_back(path);
        }
        for(auto& [folder, child] : node->children){
            path.push_back(folder);
            operate(child);
            path.pop_back();
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        
        // build the trie
        Trie* root = new Trie();
        for(vector<string>& path:paths){
            Trie* cur = root;
            for(string& node:path){
                if( !cur->children.count(node)){
                    cur->children[node] = new Trie();
                }
                cur = cur->children[node];
            }
        }
        construct(root);
        operate(root);
        
        return ans;
    }
};
