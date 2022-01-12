package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	ans := 0
	for i := 1; i < n; i++ {
		ans += (n - 1) / i
	}

	fmt.Println(ans)
}
