#
# @lc app=leetcode id=2 lang=python3
#
# [2] Add Two Numbers
#
# Definition for singly-linked list.


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        t1 = l1
        t2 = l2
        carry = 0
        ret = ListNode(0)
        t = ret
        while t1 is not None or t2 is not None:
            t1 = ListNode(0) if t1 is None else t1
            t2 = ListNode(0) if t2 is None else t2
            x = t1.val+t2.val+carry
            carry = x//10
            x = x % 10
            t.next = ListNode(x)
            t = t.next
            t1 = t1.next
            t2 = t2.next
        if carry == 1:
            t.next = ListNode(1)
        return ret.next
