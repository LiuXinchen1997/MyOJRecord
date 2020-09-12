#include <cstdio>
#include <cstdlib>
#include <climits>

const int MAX = 10000005;
int pre[MAX],rank[MAX],maxx;


void init(){
	int i;
	for(i=1;i<MAX;++i){
		pre[i] = i;
		rank[i] = 1;
	}
}

int root(int x){
	if(x!=pre[x]){
		pre[x] = root(pre[x]);
	}
	return pre[x];
}

void merge(int x,int y){
	int fx = root(x);
	int fy = root(y);
	if(fx!=fy){
		pre[fx] = fy;
		rank[fy] += rank[fx];
		if(rank[fy]>maxx)maxx = rank[fy];
	}
}


int main(){
	//freopen("in.txt","r",stdin);
	int i,n,x,y;
	while(scanf("%d",&n)!=EOF){
		if(n==0){
			printf("1\n");
			continue;
		}
		init();
		maxx = INT_MIN;
		for(i=0;i<n;++i){
			scanf("%d %d",&x,&y);
			merge(x,y);
		}
		printf("%d\n",maxx);
	}
	return 0;
}
