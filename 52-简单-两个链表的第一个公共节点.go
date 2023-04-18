package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func getIntersectionNode(headA, headB *ListNode) *ListNode {
	mymap := make(map[*ListNode]bool)

	for tmp := headA; tmp != nil; tmp = tmp.Next {
		mymap[tmp] = true
	}
	var ret *ListNode = nil
	for tmp := headB; tmp != nil; tmp = tmp.Next {
		_, ok := mymap[tmp]
		if ok  {
			ret = tmp
			break
		}
	}
	return ret
}
