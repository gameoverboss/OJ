package main

import "fmt"

func getLongest(s string, i int) (int, int) {
	left := i / 2
	right := (i + 1) / 2
	for left >= 0 && right < len(s) && s[left] == s[right] {
		left--
		right++
	}
	return left + 1, right - 1
}

func longestPalindrome(s string) string {
	maxLen := 0
	maxLeft := 0
	maxRight := 0
	len := len(s)
	n := len*2 - 1
	if len == 0 {
		return ""
	}

	for i := 0; i < n; i++ {
		left, right := getLongest(s, i)
		if right-left+1 > maxLen {
			maxLen = right - left + 1
			maxLeft = left
			maxRight = right
		}
	}

	return s[maxLeft : maxRight+1]
}

func main() {
	ret := longestPalindrome("cbbd")
	if ret != "bb" {
		fmt.Println("FAIL")
		return
	}
	ret = longestPalindrome("bb")
	if ret != "bb" {
		fmt.Println("FAIL")
		return
	}
	fmt.Println("OK")
}
