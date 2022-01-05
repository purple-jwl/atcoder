package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	keys := []string{"AC", "WA", "TLE", "RE"}

	c := map[string]int{}
	for _, k := range keys {
		c[k] = 0
	}

	var s string
	for i := 0; i < n; i++ {
		fmt.Scan(&s)
		c[s]++
	}

	for _, k := range keys {
		fmt.Println(k, "x", c[k])
	}
}
