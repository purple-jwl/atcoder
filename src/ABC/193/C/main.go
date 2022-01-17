package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	m := map[int]int{}
	for i := 2; i*i <= n; i++ {
		v := i
		for {
			if n < v*i {
				break
			}
			v *= i
			m[v] = 1
		}
	}

	fmt.Println(n - len(m))
}
