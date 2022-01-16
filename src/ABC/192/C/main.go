package main

import (
	"fmt"
	"sort"
	"strconv"
)

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	for i := 0; i < k; i++ {
		tmp := []rune(strconv.Itoa(n))
		sort.Slice(tmp, func(x, y int) bool {
			return tmp[x] > tmp[y]
		})
		g1, _ := strconv.Atoi(string(tmp))
		sort.Slice(tmp, func(x, y int) bool {
			return tmp[x] < tmp[y]
		})
		g2, _ := strconv.Atoi(string(tmp))
		n = g1 - g2
	}

	fmt.Println(n)
}
