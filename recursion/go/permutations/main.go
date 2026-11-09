package main

import "fmt"

func permutations(a string) []string {
	if len(a) == 0 {
		return []string{""}
	}
	var answer []string
	for i := 0; i < len(a); i++ {
		reversal := permutations(a[:i] + a[i+1:])
		for _, s := range reversal {
			answer = append(answer, string(a[i])+s)
		}
	}
	return answer
}

func main() {
	result := permutations("abc")
	fmt.Println(result)
}
