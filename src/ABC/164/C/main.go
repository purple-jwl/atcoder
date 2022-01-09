package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	m := map[string]int{}

	for i := 0; i < n; i++ {
		var s string
		fmt.Scan(&s)
		m[s] = 1
	}

	fmt.Println(len(m))
}
