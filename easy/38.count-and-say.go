package main

import (
	"fmt"
	"strings"
)

/*
 * @lc app=leetcode id=38 lang=golang
 *
 * [38] Count and Say
 */

// @lc code=start
func string2int(str string) int {
	switch str {
	case "0":
		return 0
	case "1":
		return 1
	case "2":
		return 2
	case "3":
		return 3
	case "4":
		return 4
	case "5":
		return 5
	case "6":
		return 6
	case "7":
		return 7
	case "8":
		return 8
	case "9":
		return 9
	}
	return 0
}

func int2string(i int) string {
	switch i {
	case 0:
		return "0"
	case 1:
		return "1"
	case 2:
		return "2"
	case 3:
		return "3"
	case 4:
		return "4"
	case 5:
		return "5"
	case 6:
		return "6"
	case 7:
		return "7"
	case 8:
		return "8"
	case 9:
		return "9"
	}
	return ""
}

func countAndSay(n int) string {
	if n == 1 {
		return "1"
	}
	input := "1"
	for i := 2; i <= n; i++ {
		count := 0
		num := ""
		output := ""
		for _, c := range strings.Split(input, "") {
			if count == 0 {
				count = 1
				num = c
				continue
			}
			if num == c {
				count++
				continue
			}
			if num != c {
				output = output + int2string(count) + num
				count = 1
				num = c
				continue
			}
		}
		output = output + int2string(count) + num
		input = output
	}
	return input
}

// @lc code=end
func main() {
	for i := 1; i <= 30; i++ {
		fmt.Println(countAndSay(i))
	}
}
