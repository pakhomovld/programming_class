import re

s = '0P'

def isPalindrome(s: str) -> bool:
    s = re.sub(r'[^a-zA-Z0-9]', '', s)
    s = str.lower(s)
    
    return s == s[::-1]

print(isPalindrome(s))


