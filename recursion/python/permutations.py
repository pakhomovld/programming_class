# permutations

# ""
# ["abc","acb","bac","bca","cab","cba"]
# [""]
# "bc" - ["bc","cb"] - ["abc","acb"]
# "ac" - ["ac","ca"] - ["bac","bca"]
# "ab" - ["ab","ba"] - ["cab","cba"]

def permutations(a: str) -> [str]:
    if not a:
        return [""]
    else:
        answer = []
        for i in range(len(a)):
            reversal = permutations(a[:i] + a[i+1:])
            for j in range(len(reversal)):
                answer.append(a[i] + reversal[j])
        return answer

print(permutations("abc"))