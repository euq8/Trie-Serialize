// serialize 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
 
    // isEndOfWord is true if the node represents end of a word
    bool isEndOfWord;
};
 
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void) {
  struct TrieNode *pNode =  new TrieNode;
  pNode->isEndOfWord = false;
 
  for (int i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;

  return pNode;
}
 
// If not present, inserts key into trie. If the key is prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, string key) {
  struct TrieNode *pCrawl = root;
  for (int i = 0; i < key.length(); i++) {
    int index = key[i] - 'a';
    if (!pCrawl->children[index]) pCrawl->children[index] = getNode();

    pCrawl = pCrawl->children[index];
  }
  // mark last node as leaf
  pCrawl->isEndOfWord = true;
}

int main(){
  fstream newfile;
  
  // ROOT node trie 
  struct TrieNode *root = getNode();
  
  // open a file to perform read operation using file object
  newfile.open("friends.txt",ios::in);
  
  if (newfile.is_open()){ //checking whether the file is open
    string tp;
    while(getline(newfile, tp)){ //read data from file object and put it into string.
      // deserializeing textfile to trie / inserting friends to trie
      insert(root, tp);
      cout << "Inserted:- " << tp << "\n"; //print the data of the string
    }
    newfile.close(); //close the file object.
  }
}
