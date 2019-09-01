package main

import "fmt"

func min(a int, b int) int {
	if a <= b {
		return a
	}
	return b
}

func convert(s string, numRows int) string {
	di := 1
	rLen := len(s)
	rows := make([]string, min(rLen, numRows))
	curR := 0

	if numRows == 1 {
		return s
	}

	for _, c := range s {
		rows[curR] = rows[curR] + string(c)
		if curR == 0 {
			di = 1
		} else if curR == numRows-1 {
			di = -1
		}
		curR = curR + di
	}

	ret := ""
	for _, j := range rows {
		ret = ret + j
	}
	return ret
}

func main() {
	ret := convert("LEETCODEISHIRING", 3)
	if ret != "LCIRETOESIIGEDHN" {
		fmt.Println("FAIL")
		return
	}
	ret = convert("LEETCODEISHIRING", 4)
	if ret != "LDREOEIIECIHNTSG" {
		fmt.Println("FAIL")
		return
	}
	ret = convert("AB", 1)
	if ret != "AB" {
		fmt.Println("FAIL")
		return
	}
	fmt.Println("OK")
}
