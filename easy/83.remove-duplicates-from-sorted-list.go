package main

/*
 * @lc app=leetcode id=83 lang=golang
 *
 * [83] Remove Duplicates from Sorted List
 */

type ListNode struct {
	Val  int
	Next *ListNode
}

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	m := make(map[int]interface{})
	ret := head
	pre := head
	m[head.Val] = nil
	head = head.Next
	for {
		if head == nil {
			return ret
		}
		_, ok := m[head.Val]
		if ok {
			pre.Next = head.Next
		} else {
			m[head.Val] = nil
			pre.Next = head
			pre = head
		}
		head = head.Next
	}
	return ret
}

// @lc code=end
