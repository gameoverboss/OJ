package main

import (
	"fmt"
	"math"
)

func isNum(c byte) bool {
	if c < '0' || c > '9' {
		return false
	}
	return true
}

func myAtoi(str string) int {
	nNum := 0
	for i, val := range str {
		if nNum == 0 && val == '0' {
			continue
		}
		if isNum(byte(val)) {
			nNum++
			if nNum > 10 {
				str = str[:i+1]
				break
			}
			continue
		}
		if nNum != 0 {
			break
		}
	}
	var a int
	n, _ := fmt.Sscanf(str, "%d", &a)
	if n != 1 {
		return 0
	}
	if a < math.MinInt32 {
		return math.MinInt32
	}
	if a > math.MaxInt32 {
		return math.MaxInt32
	}
	return a
}

func main() {
	ret := myAtoi("42")
	if ret != 42 {
		fmt.Printf("FAIL: %d\n", ret)
		return
	}
	ret = myAtoi("    -42")
	if ret != -42 {
		fmt.Printf("FAIL: %d\n", ret)
		return
	}
	ret = myAtoi("4193 with words")
	if ret != 4193 {
		fmt.Println("FAIL2")
		return
	}
	ret = myAtoi("words and 987")
	if ret != 0 {
		fmt.Println("FAIL3")
		return
	}
	ret = myAtoi("-91283472332")
	if ret != math.MinInt32 {
		fmt.Println("FAIL5 ")
		return
	}
	ret = myAtoi("-20000000000000000000")
	if ret != math.MinInt32 {
		fmt.Printf("FIAL: -20000000000000000000 %d\n", ret)
		return
	}
	ret = myAtoi("20000000000000000000")
	if ret != math.MaxInt32 {
		fmt.Println("FAIL7")
		return
	}
	ret = myAtoi("+321")
	if ret != 321 {
		fmt.Println("FAIL8")
		return
	}
	ret = myAtoi("+ 321")
	if ret != 0 {
		fmt.Println("FAIL9")
		return
	}
	ret = myAtoi("fadsfasd")
	if ret != 0 {
		fmt.Println("FAIL10")
		return
	}
	ret = myAtoi("")
	if ret != 0 {
		fmt.Println("FAIL11")
		return
	}
	ret = myAtoi("    ")
	if ret != 0 {
		fmt.Println("FAIL12")
		return
	}
	ret = myAtoi("  0000000000012345678")
	if ret != 12345678 {
		fmt.Println("FAIL13")
		return
	}
	fmt.Println("OK")
}
