# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = None
        if l1 == None or l2 == None:
            if l1 == None and l2 != None:
                head = l2
            elif l2 == None and l1 != None:
                head = l1
            else:
                pass
            return head
        
        if l1.val>l2.val:
            head = ListNode(l2.val)
            p = l1
            q = l2.next
        else:
            head = ListNode(l1.val)
            p = l1.next
            q = l2
        alt = head
        
        while p!=None and q!= None:
            if p.val > q.val:
                new = ListNode(q.val)
                alt.next = new
                alt = new
                q = q.next
            else:
                new = ListNode(p.val)
                alt.next = new
                alt = new
                p = p.next
        if p == None:
            while q != None:
                new = ListNode(q.val)
                alt.next = new
                alt = new
                q = q.next
        else:
            while p != None:
                new = ListNode(p.val)
                alt.next = new
                alt = new
                p = p.next
        return head
