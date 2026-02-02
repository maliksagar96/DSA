/*
  Check if the given string s and t are anagrams or not.
*/



#include <iostream>
#include <unordered_map>

using namespace std;

bool ana(string s, string t) {

  unordered_map<char,int> map1;
  unordered_map<char,int> map2;

  for(char c:s) {
    map1[c]++;
  }

  for(char c:t) {
    map2[c]++;
  }
  
  if(map1 == map2) {
    cout<<"The given strings are anagrams"<<endl;
    return true;
  }

  return false;
}

int main() {

  string s = "listem";
  string t = "silent";

  ana(s,t);

  return 0;
}