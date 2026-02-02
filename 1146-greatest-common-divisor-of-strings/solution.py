class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        def can_construct(pattern: str, target: str) -> bool:
            constructed = ""
            while len(constructed) < len(target):
                constructed += pattern
          
            
            return constructed == target
    
        for length in range(min(len(str1), len(str2)), 0, -1):
            
            candidate = str1[:length]
          
           
            if can_construct(candidate, str1) and can_construct(candidate, str2):
                return candidate
        return ""

