/*
 * @lc app=leetcode id=14 lang=golang
 *
 * [14] Longest Common Prefix
 */
package main

// @lc code=start
func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	prefix := []byte(strs[0])
	min := len(prefix)
	if len(strs) == 1 {
		return strs[0]
	}
	for _, str := range strs[1:] {
		if len(str) < min {
			min = len(str)
			prefix = prefix[:min]
		}
		for i := 0; i < min; i++ {
			if prefix[i] != []byte(str)[i] {
				if i == 0 {
					return ""
				}
				prefix = prefix[:i]
				min = i
				break
			}
		}
	}
	return string(prefix)
}

// @lc code=end

func main() {
	longestCommonPrefix("")
}
