import ctypes

class DynamicArray:
    def __init__(self):
        self._size = 0
        self._capacity = 10
        self._array = self._make_array(self._capacity)

    def _make_array(self, capacity):
        return (ctypes.c_int * capacity)()
    
    def __len__(self):
        return self._size

    def append(self, value):
        if self._size == self._capacity:
            self._resize(self._capacity * 2)
        self._array[self._size] = value
        self._size += 1

    def _resize(self, new_capacity):
        new_array = self._make_array(new_capacity)
        for i in range(self._size):
            new_array[i] = self._array[i]
        self._array = new_array
        self._capacity = new_capacity

    def __getitem__(self, key):
        a = DynamicArray()
        if isinstance(key, slice):
            start = 0 if key.start == None else key.start
            stop = self._size if key.stop == None else key.stop
            step = 1 if key.step == None else key.step
            for i in range(start, stop, step):
                a.append(self._array[i])
            return a
        elif key < 0:
            return self._array[self._size + key]
        else:
            key = self._normalize_index(key)
            return self._array[key]

    def __setitem__(self, key, value):
        key = self._normalize_index(key)
        self._array[key] = value

    def __str__(self):
        arr = ""
        for i in range(self._size):
            if i < self._size - 1:
                arr += str(self._array[i]) + ", "
            else:
                arr += str(self._array[i])
        return "[" + arr + "]"

    def __iter__(self):
        for i in range(self.size):
            yield self._array[i]

    def __contains__(self, value):
        for i in range(self._size):
            if self._array[i] == value:
                return True
        return False

    def extend(self, iterable):
        for value in iterable:
            self.append(value)

    def remove(self, value):
        idx = self.index(value)
        self.pop(idx)
                       
    def count(self, value):
        cnt = 0
        for i in range(self._size):
            if self._array[i] == value:
                cnt += 1
        return cnt

    def clear(self):
        self._size = 0
        self._capacity = 10
        self._array = self._make_array(self._capacity)

    def __delitem__(self, key):
        self.pop(key)

    def reverse(self):
        left = 0
        right = self._size - 1
        while left < right:
            self._array[left], self._array[right] = self._array[right], self._array[left]
            left += 1
            right -= 1

    def _normalize_index(self, key):
        if key < 0:
            key += self._size
        if not 0 <= key < self._size:
            raise IndexError("Index out of range")
        return key

    def pop(self, key=-1):
        if self._size == 0:
            raise IndexError("pop from empty list")
        key = self._normalize_index(key)
        element = self._array[key]
        for i in range(key, self._size - 1):
            self._array[i] = self._array[i+1]
        self._size -= 1
        return element

    def insert(self, key, value):
        if key < 0:
            key += self._size
        if not 0 <= key <= self._size:
            raise IndexError("Index out of range")

        if self._size == self._capacity:
            self._resize(self._capacity * 2)

        for i in range(self._size, key, -1):
            self._array[i] = self._array[i-1]
        self._array[key] = value
        self._size += 1

    def index(self, value):
        for i in range(self._size):
            if self._array[i] == value:
                return i
        raise ValueError(f"{value} is not in list")






a = DynamicArray()

for i in range(20):
    a.append(i)
print(a)
print(a[-5])


# доделать все методы

# почитать про связные списки