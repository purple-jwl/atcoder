package main

import (
	"fmt"
	"math/big"
)

func main() {
	var l int
	fmt.Scan(&l)

	ans := big.NewInt(1)
	for i := 0; i < 11; i++ {
		ans.Mul(ans, big.NewInt(int64(l-1-i)))
	}
	for i := 0; i < 11; i++ {
		ans.Div(ans, big.NewInt(int64(i+1)))
	}

	fmt.Println(ans)
}
