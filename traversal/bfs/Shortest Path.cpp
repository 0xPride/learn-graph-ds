#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

/*
        n -> cities
        m -> roads
        k -> forbidden roads
*/

using namespace std;

void print(vector<vector<int> > &roads, vector<vector<int> > &forbidden) {
  cout << " ------ ROADS ------ " << endl;
  for (int i = 1; i < roads.size(); i++) {
    cout << i << " -> ";
    for (int j = 0; j < roads[i].size(); j++) {
      cout << roads[i][j] << " | ";
    }
    cout << endl;
  }
  cout << " ------ FORBIDDEN ------ " << endl;
  for (int i = 0; i < forbidden.size(); i++) {
    cout << forbidden[i][0] << " " << forbidden[i][1] << " " << forbidden[i][2]
         << " " << endl;
  }
}

void solve(vector<vector<int> > &roads, vector<vector<int> > &forbidden) {
	int nodes = roads.size(), source = 1;
	queue<int> q;
	vector<bool> visited(nodes);
	vector<int> d(nodes), parrent(nodes);

	for (bool v : visited)
	{
		v = false;
	}
	q.push(source);
	visited[source] = true;
	parrent[source] = -1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : roads[v]) {
			if (!visited[u]) {
				visited[u] = true;
				q.push(u);
				d[u] = d[v] + 1;
				parrent[u] = v;
			}
		}
	}
	if (!visited[4])
		cout << "No Path Was Found\n";
	else
		{
			vector<int> path;

			for (int v = 4; v != -1; v = parrent[v])
			{
				cout << "running" << endl;
				path.push_back(v);
			}
			reverse(path.begin(), path.end());
			cout << path.size() - 1 << endl;
			for (int v : path) {
				cout << v << " ";
			}
			cout << endl;
	}
}

int main(int argc, char *argv[]) {
  int n, m, k;

  cin >> n >> m >> k;

  vector<vector<int> > roads(n + 1);
  vector<vector<int> > forbidden;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    roads[a].push_back(b);
		roads[b].push_back(a);
  }
  for (int i = 0; i < k; i++) {
    int a, b, c;
		vector<int> tmp;
		cin >> a >> b >> c;
    tmp.push_back(a);
    tmp.push_back(b);
    tmp.push_back(c);
		forbidden.push_back(tmp);
  }
	solve(roads, forbidden);
  return 0;
}
