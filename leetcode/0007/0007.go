package main

import (
	"fmt"
	"math"
)

func reverse(x int) int {
	if x == math.MinInt32 {
		return 0
	}

	sign := 1
	if x < 0 {
		sign = -1
		x = -x
	}
	ret := 0
	for x != 0 {
		mod := x % 10
		x = x / 10
		if mod != 0 || ret != 0 {
			ret = ret*10 + mod
			if ret > math.MaxInt32 {
				return 0
			}
		}
	}

	return ret * sign
}

func main() {
	ret := reverse(123)
	if ret != 321 {
		fmt.Printf("FAIL: %d\n", ret)
		return
	}
	ret = reverse(-123)
	if ret != -321 {
		fmt.Println("FAIL2")
		return
	}
	ret = reverse(120)
	if ret != 21 {
		fmt.Println("FAIL3")
		return
	}
	ret = reverse(math.MinInt32)
	if ret != 0 {
		fmt.Println("FAIL4")
		return
	}
	// 901000
	ret = reverse(901000)
	if ret != 109 {
		fmt.Println("FAIL4")
		return
	}
	// 1534236469
	ret = reverse(1534236469)
	if ret != 0 {
		fmt.Println("FAIL4")
		return
	}
	fmt.Println("OK")
}
