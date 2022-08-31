#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[101];
void addEdge(int x, int y){
	graph[x].push_back(y);
	graph[y].push_back(x);
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int x, y;
		cin >> x >> y;
		addEdge(x, y);
	}
	vector<pair<int, pair<int, int> > > th;
	vector<pair<int, int> > tw;
	vector<int> on;
	const int inf = 1e9;
	vector<int> d(n + 1, inf);
	bool bad = 0;
	for(int i = 1; i <= n; ++i){
		if(d[i] == inf){
			vector<int> vertices;
			d[i] = 0;
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				int v = q.front();
				vertices.push_back(v);
				q.pop();
				for(int j=0;j<graph[v].size();j++){
                    int to=graph[v][j];
					if(d[to] == inf){
						d[to] = d[v] + 1;
						q.push(to);
					}
				}
			}
			if(vertices.size() > 3) bad = 1;
			else if(vertices.size() == 3){
				th.push_back({vertices[0], {vertices[1], vertices[2]}});
			}else if(vertices.size() == 2){
				tw.push_back({vertices[0], vertices[1]});
			}else{
				on.push_back(vertices[0]);
			}
		}
	}
	if(tw.size() > on.size() || bad){
        cout << -1 << endl;	
    }else{
		for(int it=0;it<th.size();it++)
			cout << th[it].first << ' ' << th[it].second.first << ' ' << th[it].second.second << endl;
		while(tw.size()){
			cout << tw[tw.size() - 1].first << ' ' << tw[tw.size() - 1].second << ' ' << on[on.size() - 1] << endl;
			tw.pop_back();
			on.pop_back();
		}
		for(int i = 0; i < on.size(); i += 3){
			cout << on[i] << ' ' << on[i + 1] << ' ' << on[i + 2] << endl;
		}
	}
	return 0;
}