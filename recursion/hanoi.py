

def hanoi(disks: int, tower_from: int, tower_target: int, tower_spare: int):
    if disks < 1:
        return "No disks"
    hanoi(disks - 1, tower_from, tower_spare, tower_target)
    print(tower_from, tower_target)
    hanoi(disks - 1, tower_spare, tower_target, tower_from)
    
print(hanoi(3, 1, 3, 2))

def hanoi_arr(disks: int, tower_from: int, tower_target: int, tower_spare: int) -> [(int,int)]:
    if disks < 1:
        return []
    transfers = hanoi_arr(disks - 1, tower_from, tower_spare, tower_target)
    transfers += [(tower_from, tower_target)]
    transfers += hanoi_arr(disks - 1, tower_spare, tower_target, tower_from)
    return transfers

#print(len(hanoi_arr(8, 1, 3, 2)))
print(hanoi_arr(3, 1, 3, 2))

