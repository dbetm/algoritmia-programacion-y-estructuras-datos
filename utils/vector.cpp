#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    int bandera=0;
    vector <string> nombres;
    vector <int> orden;
    nombres.push_back("Juan");
    nombres.push_back("Hernandez");

    for(int i=0; i<nombres.size();i++)
    {
        for(int j=nombres[i].size()-1;j>=0;j--)
        {
            if(nombres[i][j]=='a'||nombres[i][j]=='A' ){
                bandera++;
            }
            cout <<nombres[i][j]<<" es: "<<(int)nombres[i][j]<< "\n";

            if(find(orden.begin(), orden.end(), (int)nombres[i][j]) == orden.end())
            {
                orden.push_back((int)nombres[i][j]);
            }

        }
    }

    cout << bandera << "\n";

    sort(orden.begin(),orden.end());
    for (int var : orden)
    {
        cout << var <<" letra: "<< (char)var<<"\n";
    }

    return 0;
}
