#include<bits/stdc++.h>
using namespace std;
int ne=1,min_cost=0;

int main()
{
    int n,i,j,a,b,u,v,min,cost[20][20],parent[20];
    cout<<"Enter Number of vertices :";
    cin>>n;
    cout<<"Enter the cost matrix \n";
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    cin>>cost[i][j];
    for(i=1;i<=n;i++)
    parent[i]=0;
    cout<<"The edges of spanning tree are \n";
    while(ne<n)
    {
        min=999;
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        if(cost[i][j]<min)
        {
            min=cost[i][j];
            a=u=i;
            b=v=j;
        }
        while(parent[u])
        u=parent[u];
        while(parent[v])
        v=parent[v];
        if(u!=v)
        {
            cout<<a<<"->"<<b<<" = "<<min<<endl;
            min_cost=min_cost+min;
            parent[v]=u;
            ne++;
        }
        cost[a][b]=cost[b][a]=999;
    }
    cout<<"Minimum cost = "<<min_cost;
    return 0;
}