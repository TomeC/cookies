#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100
#define INFINITY 65535
#define true 1
#define false 0
typedef char VertexType;
typedef int EdgeType;
char visited[MAXVEX];

//邻接矩阵结构
struct MGraph
{
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
};
//创建图，邻接矩阵实现
void createMGraph (struct MGraph *G)
{
	int i, j, k, w;
	printf ("Enter numVertexes and numEdges:");
	scanf ("%d %d", &G->numVertexes, &G->numEdges);
	for (i = 0; i < G->numVertexes; ++i)
	{
		printf ("Enter data in %d: ", i);
		fflush (stdin);
		scanf ("%c", &G->vexs[i]);
	}
	for (i = 0; i < G->numVertexes; ++i)
	{
		for (j = 0; j < G->numVertexes; ++j)
		{
			G->arc[i][j] = INFINITY;
		}
	}
	for (k = 0; k < G->numEdges; ++k)
	{
		printf("Enter (Vi, Vj) --> i , j and weight w  :");
		scanf ("%d %d %d", &i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];
	}
}
//邻接表
//边表节点
struct EdgeNode
{
	int adjvex;
	EdgeType weight;
	struct EdgeNode *next;
};
//顶点节点
typedef struct VertexNode
{
	VertexType data;
	struct EdgeNode *firstEdge;
}VertexNode, AdjList[MAXVEX];
//邻接表结构存储的图
struct GraphAdjList
{
	AdjList adjList;
	int numVertexes, numEdges;
};
//创建邻接表结构存储的图
void CreateALGraph (struct GraphAdjList *G)
{
	int i, j, k;
	struct EdgeNode *e;
	printf("%s", "Enter numVertexes and numEdges: ");
	scanf ("%d %d", &G->numVertexes, &G->numEdges);
	for (i = 0; i < G->numVertexes; i++)
	{
		printf ("node %d data: ", i);
		fflush (stdin);
		scanf ("%c", &G->adjList[i].data);
		G->adjList[i].firstEdge = NULL;
	}
	for (k = 0; k < G->numEdges; k++)
	{
		e = (struct EdgeNode *)malloc (sizeof (struct EdgeNode));
		printf("(Vi, Vj) --> i , j and weight:");
		scanf ("%d %d %d", &i, &e->adjvex, &e->weight);
		e->next = G->adjList[i].firstEdge;
		G->adjList[i].firstEdge = e;

		e = (struct EdgeNode *)malloc (sizeof (struct EdgeNode));
		e->adjvex = i;
		e->next = G->adjList[i].firstEdge;
		G->adjList[i].firstEdge = e;
	}
}
//visit data
void visit (char data)
{
	printf("%c\t", data);
}
//深度优先遍历，邻接矩阵实现的图
void DFS_MGraph (struct MGraph G, int i)
{
	int j;
	visited[i] = true;
	visit (G.vexs[i]);
	for (j = 0; j < G.numVertexes; j++)
	{
		if (G.arc[i][j] != INFINITY && !visited[i])
			DFS_MGraph (G, j);
	}
}

void DFS_MGraphTraverse (struct MGraph G)
{
	int i;
	for (i = 0; i < G.numVertexes; i++)
	{
		visited[i] = false;
	}
	for (i = 0; i < G.numVertexes; i++)
	{
		if (!visited[i])
			DFS_MGraph (G, i);
	}
}
//深度优先遍历邻接表实现的图
void DFS_ALGraph(struct GraphAdjList *G, int i)
{
	struct EdgeNode *p;
	visited[i] = true;
	visit (G->adjList[i].data);
	p = G->adjList[i].firstEdge;
	while (p)
	{
		if (!visited[p->adjvex])
		{
			DFS_ALGraph (G, p->adjvex);
		}
		p = p->next;
	}
}
void DFS_ALGraphTraverse (struct GraphAdjList *G)
{
	int i, j;
	for (i = 0; i < G->numVertexes; ++i)
	{
		visited[i] = false;
	}
	for (i = 0; i < G->numVertexes; ++i)
	{
		if (!visited[i])
		{
			DFS_ALGraph (G, i);
		}
	}
}
//
void BFS_MGraphTraverse (MGraph *G)
{
	int i, j;
	Queue <char> q;
	for (i = 0; i < G->numVertexes; ++i)
	{
		visited[i] = false;
	}
	for (i = 0; i < G->numVertexes; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			
		}
	}
}

int main ()
{

	//struct MGraph MG;
	struct GraphAdjList AG;
	//createMGraph (&MG);
	CreateALGraph (&AG);
	//DFS_MGraphTraverse (MG);
	DFS_ALGraphTraverse (&AG);
	return 0;
}