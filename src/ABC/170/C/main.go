package main

import "fmt"

func main() {
	var x, n int
	fmt.Scan(&x, &n)

	m := map[int]int{}
	for i := 0; i < n; i++ {
		var p int
		fmt.Scan(&p)
		m[p] = 1
	}

	for i := 0; ; i++ {
		if _, exist := m[x-i]; !exist {
			fmt.Println(x - i)
			return
		}
		if _, exist := m[x+i]; !exist {
			fmt.Println(x + i)
			return
		}
	}
}
