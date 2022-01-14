package main

import "fmt"

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	a := make([]int, m)
	b := make([]int, m)
	for i := 0; i < m; i++ {
		fmt.Scan(&a[i], &b[i])
	}

	var k int
	fmt.Scan(&k)
	c := make([]int, k)
	d := make([]int, k)
	for i := 0; i < k; i++ {
		fmt.Scan(&c[i], &d[i])
	}

	ans := 0
	for i := 0; i < (1 << k); i++ {
		p := map[int]int{}
		for j := 0; j < k; j++ {
			if (i>>j)%2 == 1 {
				p[c[j]] = 1
			} else {
				p[d[j]] = 1
			}
		}

		cnt := 0
		for j := 0; j < m; j++ {
			if p[a[j]] == 1 && p[b[j]] == 1 {
				cnt++
			}
		}

		if ans < cnt {
			ans = cnt
		}
	}

	fmt.Println(ans)
}
