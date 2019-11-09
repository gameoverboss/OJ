package main

import (
	"fmt"
)

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
