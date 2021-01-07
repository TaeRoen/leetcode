/*
 * @lc app=leetcode id=26 lang=golang
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
func removeDuplicates(nums []int) int {
	s := 0
	m := make(map[int]interface{}, 0)
	for i := 0; i < len(nums); i++ {
		c := nums[i]
		_, ok := m[c]
		if !ok {
			m[c] = nil
			nums[s] = c
			s++
		}
	}
	return s
}

// @lc code=end

