#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {

   stringstream ss(str);
   vector<int> v;
   int aux;
   char ch;
   
   while(ss >> aux) {
       v.push_back(aux);
       ss >> ch;
   }
   return v;
}
 
int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(unsigned int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
