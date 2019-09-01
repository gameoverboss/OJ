package main

import (
	"fmt"
	"math"
)

func max(a int, b int) float64 {
	if a >= b {
		return float64(a)
	}
	return float64(b)
}

func min(a int, b int) float64 {
	if a <= b {
		return float64(a)
	}
	return float64(b)
}

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	n := len(nums1)
	m := len(nums2)

	if n > m {
		return findMedianSortedArrays(nums2, nums1)
	}

	var lMax1 int
	var lMax2 int
	var rMin1 int
	var rMin2 int
	var cut1 int
	var cut2 int
	lo := 0
	hi := 2 * n

	for lo <= hi {
		cut1 = (lo + hi) / 2
		cut2 = n + m - cut1

		if cut1 == 0 {
			lMax1 = math.MinInt32
		} else {
			lMax1 = nums1[(cut1-1)/2]
		}
		if cut1 == 2*n {
			rMin1 = math.MaxInt32
		} else {
			rMin1 = nums1[cut1/2]
		}
		if cut2 == 0 {
			lMax2 = math.MinInt32
		} else {
			lMax2 = nums2[(cut2-1)/2]
		}
		if cut2 == 2*m {
			rMin2 = math.MaxInt32
		} else {
			rMin2 = nums2[cut2/2]
		}

		if lMax1 > rMin2 {
			hi = cut1 - 1
		} else if lMax2 > rMin1 {
			lo = cut1 + 1
		} else {
			break
		}
	}
	return ((max(lMax1, lMax2) + min(rMin1, rMin2)) / 2.0)
}

func main() {
	nums1 := []int{1, 3}
	nums2 := []int{2}
	fmt.Println(findMedianSortedArrays(nums1, nums2))

	nums1 = []int{1, 2}
	nums2 = []int{3, 4}
	fmt.Println(findMedianSortedArrays(nums1, nums2))
}
