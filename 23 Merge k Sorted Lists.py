# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        amount = len(lists)                                         #本例中有个特别需要关注的点就是，如何在不消耗多余空间的情况下，
        interval = 1                                                #对一个数组中的元素进行两两分析处理，最终得到整个数组的最优解。
        while interval < amount:
            for i in range(0, amount - interval, interval * 2):
                lists[i] = self.merge2Lists(lists[i], lists[i + interval])
            interval *= 2
        return lists[0] if amount > 0 else lists
        
    def merge2Lists(self,l1,l2):
        head = ListNode(0)
        p = head
        while l1  and l2:
            if l1.val <= l2.val:
                p.next = l1
                l1 = l1.next
            else:
                p.next = l2
                l2 = l2.next
            p = p.next
        if not l1:
            p.next = l2
        if not l2:
            p.next = l1
        return head.next

 
