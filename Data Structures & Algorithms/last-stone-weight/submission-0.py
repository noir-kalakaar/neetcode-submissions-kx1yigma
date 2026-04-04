class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heapq.heapify_max(stones)
        

        while len(stones)>1:
            heaviest = heapq.heappop_max(stones)
            s_heaviest = heapq.heappop_max(stones)
            if(heaviest>=s_heaviest):
                heapq.heappush_max(stones,heaviest-s_heaviest)

        return stones[0]

