#include  <iostream>
#include <vector>
#include <queue>

using namespace std;

int V,E;
vector<pair<int,int>> adj[20001];
int dist[20001];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

void dijkstra(int s) {
  fill(dist,dist+20001,1e9);

  dist[s]=0;
  pq.push({0,s});

  while (!pq.empty()) {
    int d=pq.top().first;
    int curr=pq.top().second;
    pq.pop();

    if (dist[curr] < d) {continue;}

    for (auto a : adj[curr]) {
      int next = a.first;
      int cost = a.second;

      if (dist[curr] + cost < dist[next]) {
        dist[next] = dist[curr] + cost;
        pq.push({dist[next],next});
      }
    }

  }
}



int main() {
  int k;
  cin >> V >> E >> k;

  for (int i = 1; i <= E; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].push_back(make_pair(v,w));
  }

  dijkstra(k);

  for (int i = 1; i <= V; i++) {
    if (dist[i] == 1e9) {
      cout << "INF\n";
    }
    else {
      cout << dist[i] << "\n";
    }
  }
}