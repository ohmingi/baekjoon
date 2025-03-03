#include <iostream>
#include <vector>

using namespace std;

vector<int> v[51];
int leaf = 0,root,c;

int search(int node){
    if(node == c){
        return -1;
    }
    if(v[node].empty()){
        leaf++;
        return 0;
    }

    for(int i =  0; i < v[node].size(); i++){
        int tmp = search(v[node][i]);
        if(tmp == -1 && v[node].size() == 1){
            leaf++;
        }
    }

    return 0;
}

int main(){
    int n;
    cin >> n;

   for(int i = 0 ; i < n ; i++){
        int a;
        cin >> a;

        if(a == -1) root = i;
        else{
             v[a].push_back(i);
        }
   }

   cin >> c;

   search(root);

   cout << leaf;

}