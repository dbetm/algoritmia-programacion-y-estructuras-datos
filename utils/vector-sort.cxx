#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

/* You are given N integers.Sort the N integers and print the sorted order.
 * 
 * Input Format:
 * The first line of the input contains N where N is the number of integers. The next line contains N integers.
 * 
 * Output Format
 * Print the integers in the sorted order one by one in a single line followed by a space.
*/

using namespace std;


int main() {
	
    long long int N, item;
    vector <long long int> v;
    cin >> N;
    for(long long int i = 0; i < N; i++) {
        cin >> item;
        v.push_back(item); //para ir a agregando el elemento que se lee al vector
    }
    
    sort(v.begin(),v.end()); // sort es un método de la biblioteca algorithm
    
    for(unsigned long long int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    
    return 0;
}
