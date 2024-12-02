# problem link: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/

class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        words = sentence.split()
        for index, word in enumerate(words):
            if len(searchWord) > len(word):
                continue
            found = True
            for i in range(len(searchWord)):
                if word[i] != searchWord[i]:
                    found = False
            if found:
                return index+1
        return -1