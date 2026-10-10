from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        kv = defaultdict(list)
        for string in strs:
            freq = [0]*26
            s=""
            for char in string:
                freq[ord(char)-ord('a')]+=1
            for i in range(26):
                s+=str(freq[i])
                s+='.'
            kv[s].append(string)
        res = []
        for k,v in kv.items():
            res.append(v)
        return res


                        