seq = '222L'
pos = 0

def unpack_string(seq: str, pos: int) -> str:
    result = ''
    if pos == len(seq):
        return result
    elif seq[pos] == '2':
        result = unpack_string(seq, pos+1) + unpack_string(seq, pos+2)
    else:
        result = seq[pos] + unpack_string(seq, pos+1)

print(unpack_string(seq, pos))

