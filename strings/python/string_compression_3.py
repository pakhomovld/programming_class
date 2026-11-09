word = 'aaaaaaaaaaaaa'


def compressedString(word: str) -> str:
    result = []
    count = 1
    prev = word[0]

    for char in word[1:]:
        if char == prev:
            count += 1
        else:
            if count >= 1 and count < 9:
                result.append(str(count))
                result.append(prev)
            else:
                result.append(str(9))
                result.append(prev)
                result.append(str(count - 9))
                result.append(prev)
            prev = char
            count = 1
    
    if count >= 1 and count < 9:
        result.append(str(count))
        result.append(prev)
    else:
        result.append(str(9))
        result.append(prev)
        result.append(str(count - 9))
        result.append(prev)        

    return ''.join(result)
        

print(compressedString(word))