package main

import "fmt"

func main() {
	var h, w, k int
	fmt.Scan(&h, &w, &k)

	c := make([][]rune, h)
	for i := 0; i < h; i++ {
		var s string
		fmt.Scan(&s)
		c[i] = []rune(s)
	}

	ans := 0
	for i := 0; i < (1 << h); i++ {
		for j := 0; j < (1 << w); j++ {
			cnt := 0
			for p := 0; p < h; p++ {
				for q := 0; q < w; q++ {
					if (i>>p)%2 == 0 && (j>>q)%2 == 0 && c[p][q] == '#' {
						cnt++
					}
				}
			}
			if cnt == k {
				ans++
			}
		}
	}

	fmt.Println(ans)
}
