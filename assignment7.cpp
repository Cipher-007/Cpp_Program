#include<iostream>
#include<algorithm>
using namespace std;

class graph
{
    int G[20][20],n;
    public:
    void accept()
    {
        int i,j,e;
        int src,dest,cost;
        cout<<"Enter no of vertices: "; cin>>n;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            { 
                G[i][j]=0;
            }
        }
        cout<<"Enter no of Edges: "; cin>>e;
        for(i=0;i<e;i++)
        {
            cout<<"Enter Source: "; cin>>src;
            cout<<"Destination: "; cin>>dest;
            cout<<"Cost: "; cin>>cost;
            G[src][dest]=cost;
            G[dest][src]=cost;
        }
    }
    void display()
    {
        int i,j;
        for(i=0;i<n;i++)
        {
            cout<<"\n";
            
            for(j=0;j<n;j++)
            {
                cout<<"\t"<<G[i][j];
            }
        }
    }
    void prims()
    {
        int i,j,R[20][20];
        int src,dest,cost,count,min;
        int total=0;
        int visited[20];
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(G[i][j]==0)
                {
                    R[i][j]=999;
                }
                else
                {
                    R[i][j]=G[i][j];
                }
            }
        }
        for(i=0;i<n;i++)
        {
            visited[i]=0;
        }
        cout<<"\nEnter start vertex: "; cin>>src;
        visited[src]=1;
        count=0;
        while(count<n-1)
        {
            min=999;

            for(i=0;i<n;i++)
            {
                if(visited[i]==1) for(j=0;j<n;j++)
                {
                    if(visited[j]!=1)
                    {
                        if(min>R[i][j])
                        {
                            min=R[i][j]; src=i; dest=j;
                        }
                    }
                }
            }
            cout<<"\nEdge from "<<src<<" to "<<dest<<"\twith cost:	"<<min; total=total+min;
            visited[dest]=1;
            count++;
        }
        cout<<"\nTotal Cost: "<<total<<"\n";
    }

};
class Edge
{
    public:
    int source; int dest; int weight;
};
bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}
int findParent(int v, int *parent)
{
    if (parent[v] == v) 
    {
        return v;
    }
    return findParent(parent[v], parent);
}
void printMST(Edge *input, int v, int e)
{
    Edge *output = new Edge[v - 1]; int *parent = new int[v];
    for (int i = 0; i < v; i++)
    { 
        parent[i] = i;
    }
    sort(input, input + e, compare);
    int count = 0;
    int i = 0;
    while (count != v - 1)
    {
        Edge currentEdge = input[i];
        int sourceParent = findParent(currentEdge.source, parent);        
        int destParent = findParent(currentEdge.dest, parent);
        if (sourceParent != destParent)
        {
            output[count] = currentEdge; count++;
            parent[sourceParent] = destParent;
        }
        i++;
    }
    cout << endl;
    for (int i = 0; i < v - 1; i++)
    {
        cout << output[i].source << " " << output[i].dest << " " << output[i].weight;
    }
}

int main() 
{
    graph g; g.accept();
    g.display();
    g.prims();
    int v,e;	// V = No. of vertex in range [0 to v-1] e = no. of edges 
    cout << "Enter no of vertex: ";
    cin >>v;
    cout << "Enter no of edges ";
    cin >>e;
    Edge *input = new Edge[e];
    cout << "Enter source vertex, then destination vertex, then their weights"<< endl;
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    printMST(input, v, e);
}
