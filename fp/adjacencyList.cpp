#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

bool foundDFSNode = false;

class Graph
{
  int numVertices;
  list<pair<int, int>> *adjLists;
  map<int, bool> visitedDfsNode;
  bool *visited;

  public:
    Graph(int vertices);
    void addEdge(int src, int dest, int weight);
    void BFS(int startVertex, int endVertex);
    void shortestPath(int src, int dest);
    void DFS(int v, int end);
    void showList();
};

Graph::Graph(int vertices)
{
  numVertices = vertices;
  adjLists = new list<pair<int, int>>[vertices];
}

void Graph::addEdge(int src, int dest, int weight)
{
  adjLists[src].push_back(make_pair(dest, weight));
}

void Graph::BFS(int startVertex, int endVertex)
{
  visited = new bool[numVertices];
  for (int i = 1; i <= numVertices; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);

  list<pair<int, int>>::iterator i;

  while (!queue.empty())
  {
    int currVertex = queue.front();

    if (currVertex == endVertex)
    {
      break;
    }

    cout << "(V" << currVertex << ")";
    queue.pop_front();

    for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i)
    {
      int adjVertex = (*i).first;
      if (!visited[adjVertex])
      {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
  cout << endl;
}

void Graph::shortestPath(int src, int dest)
{
    set< pair<int, int> > setds;
 
    vector<int> dist(numVertices, INF);
 
    setds.insert(make_pair(1, src));
    dist[src] = 0;

    while (!setds.empty())
    {
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());
 
        int u = tmp.second;
 
        list<pair<int, int>>::iterator i;
        for (i = adjLists[u].begin(); i != adjLists[u].end(); ++i)
        {   
            int v = (*i).first;
            int weight = (*i).second;

            if (dist[v] > dist[u] + weight)
            {
                if (dist[v] != INF)
                {
                  setds.erase(setds.find(make_pair(dist[v], v)));
                }
 
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 1; i <= numVertices; ++i)
    {
      if (i == dest)
      {
        break;
      }
      
      printf("%d \t\t %d\n", i, dist[i]);
    }
}

void Graph::DFS(int v, int end)
{
    if (foundDFSNode == false)
    {

      visitedDfsNode[v] = true;
      cout << v << " ";

      list<pair<int, int>>::iterator i;

      for (i = adjLists[v].begin(); i != adjLists[v].end(); ++i)
      {

        if (v == end)
        {
          foundDFSNode = true;
        }
        if (!visitedDfsNode[(*i).first])
        {
          DFS((*i).first, end);
        }
      }
    }

}

void Graph::showList()
{
  for (int i = 1; i <= numVertices; i++)
  {
    cout << i << "-> ";
    list<pair<int, int>>::iterator it;
      for(it = adjLists[i].begin(); it != adjLists[i].end(); ++it){
        cout << (*it).first << "-> ";
      }
    cout << endl;
  }
}

int main()
{
    Graph graf(22);
    graf.addEdge(1, 2, 2);
    graf.addEdge(2, 3, 1);
    graf.addEdge(3, 4, 1);
    graf.addEdge(3, 5, 1);
    graf.addEdge(3, 6, 2);
    graf.addEdge(6, 7, 1);
    graf.addEdge(7, 8, 1);
    graf.addEdge(7, 9, 1);
    graf.addEdge(8, 10, 1);
    graf.addEdge(9, 11, 1);
    graf.addEdge(9, 12, 1);
    graf.addEdge(12, 13, 1);
    graf.addEdge(12, 14, 3);
    graf.addEdge(14, 15, 1);
    graf.addEdge(14, 16, 2);
    graf.addEdge(15, 17, 1);
    graf.addEdge(16, 18, 1);
    graf.addEdge(17, 3, 1);
    graf.addEdge(18, 19, 1);
    graf.addEdge(18, 20, 1);
    graf.addEdge(19, 21, 1);
    graf.addEdge(19, 1, 2);
    graf.addEdge(21, 2, 1);

    int start, end;
    cin >> start >> end;

    cout << endl << "BFS :" << endl;
    graf.BFS(start, end);
    cout << endl << "DFS :" << endl;
    graf.DFS(start, end);
    cout << endl << endl << "Dijkstra :" << endl;
    graf.shortestPath(start, end);
    cout << endl << "List :" << endl;
    graf.showList();

  return 0;
}
