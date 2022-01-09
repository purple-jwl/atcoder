package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	ans := 0
	h := -1
	for i := 0; i < n; i++ {
		var a int
		fmt.Scan(&a)

		if h <= a {
			h = a
		} else {
			ans += h - a
		}
	}

	fmt.Println(ans)
}
