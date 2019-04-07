class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        def generate(Str,left,right):
            
            if len(Str) == 2*n:
                ans.append(Str)
            if left < n:
                generate(Str+"(",left+1,right)
            if right < left:
                generate(Str+")",left,right+1)
        
        ans = []
        generate("",0,0)
        return ans
