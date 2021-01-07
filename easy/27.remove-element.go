/*
 * @lc app=leetcode id=27 lang=golang
 *
 * [27] Remove Element
 */

// @lc code=start
func removeElement(nums []int, val int) int {
	s := 0
	for i := 0; i < len(nums); i++ {
		if nums[i] != val {
			nums[s] = nums[i]
			s++
		}
	}
	return s
}

// @lc code=end

