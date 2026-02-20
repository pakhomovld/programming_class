# Example 1:

# Input: s = "aba"
# Output: true
# Example 2:

# Input: s = "abca"
# Output: true
# Explanation: You could delete the character 'c'.
# Example 3:

# Input: s = "abc"
# Output: false
import re

s = "abca"

def validPalindrome(s: str) -> bool:
    s = re.sub(r'[^a-zA-Z0-9]', '', s)
    s = str.lower(s)
    print(s)
    for i in range(len(s)):
        substr = s[i:] + s[i+1:]
        if substr == substr[::-1]
            return True
    return False

print(validPalindrome(s))