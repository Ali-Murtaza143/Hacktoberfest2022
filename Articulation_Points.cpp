// articulation points in a given graph

//  A vertex in an undirected connected graph is an articulation point (or cut vertex) if removing it (and edges through it) disconnects the graph.

#include<bits/stdc++.h>
using namespace std;


void dft(vector<vector<int>> g,int vis[],int u,int num[],int low[],int p[],int ans[])
{
    static int lvl=1;
    vis[u]=1;
    num[u]=lvl,low[u]=lvl;
    lvl++;
    int dftc=0;
    for(int v=0;v<g.size();v++)
        {
        if(g[u][v]==1){
            if(vis[v]!=1)
            {
                dftc++;
                p[v]=u;
                dft(g,vis,v,num,low,p,ans);

                low[u]=min(low[u],low[v]);

            if (p[u]==-1 && dftc>1)
            {
                ans[u]=1;
            }
            if (p[u]!=-1 && low[v] >= num[u])
            {
                ans[u]=1;
            }

            }

        else if(v!=p[u]){
            low[u]=min(low[u],num[v]);
       }
    }
  }
}
int main()
{
    // given graph

    int n=9;
    int e=10;

    vector<vector<int>> g(n,vector<int>(n,0));
    int u[]={0,0,1,2,2,3,5,5,6,7};
	int v[]={1,2,2,3,5,4,8,6,7,8};

    for(int i=0;i<e;i++)
    {
        g[u[i]][v[i]]=1;
        g[v[i]][u[i]]=1;
    }

    int a[n];
    int num[n];
    int low[n];
    int p[n];
    int ans[n];

    for(int i=0;i<n;i++)
    {
        ans[i]=0;
        num[i]=0;
        a[i]=0;
        low[i]=0;
        p[i]=-1;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            dft(g,a,i,num,low,p,ans);
        }

    }

    // points

    for(int i=0;i<n;i++)
    {
        if(ans[i]==1){
            cout<<i<<" ";
        }
    }

}






