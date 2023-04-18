package main

import "fmt"

type Queue struct {
	vec []int
}

func (q *Queue) push(v int) {
	q.vec = append(q.vec, v)
}

func (q *Queue) pop() {
	q.vec = q.vec[1:]
}

func (q *Queue) empty() bool {
	return len(q.vec) == 0
}

func (q *Queue) top() int {
	return q.vec[0]
}

func (q *Queue) len() int {
	return len(q.vec)
}

func main() {
	q := new(Queue)
	q.push(2)
	q.push(1)
	q.push(3)

	fmt.Println(q.top())

	for i := 0; i < 3; i++ {
		fmt.Println(q.top())
		q.pop()
	}
}

type MyStack struct {
	q1 Queue
	q2 Queue
	is_use1 bool
}

func Constructor() MyStack {
	stack := new(MyStack)
	stack.q1 = new(Queue)
	stack.q2 = new(Queue)
	stack.is_use1 = true
	return stack
}

func (this *MyStack) Push(x int) {
	if (this.is_use1) {
		this.q1.push(x)
	} else {
		this.q2.push(x)
	}
}

func (this *MyStack) Pop() int {
	var used Queue
	var buff Queue
	if (this.is_use1) {
		used = this.q1
		buff = this.q2
	} else {
		used = this.q2
		buff = this.q1
	}

	used_len := used.len()
	for i := 0; i < used_len - 1; i++ {
		buff.push(used.top())
		used.pop()
	}
	ret := used.top()
	used.pop()

	if this.is_use1 == false {
		this.is_use1 = true
	} else {
		this.is_use1 = false
	}

	return ret
}

func (this *MyStack) Top() int {
	var used Queue
	var buff Queue
	if (this.is_use1) {
		used = this.q1
		buff = this.q2
	} else {
		used = this.q2
		buff = this.q1
	}

	used_len := used.len()
	for i := 0; i < used_len - 1; i++ {
		buff.push(used.top())
		used.pop()
	}
	ret := used.top()
	used.pop()
	buff.push(ret)

	if this.is_use1 == false {
		this.is_use1 = true
	} else {
		this.is_use1 = false
	}

	return ret

}

func (this *MyStack) Empty() bool {
	return this.q1.empty() && this.q2.empty()
}

// /**
//  * Your MyStack object will be instantiated and called as such:
//  * obj := Constructor();
//  * obj.Push(x);
//  * param_2 := obj.Pop();
//  * param_3 := obj.Top();
//  * param_4 := obj.Empty();
//  */
