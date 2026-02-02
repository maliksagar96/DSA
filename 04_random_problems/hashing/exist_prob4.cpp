/*

---
**Problem: Check Key Existence**

Given an `unordered_map<int, string>`, and an integer key, write a function that returns:

* The corresponding value if the key **exists** in the map.
* Or `"Key not found"` if the key **does not exist**.

---

**Example:**
Input: map = `{1: "apple", 2: "banana", 3: "cherry"}`, key = `2`
Output: `"banana"`

Input: map = `{1: "apple", 2: "banana", 3: "cherry"}`, key = `5`
Output: `"Key not found"`

---
*/

/*
In unordered_map a single key holds a single value. 
*/


#include <iostream> 
#include <unordered_map> 

using namespace std;

bool chechValue(const unordered_map<int, string>& map, string value) {
  
  for(auto& pair:map) {
    if(value == pair.second) {
      cout<<"The value is present."<<endl;
      return true;
    }
    
  }
  cout<<"Given value is not present."<<endl;
  return false;
}


bool chechKey(const unordered_map<int, string>& map, int key) {
  
  for(auto& pair:map) {
    if(key == pair.first) {
      cout<<"The key is present."<<endl;
      return true;
    }
    
  }
  cout<<"Given key is not present."<<endl;
  return false;
}

int main() {

  unordered_map<int, string> map;

  //map[key] = value;
  map[1] = "banana";
  map[2] = "apple";
  map[3] = "grapes";
  map[1] = "kela";

  // bool present = chechValue(map, "banana"); 
  // bool key = chechKey(map, 100); 

  // for(auto& pair:map) {
  //   cout<<"Key = "<<pair.first<<endl;
  //   cout<<"Value = "<<pair.second<<endl;    
  // }

  cout<<map.end()<<endl;

  return 0;
}