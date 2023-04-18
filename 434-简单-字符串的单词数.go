package main

import (
	"fmt"
	"strings"
)

func countSegments(s string) int {
	strings.Trim(s, " ")
	if len(s) == 0 {
		return 0
	}
	splic := strings.Split(s, " ")
	return len(splic)
}

