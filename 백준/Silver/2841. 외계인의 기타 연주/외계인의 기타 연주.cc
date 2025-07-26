#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n,p;
    cin >> n >> p;

    priority_queue<int>pq[7];

    int count = 0;

    while(n--){
        int a,b;
        cin >> a >> b;

        if(pq[a].empty() || pq[a].top() < b){
            pq[a].push(b);
            count++;
        }
        else if(pq[a].top() > b){
            while(pq[a].top() > b){
                pq[a].pop();
                count++;

                if(pq[a].empty()){
                    pq[a].push(b);
                    count++;
                    break;
                }

                if(pq[a].top() < b){
                    pq[a].push(b);
                    count++;
                }
            }

        }
    }

    cout << count;
}