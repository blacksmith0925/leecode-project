def find_s0match_pos(s):
    count = 0
    if s[0] == '(':
        for i in range(1,len(s)):
            if s[i] == '(':
                count = count + 1 
            if s[i] == ')':
                if count == 0:
                    return i
                count = count - 1
    elif s[0] == '{':
        for i in range(1,len(s)):
            if s[i] == '{':
                count = count + 1  
            if s[i] == '}':
                if count == 0:
                    return i
                count = count - 1
    elif s[0] == '[':
        for i in range(1,len(s)):
            if s[i] == '[':
                count = count + 1 
            if s[i] == ']':
                if count == 0:
                    return i
                count = count - 1
    else:
        return None

def judge(s):
    if len(s) == 0:
        return True
    pos = find_s0match_pos(s)
    
    if pos == None:
            return False
    
    if pos == len(s)-1:
        if pos == 1:
            return True
        if pos > 1:
            return judge(s[1:pos])
    else:
        if judge(s[0:pos+1]) and judge(s[pos+1:]):
            return True
        else:
            return False

class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        result = judge(s)
        return result
    

