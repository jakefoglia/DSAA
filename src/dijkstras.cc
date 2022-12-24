#include <stdint.h>
#include <stack>
#include <iostream>
#include <cstring>

struct result
{
  int* distances;
  int* froms;


  result(int num_vertices)
  {
    distances = new int[num_vertices];
    froms = new int[num_vertices]; 

    for(int i = 0; i < num_vertices; i++)
    {
      distances[i] = INT32_MAX;
      froms[i] = -1;
    }
  }

}; 

// helper method
int next_unvisted(int** graph, int num_vertices, bool* visited, result* res)
{
  int next = -1;
  int smallest_known_distance = INT32_MAX;

  for(int i = 0; i < num_vertices; i++)
  {
    if(!visited[i] && res->distances[i] < smallest_known_distance)
    {
      next = i;
      smallest_known_distance = res->distances[i];
    }
  }

  return next;
}

result* dijkstra(int** graph, int num_vertices, int source)
{
  result* res = new result(num_vertices);
  bool* visited = new bool[num_vertices] { false };

  res->distances[source] = 0;
  
  int u = -1;
  while((u = next_unvisted(graph, num_vertices, visited, res)) != -1)
  {
    //std::cout << "\nvisiting " << u << std::endl;
    visited[u] = true;

    for(int v = 0; v < num_vertices; v++)
    {
      //std::cout << "checking " << v << std::endl;

      if(!visited[v] && res->distances[u] != INT32_MAX && graph[u][v] != INT32_MAX && (res->distances[v] > (res->distances[u] + graph[u][v])))
      {
        /*std::cout << "found shorter path to " << v << " via " << u << " : " << 
        res->distances[u] <<  " + " << graph[u][v] << " = " << res->distances[u] + graph[u][v] <<
         " < " << res->distances[v] << std::endl;*/
        
        res->distances[v] = res->distances[u] + graph[u][v];
        res->froms[v] = u;
      }
    }

  }
  return res;
}

inline char i2c(int i)
{
  char c = 'A' + i; 
  return c;
}

void print_shortest_path(result* res, int num_vertices, int source, int dest)
{
  std::cout << "Shortest Path From " << i2c(source) << " to " << i2c(dest) << std::endl;
  std::stack<int>* s = new std::stack<int>();
  int current = dest;

  while(current != source)
  {
    s->push(current);
    current = res->froms[current];
  }

  s->push(source);

  while(!s->empty())
  {
    std::cout << i2c(s->top()) << ' ';
    s->pop();
  }
  std::cout << '\n' << std::endl; 

}

void print_result(result* res, int num_vertices, int source)
{
  for(int dest = 0; dest < num_vertices; dest++)
  {
    print_shortest_path(res, num_vertices, source, dest);
  }
}

void print_graph(int** graph, int num_vertices)
{
  for(int r = 0; r < num_vertices; r++)
  {
    for(int c = 0; c < num_vertices; c++)
    {
      std::cout << graph[r][c] << " ";
    }
    std::cout << std::endl;

  }
}

int main()
{
  int** graph = new int*[4];
  for(int r = 0; r < 4; r++)
  {
    graph[r] = new int[4] { INT32_MAX, INT32_MAX, INT32_MAX, INT32_MAX };
  }
  
  // AB = 3
  graph[0][1] = 3; 
  graph[1][0] = 3; 
  
  // AC = 1
  graph[0][2] = 1;
  graph[2][0] = 1;

  // BC = 1
  graph[1][2] = 1;
  graph[2][1] = 1;

  // BD = 1
  graph[1][3] = 1;
  graph[3][1] = 1;

  //print_graph(graph,4);

  result* res = dijkstra(graph, 4, 0);
  print_result(res, 4, 0);
  
  return 1;
}