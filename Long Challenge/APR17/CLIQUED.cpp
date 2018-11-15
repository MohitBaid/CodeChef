#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*GRAPH implementation and dikstra from http://www.geeksforgeeks.org/greedy-algorithms-set-7-dijkstras-algorithm-for-adjacency-list-representation/*/
struct AdjListNode
{
    long long dest;
    long long weight;
    struct AdjListNode* next;
};
struct AdjList
{
    struct AdjListNode *head; 
};
struct Graph
{
    long long V;
    struct AdjList* array;
};
struct AdjListNode* newAdjListNode(long long dest, long long weight)
{
    struct AdjListNode* newNode =
            (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}
struct Graph* createGraph(long long V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
	for (long long i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}
void addEdge(struct Graph* graph, long long src, long long dest, long long weight)
{
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
 
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
struct MinHeapNode
{
    long long   v;
    long long  dist;
};
struct MinHeap
{
    long long  size;      // Number of heap nodes present currently
    long long  capacity;  // Capacity of min heap
    long long  *pos;     // This is needed for decreaseKey()
    struct MinHeapNode **array;
};
struct MinHeapNode* newMinHeapNode(long long v, long long dist)
{
    struct MinHeapNode* minHeapNode =
           (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    minHeapNode->v = v;
    minHeapNode->dist = dist;
    return minHeapNode;
}
struct MinHeap* createMinHeap(long long capacity)
{
    struct MinHeap* minHeap =
         (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->pos = (long long  *)malloc(capacity * sizeof(long long ));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array =
         (struct MinHeapNode**) malloc(capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}
void minHeapify(struct MinHeap* minHeap,  long long idx)
{
    long long smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;
 
    if (left < minHeap->size &&
        minHeap->array[left]->dist < minHeap->array[smallest]->dist )
      smallest = left;
 
    if (right < minHeap->size &&
        minHeap->array[right]->dist < minHeap->array[smallest]->dist )
      smallest = right;
 
    if (smallest != idx)
    {
        MinHeapNode *smallestNode = minHeap->array[smallest];
        MinHeapNode *idxNode = minHeap->array[idx];
        minHeap->pos[smallestNode->v] = idx;
        minHeap->pos[idxNode->v] = smallest;
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}
long long  isEmpty(struct MinHeap* minHeap)
{
    return minHeap->size == 0;
}
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
    if (isEmpty(minHeap))
        return NULL;
    struct MinHeapNode* root = minHeap->array[0];
    struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = lastNode;
    minHeap->pos[root->v] = minHeap->size-1;
    minHeap->pos[lastNode->v] = 0;
    --minHeap->size;
    minHeapify(minHeap, 0);
    return root;
}
void decreaseKey(struct MinHeap* minHeap, long long int v, long long int dist)
{
    long long int i = minHeap->pos[v];
    minHeap->array[i]->dist = dist;
    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist)
    {
        minHeap->pos[minHeap->array[i]->v] = (i-1)/2;
        minHeap->pos[minHeap->array[(i-1)/2]->v] = i;
        swapMinHeapNode(&minHeap->array[i],  &minHeap->array[(i - 1) / 2]);
		i = (i - 1) / 2;
    }
}
bool isInMinHeap(struct MinHeap *minHeap, long long v)
{
   if (minHeap->pos[v] < minHeap->size)
     return true;
   return false;
}
void printArr(long long dist[], int n)
{
    for (long long int i = 0; i < n; ++i)
        printf("%lld ",dist[i]);
     printf("\n");   
}
void dijkstra(struct Graph* graph, long long int src,long long int k,long long int x,int flag)
{
    long long int V = graph->V;// Get the number of vertices in graph
    long long int dist[V];      // dist values used to pick minimum weight edge in cut
 
    struct MinHeap* minHeap = createMinHeap(V);
    
    for (long long int v = 0; v < V ; ++v)
    {
        dist[v] = LONG_LONG_MAX;
        minHeap->array[v] = newMinHeapNode(v, dist[v]);
        minHeap->pos[v] = v;
    }
    minHeap->array[src] = newMinHeapNode(src, dist[src]);
    minHeap->pos[src]   = src;
    dist[src] = 0;
    decreaseKey(minHeap, src, dist[src]);
    
    minHeap->size = V;
    while (!isEmpty(minHeap))
    {
        struct MinHeapNode* minHeapNode = extractMin(minHeap);
        long long int u = minHeapNode->v; // Store the extracted vertex number
 
        struct AdjListNode* pCrawl = graph->array[u].head;
        if(u<k && flag==0)
        {
        	for(long long int v=0;v<k;v++)
        	{
        		if (isInMinHeap(minHeap, v) && dist[u] != LONG_LONG_MAX && x + dist[u] < dist[v])
            	{
                	dist[v] = dist[u] + x;
                	decreaseKey(minHeap, v, dist[v]);
            	}	
        	}
        	flag=1;
        }
	    while (pCrawl != NULL)
        {
            long long int v = pCrawl->dest;
            if (isInMinHeap(minHeap, v) && dist[u] != LONG_LONG_MAX && pCrawl->weight + dist[u] < dist[v])
            {
                dist[v] = dist[u] + pCrawl->weight;
                decreaseKey(minHeap, v, dist[v]);
            }
            pCrawl = pCrawl->next;
        }
    }
    printArr(dist, V);
}
int main()
{
    int T;	scanf("%d",&T);
    while(T--)
    {
    	long long int n,k,x,m,s;	scanf("%lld %lld %lld %lld %lld",&n,&k,&x,&m,&s);
  	 	struct Graph* graph = createGraph(n);
 		for(long long int i=0;i<m;i++)
 		{
 			 long long int a,b,c;
			 scanf("%lld %lld %lld",&a,&b,&c);
			 addEdge(graph, a-1, b-1, c);
    	     
 		}
       dijkstra(graph, s-1,k,x,0);
 	}
    return 0;
}
