/*
 * @lc app=leetcode id=28 lang=golang
 *
 * [28] Implement strStr()
 */

// @lc code=start
func strStr(haystack string, needle string) int {
	if needle == "" {
		return 0
	}
	lenHaystack := len(haystack)
	lenNeedle := len(needle)
	if lenHaystack < lenNeedle {
		return -1
	}
	if lenHaystack == lenNeedle {
		if haystack == needle {
			return 0
		} else {
			return -1
		}
	}
	bytes := []byte(haystack)
	for i := 0; i <= lenHaystack-lenNeedle; i++ {
		if string(bytes[i:i+lenNeedle]) == needle {
			return i
		}
	}
	return -1
}

// @lc code=end

