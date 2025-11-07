#5! = 1 * 2 * 3 * 4 * 5

def factorial(n):
    counter = n
    answer = n

    while counter != 1:
        counter = counter - 1
        answer = answer * counter

    return answer

print(factorial(1))

"""
1! = 1
2! = 1 * 2 = 2
3! = 1 * 2 * 3 = 6
1 2 3
3 2 1
2 3 1
1 3 2
2 1 3
3 1 3
4! = 3! * 4 = 24
5! = 4! * 5 = 120

n! = (n-1)! * n
"""

def fact(n):
	if n == 1:
		return 1
	else:
		return fact(n - 1) * n

print(fact(5))

# Golang
# Перевести сегодняшний код в Golang

# "Как написать n в Go"
# Получаем ошибки, просим объяснить

# Подсказки и примеры, но не сам код


