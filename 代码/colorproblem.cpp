#include<bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;

int n, m, match;       //ͼ�Ķ����������õ���ɫ�������ߵ�����
int g[maxn][maxn];  //ͼ�����Ӿ���
int col[maxn];          //��ǰ�Ľ�
int sum = 0;            //������

bool check(int t) {//�ж��Ƿ�������Ϳɫ
	for (int i = 1; i <= n; ++i) { 
		if (g[t][i] == 1 && col[i] == col[t])
			return false;
	}
	return true;
}

void dfs(int t) {
	if (t > n) {
		sum++;
		for (int i = 1; i <= n; ++i)
			printf("%d ", col[i]);
		printf("\n");
	}
	else {
		for (int i = 1; i <= m; ++i) {
			col[t] = i;
			if (check(t))dfs(t + 1);
			col[t] = 0;
		}
	}
}
int main() {
	printf("������õ���ɫ����:\n");
	scanf("%d", &m);
	printf("����ͼ�Ķ��������ߵ�����:\n");
	scanf("%d %d",&n, &match);
	printf("�����:\n");
	for (int i = 1; i <= match; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x][y] = g[y][x] = 1;
	}
	printf("��ɫ�ķ���Ϊ��\n");
	dfs(1);
	if (sum == 0)printf("������\n");
	else printf("һ����%d����ɫ����\n", sum);
}