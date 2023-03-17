/*
----------------
Vertex-Edge list 
----------------

Vertex List - contains all the vertexs of the grpah
Edge List - contains the [start_vertex, end_vertex] for all edges in a graph
    - In an undirected graph, the start and end vertexes are interchangeable
    - In an weighted graph, the Edge List would contain [start_vertex, end_vertex, weight]

Vertex List would consume |V| memory 
Edge List could contain [start_vertex_idx, end_vertex_idx, weight_value] to save up memory

struct Edge {
    int startVertexidx;
    int endVertexidx;
    int weight;
}

But in time cost analysis, vertex-edge list is not very efficient.
Most of the operations take up to O(|E|) TC which translates to nearly O(|V|*|V|) TC.

----------------
Adjacency Matrix
----------------

We can store the edges in a |V| x |V| matrix.
A_ij = 1 if there exists an edge from i to j.

Finding Adjacent Nodes: just go to the row with that matrix and find all the elements with 1
    - TC: O(|V|)
Finding if two nodes are connected: we would have to find the indices for the vertex in the Vertex List
    - TC: O(|V|)

For a weighted graph, we can fill in the matrix with the weight values instead of the default 1

However, our matrix takes up a lot of space.
If our graph is sparse (few edges but with lots of vertices), 
our matrix in this representation would waste a lot of memory.

--------------
Adjacency List
--------------

*/