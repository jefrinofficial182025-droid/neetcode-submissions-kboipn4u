class Solution:

    def encode(self, strs: List[str]) -> str:
        encstr=''
        for i in strs: 
            encstr+= str(len(i)) + '#' + i
        return encstr
    def decode(self, s: str) -> List[str]:
        ans=[]
        i=0
        while i<len(s):
            j=i
            while s[j]!='#':
                    j+=1
            length=int(s[i:j])
            j+=1
            ans.append(s[j:length+j])
            i=j+length
        return ans