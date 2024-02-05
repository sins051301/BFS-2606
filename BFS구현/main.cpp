#include <iostream>
#include <queue>
#include<vector>
#include <algorithm>
using namespace std;

//���Ḯ��Ʈ�� ������ bfs
vector<int> list[1000];    //vector�� �迭�� ����� �ָ� ������ �׷����� ������ �� �ִ�.
bool visit[1000];  //�湮�� ��� ǥ�ÿ� �迭
int cnt = 0;  //���ĵ� ��ǻ�͸� ���ֱ� ���� cnt


void bfs(int start) {
	queue<int> q;   // ť�� �ְ� visit�� true�� ����� �����Ѵ�.
	q.push(start);
	visit[start] = true;
	
	while (!q.empty()) {  //ť�� �������� �ݺ��� �ش�.
		int x = q.front();
		q.pop();

		for (int i = 0; i < list[x].size(); i++) {
			int y = list[x][i];
			if (!visit[y]) {
				visit[y] = true;  //�湮�ߴٸ� true�� ����� �ش�.
				q.push(y);   //�׸��� ť�� �־��ش�.
			}
		
		}
		
	}

	for (int i = 0; i < sizeof(visit) / sizeof(visit[0]); i++) {   //�湮�� ���� ������ �����ش�.
		if (visit[i]) {
			cnt++;
		}
	}
	cout << cnt-1;   //1�� ��ǻ�͸� �����ϰ� ���ĵ� ��ǻ���� ����

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

	bfs(1);  //1�� ��ǻ�ͺ��� ����


	
  
}

