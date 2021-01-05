/*
 * @lc app=leetcode id=13 lang=golang
 *
 * [13] Roman to Integer
 */
package main

import (
	"fmt"
	"strings"
)

// @lc code=start
func romanToInt(s string) int {
	m := map[string]int{
		"I": 1,
		"V": 5,
		"X": 10,
		"L": 50,
		"C": 100,
		"D": 500,
		"M": 1000,
	}
	ret := 0
	pre := 0
	status := 0
	l := strings.Split(s, "")
	i := 0
	for {
		if i == len(l) {
			break
		}

		c := l[i]

		if m[c] == 0 {
			return 0
		}

		if status == 0 {
			pre = m[c]
			status = -1
			ret += m[c]
			i++
			continue
		}
		if status == -1 {
			if pre == m[c] {
				ret += pre
				status = -2
				i++
				continue
			}
			if pre > m[c] {
				status = 0
				continue
			}
			if pre < m[c] {
				ret -= pre * 2
				ret += m[c]
				i++
				continue
			}
		}
		if status == -2 {
			if pre == m[c] {
				ret += pre
				status = 0
				i++
				continue
			} else {
				status = 0
				continue
			}
		}
	}
	return ret
}

// @lc code=end

func main() {
	fmt.Println(romanToInt("LVIII"))
}
