#include "FileAVL.hpp"
#include "File.hpp"
#include "FileTrie.hpp"

// ALL YOUR CODE SHOULD BE IN THIS FILE. NO MODIFICATIONS SHOULD BE MADE TO FILEAVL / FILE CLASSES
// You are permitted to make helper functions (and most likely will need to)
// You must declare them "inline" | declare & implement them at the top of this file, before query()
// Below query(), implement and document all methods declared in FileTrie.hpp

/**
 * @brief Retrieves all files in the FileAVL whose file sizes are within [min, max]
 * 
 * @param min The min value of the file size query range.
 * @param max The max value of the file size query range.
 * @return std::vector<File*> storing pointers to all files in the tree within the given range.
 * @note If the query interval is in descending order (ie. the given parameters min >= max), 
        the interval from [max, min] is searched (since max >= min)
 */

inline void inOrderTraversal(Node* node, size_t min, size_t max, std::vector<File*> &result){
    //need to stay within the range 
    if( node==nullptr ){
      return;
    }
    if(node->size_ > min){
        inOrderTraversal(node->left_, min, max, result);
    }
    if(node->size_ >=min && node->size_ <= max){
        for(File* file : node->files_){ 
    
            result.push_back(file);
               
        }
    }
    if(node->size_ <max){
        inOrderTraversal(node->right_, min, max, result);
    }
    
}

std::vector<File*> FileAVL::query(size_t min, size_t max) {
    std::vector<File*> result;

    // Your code here.
    
    if (min > max){
        std::swap(min, max);
    } //ensure we have the sorted order

    //call helper function, then return it 
    inOrderTraversal(root_, min, max, result);
   
    return result;
}

 // Add file, ignore case
 //     additional specifications:
// - The root, representing the empty string (0 characters), should hold a pointer to every File.
// - The search should support a filename and extension, e.g. importantstuff.doc
// - The actual file system is not part of this project, so there are no file paths or directories, just filenames with extensions.
// - Characters allowed are a-z, 0-9, and . (period).
// - The search should be case-insensitive.--> so make it all lowercase?
void FileTrie::addFile(File* f){

    std::string filename = f->getName();
    
    FileTrieNode* curr = head;
    //convert to lowercase letters
   // bool end_of_character = false;

    for(char c: filename){
        c = std::tolower(c); //check if this should be deleted or not

            if(curr->next[c] == nullptr){

                FileTrieNode* newNodeChar = new FileTrieNode();
                //store the indx position 
                curr->next[c]=newNodeChar;

            } //end of inserting a new node into the trie 
           
            curr->matching.insert(f);

            curr = curr->next[c];
        
       // end_of_character = true;
    }

}
  // Search
std::unordered_set<File*> FileTrie::getFilesWithPrefix(const std::string& prefix) const{

    FileTrieNode* curr = head;
  // char lower_prefix;
    for (char c: prefix){
        c = std::tolower(c);
        //now next is a vector so cant use find 
        if(curr->next.at(c)){
            return {};
        }
        curr = curr->next.at(c);
    }
    return curr->matching;
}

FileTrie::FileTrie() {
    // head = new FileTrieNode;
   
}

FileTrie::~FileTrie() {
    // delete head;
    //  std::unordered_map<char, FileTrieNode*> next;
    
   

}