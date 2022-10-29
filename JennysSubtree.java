import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Jenny_Subtrees {
     static class Node implements Comparable<Node> {
    private int id;
    private List<Node> neighbours = new ArrayList<>();

    public Node(int id) {
      this.id = id;
    }

    public void addNeighbour(Node n) {
      this.neighbours.add(n);
    }

    public int compareTo(Node other) {
      return this.neighbours.size() - other.neighbours.size();
    }

    public void print() {
      System.out.print(id + ": [");
      for (Node n : neighbours) {
        System.out.print(n.id + " ");
      }
      System.out.println("]");
      for (Node n : neighbours) {
        n.print();
      }
    }
  }

  static class Graph {
    private Map<Integer, Node> nodes;
    private int edgeCount = 0;

    public Graph() {
      this.nodes = new HashMap<>();
    }

    public void addNode(int x) {
      if (nodes.containsKey(x)) {
        return;
      }
      Node node = new Node(x);
      nodes.put(x, node);
    }

    public void addEdge(int x, int y) {
      Node nx = nodes.get(x);
      if (nx == null) {
        nx = new Node(x);
        nodes.put(x, nx);
      }

      Node ny = nodes.get(y);
      if (ny == null) {
        ny = new Node(y);
        nodes.put(y, ny);
      }

      nx.addNeighbour(ny);
      ny.addNeighbour(nx);
      edgeCount++;
    }

    public int countCuts(int radius) {
      int count = 0;

      Set<Graph> trees = new HashSet<Graph>();
      for (Integer id : nodes.keySet()) {
        Graph graph = new Graph();
        graph.addNode(id);
        Node node = graph.nodes.get(id);

        dfs(radius, graph, node, new HashSet<Integer>());
        if (!isIsomorphic(trees, graph)) {
          trees.add(graph);
          count++;
        }
      }

      return count;
    }

    private void dfs(int radius, Graph graph, Node currentNode, Set<Integer> visited) {
      if (radius == 0) {
        return;
      }

      visited.add(currentNode.id);
      Node graphNode = nodes.get(currentNode.id);
      for (Node nb : graphNode.neighbours) {
        if (!visited.contains(nb.id)) {
          Node child = new Node(nb.id);
          graph.addEdge(currentNode.id, child.id);
          dfs(radius - 1, graph, child, visited);
        }
      }
    }

    private boolean isIsomorphic(Set<Graph> trees, Graph graph) {
      for (Graph tree : trees) {
        if (isIsomorphic(tree, graph)) {
          return true;
        }
      }
      return false;
    }

    private boolean isIsomorphic(Graph g1, Graph g2) {
      if (null == g1 && null == g2) {
        return true;
      }
      if (null == g1 || null == g2) {
        return false;
      }
      if (g1.nodes.size() != g2.nodes.size()) {
        return false;
      }
      if (g1.edgeCount != g2.edgeCount) {
        return false;
      }

      List<Node> g1Nodes = new LinkedList<>(g1.nodes.values());
      List<Node> g2Nodes = new LinkedList<>(g2.nodes.values());
      Collections.sort(g1Nodes);
      Collections.sort(g2Nodes);
      for (int i = 0; i < g1Nodes.size(); i++) {
        Node n1 = g1Nodes.get(i);
        Node n2 = g2Nodes.get(i);

        if (n1.neighbours.size() != n2.neighbours.size()) {
          return false;
        }
      }
      return true;
    }
  }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int r = in.nextInt();
        
        Graph graph = new Graph();
        for(int a0 = 0; a0 < n-1; a0++){
            int x = in.nextInt();
            int y = in.nextInt();
            
            graph.addEdge(x,y);
        }
        int count = graph.countCuts(r);
        System.out.println(count);
    }
}
