class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s=s.lower()
        s = [x for x in s if x.isalpha() or x.isdigit()]
        for i in range(len(s)/2):
            if s[i]!=s[len(s)-i-1]:
                return False
        return True

        