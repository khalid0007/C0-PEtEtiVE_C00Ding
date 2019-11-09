#include <iostream> 
  
// For shared_ptr class 
#include <memory>  
  
using namespace std; 
  
// Trie Node class 
#define ALPHABET_SIZE 26 
  
// Trie Node class 
class TrieNode { 
  
public: 
    // Use of shared_ptr for storing Children 
    // Pointers of TrieNode 
  
    shared_ptr<TrieNode> children[ALPHABET_SIZE]; 
  
    // Tracks whether If this Node is the end of 
    // any word stored in Trie 
  
    bool isWord; 
  
    // Constructor for TrieNode 
    TrieNode() 
    { 
        for (int i = 0; i < ALPHABET_SIZE; i++) { 
            children[i] = shared_ptr<TrieNode>(); 
        } 
        isWord = false; 
    } 
};
  
class Trie { 
      
    // Storing root of the Trie 
    shared_ptr<TrieNode> root; 
    int Total_words; 
  
public: 
    Trie() 
    { 
        root = shared_ptr<TrieNode> 
                              (new TrieNode()); 
        Total_words = 0; 
    } 
  
    ~Trie() 
    { 
        // Need not delete anything  
                // as shared_ptr deallocates  
                // all memory automatically 
    } 
  
    // To convert characters of string into 
    // integer like hashing of character 
    int i2c(char c) 
    { 
        return static_cast<int>(c - 'a'); 
    } 
  
    // Insert word function 
    void insertWord(string& trieString) 
    { 
        shared_ptr<TrieNode> current = root; 
        for (int i = 0; i < trieString.size(); i++)  
                { 
              
            // If word after some prefix is not  
                        // present then creates new node 
            if (current->children[i2c(trieString[i])] ==  
                          shared_ptr<TrieNode>(nullptr))  
            { 
                current->children[i2c(trieString[i])] =  
                     shared_ptr<TrieNode>(new TrieNode()); 
            } 
            current = (current->children[i2c(trieString[i])]); 
        } 
  
        // Now word is added in Trie so at leaf node  
        // for that word isWord=true 
        current->isWord = true; 
    } 
  
    // Searching for word whether it is  
    // present in Trie 
    bool searchWord(string& trieString) 
    { 
        shared_ptr<TrieNode> current = root; 
  
        for (int i = 0; i < trieString.size(); i++)  
        { 
            // If at any point in Trie Node for particular  
            // character is not present means nullptr then  
            // return false 
            if (current->children[i2c(trieString[i])] ==  
                            shared_ptr<TrieNode>(nullptr)) 
                return false; 
            current = current->children[i2c(trieString[i])]; 
        } 
  
        // At the end of the word checking whether this 
        // word is really present or not 
        if (current->isWord == true) 
            return true; 
  
        return false; 
    } 
  
    bool Partdelete(string& trieString, shared_ptr<TrieNode>&       
                                                     checkout) 
    { 
        // Word is not present in the Trie then returns  
        // false and stops further recursion 
        if (checkout == nullptr) 
            return false; 
  
        // At the end of the word if the word is  
        // present in trie then setting isWord to  
        // false either returing false 
        if (trieString.size() == 0) { 
            if (checkout->isWord == true) { 
                checkout->isWord = false; 
                return true; 
            } 
            return false; 
        } 
  
        // String excluding first character 
        string part = trieString.substr(1); 
  
        // Recusive call to Partdelete for  
        // rest of the string(part) 
        if (Partdelete(part, checkout-> 
                      children[i2c(trieString[0])])) { 
                            
            // Checks whether it is empty node  
            // then delete this node 
            if (isEmptyNode(checkout-> 
                      children[i2c(trieString[0])])) { 
                            
                // Resetting memory and making it nullptr 
                checkout->children[i2c(trieString[0])]. 
                                                 reset(); 
                                                   
                checkout->children[i2c(trieString[0])] =  
                                                  nullptr; 
                  
                return true; 
            } 
            else
                return true; 
        } 
        else
            return false; 
  
        return false; 
    } 
  
    // For ease of recursion; passing  
    // root to Partdelete 
    bool deleteWord(string& trieString) 
    { 
        if (Partdelete(trieString, root)) 
            return true; 
        return false; 
    } 
  
    // Checks whether there is no children present 
    bool isEmptyNode(shared_ptr<TrieNode> check) const
    { 
        for (int i = 0; i < ALPHABET_SIZE; i++) { 
            if (check->children[i] != nullptr ||  
                              check->isWord == true) 
                return false; 
        } 
        return true; 
    } 
}; 
  
// Driver code 
int main() 
{ 
    // Again using shared_ptr to store Trie 
    // you can use auto_ptr here 
    shared_ptr<Trie> myTrie(new Trie()); 
  
    string word1 = "geeksfor"; 
    string word2 = "geeksforgeeks"; 
    string word3 = "nothing"; 
  
    myTrie->insertWord(word1); 
  
    if (myTrie->searchWord(word1)) 
        cout << word1 << ": Is Present" << endl; 
    else
        cout << word1 << ": Not Present" << endl; 
  
    if (myTrie->searchWord(word3)) 
        cout << word3 << ": Is Present" << endl; 
    else
        cout << word3 << ": Not Present" << endl; 
  
    myTrie->insertWord(word2); 
  
    if (myTrie->deleteWord(word2)) 
        cout << word2 << ": Successfully deleted" << endl; 
    else
        cout << word2 << ": Not Present" << endl; 
  
    if (myTrie->searchWord(word2)) 
        cout << word2 << ": Is Present" << endl; 
    else
        cout << word2 << ": Not Present" << endl; 
  
} 