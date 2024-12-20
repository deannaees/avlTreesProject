#include "File.hpp"
#include "FileAVL.hpp"
#include "FileTrie.hpp"
#include <vector>
#include <iostream>
#include <cassert>

int main(){

  
    File* one = new File("", "1");
    File* two = new File("abc", "12");
    File* three = new File("abd", "123");
    File* four = new File("ace", "1234");
    File* five = new File("acd", "12345");

    FileTrie test;
    test.addFile(one);
    test.addFile(two);
    test.addFile(three);
    test.addFile(four);
    test.addFile(five);

    

    // std::string filename;
    // filename ="HELLO123osandr.txt";
    // for (char c: filename){
    //     c = std::tolower(c);
    //     if(isalnum(c) || c == '.'){
    //         std::cout<<c<<" ";
    //     }
    // }


    return 0;
}   