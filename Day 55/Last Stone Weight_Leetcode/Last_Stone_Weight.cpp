class Solution {
    public int lastStoneWeight(int[] stones) {
        if (stones.length == 1) return stones[0];
        // init max priority queue
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b) -> b - a);
        pq.addAll(Arrays.stream(stones).boxed().collect(Collectors.toList()));
        // smash 2 heaviest stones each time
        while (pq.size() > 1) {
            int first = pq.poll();
            int second = pq.poll();
            if (first > second) pq.offer(first - second);
        }
        return pq.size() == 1 ? pq.poll() : 0;
    }
}