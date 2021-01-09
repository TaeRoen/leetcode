/*
 * @lc app=leetcode id=66 lang=golang
 *
 * [66] Plus One
 */

// @lc code=start
func one(digits []int, n int) []int {
	if n == -1 {
		return append([]int{1}, digits...)
	}
	if digits[n] == 9 {
		digits[n] = 0
		return one(digits, n-1)
	}
	digits[n] = digits[n] + 1
	return digits
}

func plusOne(digits []int) []int {
	return one(digits, len(digits)-1)
}

// @lc code=end

