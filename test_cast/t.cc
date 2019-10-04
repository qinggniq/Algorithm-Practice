//poj_2446
/*==================================================*\
| 二分图匹配（匈牙利算法DFS 实现）
| INIT: g[][]邻接矩阵;
| 优点：实现简洁容易理解，适用于稠密图，DFS找增广路快。
| 找一条增广路的复杂度为O（E），最多找V条增广路，故时间复杂度为O（VE）
==================================================*/
#include<stdio.h>
#include<memory.h>
 
#define MAX 1089 //33*33
bool g[MAX][MAX]; //邻接矩阵，true代表有边相连
bool flag,visit[MAX];    //记录V2中的某个点是否被搜索过
int match[MAX];   //记录与V2中的点匹配的点的编号
int cnt;   //二分图中左边、右边集合中顶点的数目
bool hole[MAX][MAX];
int id[MAX][MAX];
 
// 匈牙利算法
bool dfs(int u)
{
	for (int i = 1; i <= cnt; ++i)
	{
		if (g[u][i] && !visit[i])   //如果节点i与u相邻并且未被查找过
		{
			visit[i] = true;   //标记i为已查找过
			if (match[i] == -1 || dfs(match[i]))   //如果i未在前一个匹配M中，或者i在匹配M中，但是从与i相邻的节点出发可以有增广路径
			{
				match[i] = u;  //记录查找成功记录，更新匹配M（即“取反”）
				return true;   //返回查找成功
			}
		}
	}
	return false;
}
int MaxMatch()
{
	int i,sum=0;
	memset(match,-1,sizeof(match));
	for(i = 1 ; i <= cnt ; ++i)
	{
		memset(visit,false,sizeof(visit));   //清空上次搜索时的标记
		if( dfs(i) )    //从节点i尝试扩展
		{
			sum++;
		}
	}
	return sum;
}
 
int main(void)
{
    int i,j,k,m,n,ans,y,x;
    printf("?????\n");
     scanf("%d %d %d",&m,&n,&k);
    
		  memset(g,false,sizeof(g));
		  memset(hole,false,sizeof(hole));
          for (i = 1; i <= k; ++i)
		  {
			  scanf("%d %d",&y,&x);
              hole[x][y] = true;
		  }
          cnt = 0;
 
          for (i = 1; i <= m; ++i)
          {
			  for (j = 1; j <= n; ++j)
			  {
				  if(hole[i][j] == false)   //对没有涂黑的点进行标号
				  {
					  id[i][j] = ++cnt;
				  }
			  }
          }
		  for (i = 1; i <= m; ++i)
          {
			  for (j = 1; j <= n; ++j)
			  {
				  if(hole[i][j] == false)
				  {
					  if(i-1>0 && hole[i-1][j] == false)   //建图。。要注意边界问题
						  g[ id[i][j] ][ id[i-1][j] ] = true;
					  if(i+1<=m && hole[i+1][j] == false)
						  g[ id[i][j] ][ id[i+1][j] ] = true;
					  if(j-1>0 && hole[i][j-1] == false)
						  g[ id[i][j] ][ id[i][j-1] ] = true;
					  if(j+1<=n && hole[i][j+1] == false)
						  g[ id[i][j] ][ id[i][j+1] ] = true;
				  }
			  }
		  }
 
		  ans = MaxMatch();
		  printf("%d", ans);
	
    
    return 0;
}