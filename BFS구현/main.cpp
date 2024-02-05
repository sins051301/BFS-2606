#include <iostream>
#include <queue>
#include<vector>
#include <algorithm>
using namespace std;

//연결리스트로 구현한 bfs
vector<int> list[1000];    //vector를 배열로 만들어 주면 무방향 그래프를 구현할 수 있다.
bool visit[1000];  //방문한 노드 표시용 배열
int cnt = 0;  //전파된 컴퓨터를 세주기 위한 cnt


void bfs(int start) {
	queue<int> q;   // 큐에 넣고 visit을 true로 만들고 시작한다.
	q.push(start);
	visit[start] = true;
	
	while (!q.empty()) {  //큐가 빌때까지 반복해 준다.
		int x = q.front();
		q.pop();

		for (int i = 0; i < list[x].size(); i++) {
			int y = list[x][i];
			if (!visit[y]) {
				visit[y] = true;  //방문했다면 true로 만들어 준다.
				q.push(y);   //그리고 큐에 넣어준다.
			}
		
		}
		
	}

	for (int i = 0; i < sizeof(visit) / sizeof(visit[0]); i++) {   //방문한 곳의 개수를 세어준다.
		if (visit[i]) {
			cnt++;
		}
	}
	cout << cnt-1;   //1번 컴퓨터를 제외하고 전파된 컴퓨터의 개수

}


int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(nullptr); 
	cout.tie(nullptr);

	int num, info, i, u, v;
	cin >> num;
	cin >> info;

	for (i = 0; i < info; i++) {
		cin >> u >> v;
		list[u].push_back(v);
		list[v].push_back(u);
	}

	bfs(1);  //1번 컴퓨터부터 시작


	
  
}

