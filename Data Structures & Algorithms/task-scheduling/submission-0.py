class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        freq = [0]*26
        for i in range(len(tasks)):
            freq[ord(tasks[i])-ord('A')]+=1
        freq.sort()
        maxi = freq[-1]
        gap = (maxi-1)*n

        for i in range(24,-1,-1):
            gap-=min(maxi-1,freq[i])
        return max(0,gap)+len(tasks)