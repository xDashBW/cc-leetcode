package rko

type MyStack struct {
	vec []int
}

func (this *MyStack) StackPush(x int) {
	this.vec = append(this.vec, x)
}

func (this *MyStack) StackPop() int {
	ret := this.vec[len(this.vec) - 1]
	this.vec = this.vec[:len(this.vec) - 1]
	return ret
}

func (this *MyStack) Empty() bool {
	return len(this.vec) == 0
}

func (this *MyStack) Len() int {
	return len(this.vec)
}

type MyQueue struct {
	stack1 MyStack
	stack2 MyStack
}

func Constructor() MyQueue {
	var v MyQueue
	return v
}

func (this *MyQueue) Push(x int) {
	this.stack1.StackPush(x)
}

func (this *MyQueue) Pop() int {
	if (this.stack2.Empty()) {
		sz := this.stack1.Len()
		for i := 0; i < sz; i++ {
			this.stack1.StackPush(this.stack2.StackPop())
		}
	}
	ret := this.stack2.StackPop()
	return ret
}

func (this *MyQueue) Peek() int {
	if (this.stack2.Empty()) {
		sz := this.stack1.Len()
		for i := 0; i < sz; i++ {
			this.stack1.StackPush(this.stack2.StackPop())
		}
	}
	ret := this.stack2.StackPop()
	this.stack2.StackPush(ret)
	return ret
}

func (this *MyQueue) Empty() bool {
	return len(this.stack1.vec) == 0 && len(this.stack2.vec) == 0
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Peek();
 * param_4 := obj.Empty();
 */
