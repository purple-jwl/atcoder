package main

import "fmt"

func main() {
	var s, t string
	fmt.Scan(&s, &t)

	ans := 0
	for i := 0; i < len(s); i++ {
		if s[i] != t[i] {
			ans++
		}
	}

	fmt.Println(ans)
}
