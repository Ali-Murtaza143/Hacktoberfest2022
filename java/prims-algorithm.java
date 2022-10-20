HashSet<Integer> visited;
    PriorityQueue<Pair<Integer,Integer>> priorityQueue;// <index, distance>

    void EnQueue(int[][] points, int idx){
        for (int i=0;i<points.length;i++){
            if (visited.contains(i) || i==idx){
                continue;
            }
            priorityQueue.add(new Pair<>(i,getDistance(idx, i, points)));
        }
    }
	// calculate the Manhattan Distance
    private int getDistance(int idx, int i, int[][] points) {
        return Math.abs(points[idx][0]-points[i][0]) + Math.abs(points[idx][1]-points[i][1]);
    }


    // implement standard Prim's to solve Minimum Spanning Tree Problem
    public int minCostConnectPoints(int[][] points) {
        if (points.length<=1){
            return 0;
        }

        // no need to build a graph

        // memo to record the nodes that have been explored
         visited = new HashSet<>();

         // initialized the priorityQueue
        priorityQueue = new PriorityQueue<>((x,y)->x.getValue() - y.getValue());

        // initialized
        EnQueue(points,0);
        visited.add(0);

        // cost -> result
        int cost = 0;

        while(visited.size()!=points.length){
            Pair<Integer,Integer> newPoint =  priorityQueue.poll();
            if (visited.contains(newPoint.getKey())){
                continue;
            }

            // add the new point with shortest edge into the tree
            visited.add(newPoint.getKey());
            // update the cost
            cost += newPoint.getValue();
            EnQueue(points,newPoint.getKey());
        }
        return cost;
    }
