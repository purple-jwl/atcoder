package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	c := make([][]rune, n)
	for i := 0; i < n; i++ {
		var s string
		fmt.Scan(&s)
		c[i] = []rune(s)
	}

	f := false

	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			cnt := 0

			if i+5 < n {
				cnt = 0
				for k := 0; k < 6; k++ {
					if c[i+k][j] == '#' {
						cnt++
					}
				}
				if cnt >= 4 {
					f = true
				}
			}

			if j+5 < n {
				cnt = 0
				for k := 0; k < 6; k++ {
					if c[i][j+k] == '#' {
						cnt++
					}
				}
				if cnt >= 4 {
					f = true
				}
			}

			if i+5 < n && j+5 < n {
				cnt = 0
				for k := 0; k < 6; k++ {
					if c[i+k][j+k] == '#' {
						cnt++
					}
				}
				if cnt >= 4 {
					f = true
				}
			}

			if i-5 >= 0 && j+5 < n {
				cnt = 0
				for k := 0; k < 6; k++ {
					if c[i-k][j+k] == '#' {
						cnt++
					}
				}
				if cnt >= 4 {
					f = true
				}
			}
		}
	}

	if f {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
