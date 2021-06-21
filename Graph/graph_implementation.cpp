#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>

using namespace std;

template<typename T>

class Graph {
public:
	unordered_map<T, list<T>> graph;

	void addEdge(T x, T y, bool bidirectional = true) {
		graph[x].push_back(y);
		if (bidirectional)    graph[y].push_back(x);
	}

	void printGraph() {
		for (auto parent : graph) {
			cout << parent.first << " -> ";
			for (auto children : parent.second)    cout << children << " ";
			cout << endl;
		}
		return ;
	}

	void dfs(T src) {

		unordered_map<T, bool> visited;

		for (auto node : graph)    visited[node.first] = false;

		dfs_helper(src, visited);
		cout << endl;
	}

	void dfs_helper(T src, unordered_map<T, bool> &visited) {
		cout << src << " ";
		visited[src] = true;

		for (auto nbr : graph[src]) {
			if (visited[nbr])    continue;
			dfs_helper(nbr, visited);
		}
		return ;
	}

	void bfs(T src) {
		unordered_map<T, bool> visited;
		for (auto node : graph)    visited[node.first] = false;

		queue<T> bfs_queue;
		bfs_queue.push(src);
		visited[src] = true;

		while (!bfs_queue.empty()) {
			T parent = bfs_queue.front();
			bfs_queue.pop();

			cout << parent << " ";

			for (auto child : graph[parent]) {
				if (visited[child])    continue;
				visited[child] = true;
				bfs_queue.push(child);
			}
		}
		cout << endl;
		return ;
	}
};

int main() {
	Graph<char> g;
	g.addEdge('A', 'B');
	g.addEdge('A', 'C');
	g.addEdge('A', 'D', false);
	g.addEdge('D', 'C');
	g.addEdge('B', 'D');

	g.printGraph();
	g.dfs('A');

	g.bfs('A');

	return 0;
}