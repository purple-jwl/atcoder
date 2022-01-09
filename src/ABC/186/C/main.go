package main

import "fmt"

func a(v int) bool {
	for v > 0 {
		if (v % 10) == 7 {
			return false
		}
		v /= 10
	}

	return true
}

func b(v int) bool {
	for v > 0 {
		if (v % 8) == 7 {
			return false
		}
		v /= 8
	}

	return true
}

func main() {
	var n int
	fmt.Scan(&n)

	ans := 0
	for i := 1; i <= n; i++ {
		if a(i) && b(i) {
			ans++
		}
	}

	fmt.Println(ans)
}
