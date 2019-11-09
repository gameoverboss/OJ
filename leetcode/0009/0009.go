package main

import (
	"fmt"
)

func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}
	old := x
	tmp := 0
	for x != 0 {
		mod := x % 10
		x = x / 10
		tmp = tmp*10 + mod
	}
	if tmp == old {
		return true
	}
	return false
}

func main() {
	ret := isPalindrome(121)
	if ret != true {
		fmt.Printf("FAIL: \n")
		return
	}
	ret = isPalindrome(-121)
	if ret != false {
		fmt.Printf("FAIL: \n")
		return
	}
	ret = isPalindrome(10)
	if ret != false {
		fmt.Printf("FAIL: \n")
		return
	}
	fmt.Println("OK")
}
