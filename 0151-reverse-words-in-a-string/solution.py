class Solution:
    def reverseWords(self, s: str) -> str:

        words = []
        i = 0
        n = len(s)
        while i < n:
            while i < n and s[i] == " ":
                i += 1
            if i < n:
                word_start = i
              
                while i < n and s[i] != " ":
                    i += 1
                words.append(s[word_start:i])
        return " ".join(words[::-1])

