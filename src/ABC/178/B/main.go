package main

import (
	"fmt"
)

func max(vs ...int) int {
	if len(vs) == 0 {
		panic("error")
	}

	maxv := vs[0]
	for _, v := range vs {
		if maxv < v {
			maxv = v
		}
	}

	return maxv
}

func main() {
	var a, b, c, d int
	fmt.Scan(&a, &b, &c, &d)

	ans := max(a * c, a * d, b * c, b * d)

	fmt.Println((ans))
}
