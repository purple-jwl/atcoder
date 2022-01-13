package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	x := make([]int, n)
	y := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&x[i], &y[i])
	}

	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			for k := j + 1; k < n; k++ {
				x1 := x[i] - x[k]
				y1 := y[i] - y[k]
				x2 := x[j] - x[k]
				y2 := y[j] - y[k]
				if x1*y2 == x2*y1 {
					fmt.Println("Yes")
					return
				}
			}
		}
	}

	fmt.Println("No")
}
