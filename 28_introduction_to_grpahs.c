/**
 * @author: Mitul Tyagi
 * @description: Introduction to Graphs
 */
/*
- Graph theory is a branch of mathematics that studies the properties and
applications of graphs. A graph defines a collection of objects called vertices
(or nodes) connected by edges (or links). The primary goal of graph theory is to
understand the structure of these graphs and explore various problems related to
connectivity, pathfinding, and network optimization. By analyzing these
  relationships, graph theory enables to gain insights into numerous real-world
problems across various fields.
- Graphs are used to model relationships between objects in various domains,
such as social networks, computer networks, transportation systems, and more.
They provide a powerful framework for analyzing and solving problems related to
connectivity, paths, cycles, and optimization.
- In computer science, graph theory underpins many algorithms and data
structures used to represent networks such as the internet, social networks, and
communication systems. It also provides tools for solving problems related to
network connectivity, pathfinding, and optimization, and is foundational for
understanding various mathematical structures and concepts such as trees,
  cycles, and planar graphs.
- The fundamental elements of graph theory are vertices (also known as nodes)
and edges (also known as links). A vertex represents an individual entity or
point within a graph, while an edge denotes a connection or relationship between
two vertices. Together, these components form the structure of a graph, which
can be directed or undirected, weighted or unweighted, depending on the specific
nature of the relationships being modeled.
- Graph Data Structure is a non-linear data structure consisting of vertices and
edges. It is useful in fields such as social network analysis, recommendation
systems, and computer networks. In the field of sports data science, graph data
structure can be used to analyze and understand the dynamics of team performance
and player interactions on the field.
- A graph is formally defined as an ordered pair G = (V, E), where:
    --> V is a set of vertices (or nodes), representing the individual entities
in the graph.
    --> E is a set of edges (or links), representing the connections between
pairs of vertices.
- Vertices (V): These are the fundamental units or points in a graph. Each
vertex represents an entity or a location in the structure being modeled.
- Edges (E): These are the connections or relationships between pairs of
vertices. Each edge links two vertices, indicating a relationship or path
between them.
- Directed Edges: In a directed graph (or digraph), edges have a direction,
meaning they go from one vertex to another specific vertex. This direction is
often represented with an arrow. Directed edges are useful for modeling
asymmetric relationships, such as traffic flow or precedence constraints in
scheduling.
- Undirected Edges: In an undirected graph, edges do not have a direction and
simply connect two vertices. This type of graph is used to represent symmetric
relationships, such as mutual friendships or connections in a network where
direction is not significant.
- Vertex (Node): This concept represents an individual entity or point within
the graph structure. For example, in a social network graph, each person can be
represented as a vertex.
- Degree of a Vertex: The degree of a vertex is the number of edges connected to
it. This provides insights into its connectivity and importance within a graph.
The best way to conceptualize it is to imagine a person, represented as a
vertex, in a social network. If there’s a high number of edges from the vertex,
we would say it has a “high-degree,” which also signifies a highly influential
person. If we were modeling a transportation network, a high-degree node would
signal that the node is a central hub in the network, connecting to the most
other locations directly.
- Path: A path in a graph is a sequence of vertices where each adjacent pair is
connected by an edge. They can be simple (no repeated vertices) or general
(allowing repeats). For instance, In a graph with vertices A, B, C, and D, a
path could be A → B → C → D, where each vertex is connected to the next by an
edge.
- Cycle: A cycle is a path that starts and ends at the same vertex, with no
other repetitions of vertices or edges. Cycles can be simple (no repeated edges
or vertices except for the start and end) or general. Here’s an example: In a
graph with vertices A, B, C, and D, a simple cycle could be A → B → C → D → A.
- Connected Graphs: A graph is connected if there is a path between every pair
of vertices. In other words, every vertex in a connected graph can reach every
other vertex through some sequence of edges. A good example would be a social
network graph where everyone is reachable from anyone else.
- Graphs can be classified based on various properties, such as the direction of
edges, the presence of cycles, and the nature of connections between vertices.
Some common types of graphs include:
    - Directed Graphs (Digraphs): Graphs where edges have a direction,
indicating a one-way relationship between vertices.
    - Undirected Graphs: Graphs where edges do not have a direction,
representing symmetric relationships between vertices.
    - Weighted Graphs: Graphs where edges have weights or values associated with
them, representing the cost or distance between vertices.
    - Unweighted Graphs: Graphs where edges do not have weights, representing
binary relationships between vertices.
    - Cyclic Graphs: Graphs that contain cycles, or closed paths that start and
end at the same vertex.
    - Acyclic Graphs: Graphs that do not contain cycles, meaning there are no
closed paths in the graph.
    - Connected Graphs: Graphs where there is a path between every pair of
vertices, ensuring that all vertices are reachable from each other.
    - Disconnected Graphs: Graphs where there are isolated components or
subgraphs that are not connected to the rest of the graph.
    - Complete Graphs: Graphs where every pair of distinct vertices is connected
by an edge, forming a fully connected structure.
    - Sparse Graphs: Graphs with relatively few edges compared to the total
number of possible edges, resulting in a low edge density.
    - Dense Graphs: Graphs with a high number of edges compared to the total
number of possible edges, resulting in a high edge density.
- Directed Acyclic Graphs (DAGs): Directed graphs that do not contain any
cycles, meaning there are no closed paths that start and end at the same vertex.
DAGs are commonly used in various applications such as scheduling, task
dependencies, and data processing pipelines.
- Trees are a special type of undirected graph with no cycles. Equivalently, it
is a connected graph with N nodes and N-1 edgegs. Trees are widely used in
computer science for representing hierarchical structures, such as file systems,
organization charts, and decision trees. They provide an efficient way to
organize and search data, and are foundational for many algorithms and data
structures.
- Rooted Trees: Trees where one vertex is designated as the root, and all other
vertices are connected to it through directed edges. Every edge either points
away from or towards the root node. When edges point away from the root the
graph is called an arborescence (out-tree) and anti-arborescence (in-tree)
otherwiese. Rooted trees are commonly used in computer science for representing
  hierarchical structures, such as file systems, organization charts, and
decision trees.
- All out-trees are DAGs but not all DAGs are out-trees.
- Representation of Graph Data Structure:
    - Adjacency Matrix: A two-dimensional array where the rows and columns
represent vertices, and the values indicate the presence or absence of edges
between vertices. This representation is useful for dense graphs with many
edges, as it provides constant-time access to edge information. Edge weight
lookup is also efficient in adjacency matrices.
    - Adjacency List: A collection of linked lists or arrays where each vertex
has a list of adjacent vertices. This representation is more memory-efficient
for sparse graphs with fewer edges, as it only stores information about
connected vertices. Edge weight lookup is less efficient in adjacency lists
compared to adjacency matrices.
    - Edge List: A list of tuples or pairs representing the edges in the graph.
Each tuple contains the source and destination vertices of an edge, along with
any associated edge weights. This representation is simple and flexible, making
it suitable for various graph algorithms and operations. This representation is
more memory-efficient for sparse graphs with fewer edges. Edge weight lookup is
less efficient. Edge list representation is useful for algorithms that require
iterating over all edges in the graph.
- Basic operations on graphs include adding and removing vertices and edges,
checking for the presence of edges between vertices, and traversing the graph to
explore paths, cycles, and connectivity. Graph algorithms are used to solve
various problems related to graph theory, such as finding the shortest path
between two vertices, detecting cycles in a graph, and determining the
connectivity of a graph.
- Tree is a restricted type of Graph Data Structure, just with some more rules.
Every tree will always be a graph but not all graphs will be trees. Linked List,
Trees, and Heaps all are special cases of graphs.
- DFS and BFS are fundamental graph traversal algorithms that explore the
vertices and edges of a graph to discover paths, cycles, and connected
components. DFS is used to explore as far as possible along each branch before
backtracking, while BFS explores the vertices level by level. Both algorithms
are essential for solving various graph problems and are foundational for many
  graph algorithms and data structures.
- The Depth First Search (DFS) is the most fundamental algorithm used to explore
and traverse nodes and edges of a graph. It starts at a given vertex and
explores as far as possible along each branch before backtracking. DFS is used
to find paths, cycles, and connected components in a graph, and is a key
building block for many graph algorithms. It runs with a time complexity of O(V
+ E), where V is the number of vertices and E is the number of edges in the
graph. DFS can be implemented using recursion or an explicit stack data
structure.
- The Breadth First Search (BFS) algorithm is another fundamental graph
traversal algorithm that explores the vertices of a graph level by level. It
starts at a given vertex and explores all neighboring vertices before moving to
the next level. BFS is used to find the shortest path between two vertices,
determine the connected components of a graph, and solve various graph
  optimization problems. It runs with a time complexity of O(V + E), where V is
the number of vertices and E is the number of edges in the graph. BFS can be
implemented using a queue data structure.
- The BFS algorithm uses a queue data structure to maintain the order of
vertices to be visited. It starts by enqueuing the initial vertex and marking it
as visited. Then, it dequeues the vertex and explores its neighbors, enqueuing
them if they have not been visited. This process continues until all vertices
have been visited or the desired condition is met. BFS is particularly useful
  for finding the shortest path between two vertices in an unweighted graph, as
it guarantees that the first path found is the shortest.
- Topological Sorting is a fundamental graph algorithm that orders the vertices
of a directed acyclic graph (DAG) in a linear ordering such that for every
directed edge uv from vertex u to vertex v, u comes before v in the ordering.
Topological sorting is used in various applications such as task scheduling,
dependency resolution, and data processing pipelines. It runs with a time
  complexity of O(V + E), where V is the number of vertices and E is the number
of edges in the graph. Topological sorting can be implemented using DFS or BFS.
- DFS Implementation 1:

  marked = [False] *G.size()
  def dfs_pre(G, v):
      visit(v)
      marked[v] = True
      for w in G.neighbors(v):
          if not marked[w]:
              dfs(G, w)

  def dfs_post(G, v):
      marked[v] = True
      for w in G.neighbors(v):
          if not marked[w]:
              dfs(G, w)
      visit(v)

- DFS Implementation 2:

  marked = [False] *G.size()
  def dfs(G, v):
    stack.push(v)
    while len(stack) > 0:
        v = stack.pop()
        if not marked[v]:
            visit(v)
            marked[v] = True
            for w in G.neighbors(v):
                if not marked[w]:
                    stack.push(w)

- BFS Implementation:

  marked = [False] *G.size()
  def bfs(G, v):
    queue.enqueue(v)
    while len(queue) > 0:
        v = queue.dequeue()
        if not marked[v]:
            visit(v)
            marked[v] = True
            for w in G.neighbors(v):
                if not marked[w]:
                    queue.enqueue(w)
*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>

// Adjacency matrix representation of the graph

#define V 4

void addEdge(int mat[V][V], int i, int j)
{
    mat[i][j] = 1;
    mat[j][i] = 1; // Since the graph is undirected
}

void displayMatrix(int mat[V][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

// Structure for a node in the adjacency list
struct Node
{
    int data;
    struct Node *next;
};

// Adjacency list representation of the graph

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge between two vertices
void addEdge(struct Node *adj[], int i, int j)
{
    struct Node *newNode = createNode(j);
    newNode->next = adj[i];
    adj[i] = newNode;

    newNode = createNode(i); // For undirected graph
    newNode->next = adj[j];
    adj[j] = newNode;
}

// Function to display the adjacency list
void displayAdjList(struct Node *adj[], int Vertex)
{
    for (int i = 0; i < Vertex; i++)
    {
        printf("%d: ", i); // Print the vertex
        struct Node *temp = adj[i];
        while (temp != NULL)
        {
            printf("%d ", temp->data); // Print its adjacent
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    // Adjacency matrix representation of the graph
    // Create a graph with 4 vertices and no edges. Note that all values are
    // initialized as 0
    int mat[V][V] = {0};

    // Now add edges one by one
    addEdge(mat, 0, 1);
    addEdge(mat, 0, 2);
    addEdge(mat, 1, 2);
    addEdge(mat, 2, 3);

    /* Alternatively, we can also create using the below
       code if we know all edges in advance

    int mat[V][V] = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}
    }; */

    printf("Adjacency Matrix Representation\n");
    displayMatrix(mat);

    //-------------------------------------------------------------------------------
    // Adjacency list representation of the graph
    // Create a graph with 4 vertices and no edges
    int Ver = 4;
    struct Node *adj[Ver];
    for (int i = 0; i < Ver; i++)
    {
        adj[i] = NULL; // Initialize adjacency list
    }

    // Now add edges one by one
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    printf("Adjacency List Representation:\n");
    displayAdjList(adj, Ver);
    return 0;
}
