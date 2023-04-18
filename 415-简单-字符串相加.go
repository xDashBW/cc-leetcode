package main

import (
	"fmt"
	"strconv"
)

func addStrings(num1 string, num2 string) string {
	i := len(num1) - 1
	j := len(num2) - 1
	add := 0
	str := ""
	for ; i >= 0 || j >= 0 || add > 0; i, j = i-1, j-1 {
		var x int
		var y int
		if i >= 0 {
			x, _ = strconv.Atoi(string(num1[i]))
		}
		if j >= 0 {
			y, _ = strconv.Atoi(string(num2[j]))
		}
		result := x + y + add
		str = strconv.Itoa(result % 10) + str
		add = result / 10
	}
	return str
}

func main() {
	str := addStrings("123", "1239")
	fmt.Println(str)
}
