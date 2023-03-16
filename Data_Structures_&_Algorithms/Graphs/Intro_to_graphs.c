/*
So far, we have talked about linear data sturctures (arrays, linked_list)
and non-linear tree data structures (trees).
In mathematical terms, a graph G is an ordered pair of a set V of vertices
and a set E of edges. G = (V, E)
Order matters when paranthesis are used.
If order doesn't matter, then G = {V, E}

Directed Edge: Direction matters (from u to v) (u,v)
Undirected Edge: Direction doesn't matter (from u to v or v to u) {u,v}
 
Weighted Graph: Edges have values assigned to it (distance from one node to another)
Unweighted Graph: Edges all have equal weights

There are properties of graphs that we would have to know.

Properties of Graphs

Self Loop: An edge where there is only one vertex; edge comes out from one node and enters the same node
Multi Edge: Multiple edges between two same nodes. 
If there are no self loops or multiedges, it's a *simple graph*

How to calculate maximum number of edges in a simple graph with n vertices: 
    if directed, 0 <= |E| <= n(n-1)
    if undirected, 0 <= |E| <= (n(n-1))/2
If there are close to the maximum number of edges, it is called a Dense graph.
If there are a few edges, it is called a Sparse graph.

Path: sequence of vertices were each adjacent pair is connected by an edge.
Simple Path: path in which no vertices are repeated.
Closed Walk: starts and ends at same vertex.
Simple Cycle: no repetition other than start and end.

Strongly connected graph: If there is a path from any vertex to any other vertex.
Acylic Graph: a graph with no cycle.
Directed Acyclic Graph (DAG): directed graph with no cycles.
*/