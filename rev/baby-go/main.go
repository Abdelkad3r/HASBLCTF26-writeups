package main

import (
	"fmt"
)

func main() {
	var crazy = "SEFTQkx7QjRCWV9HMEw0TkdfMTExMX0="
	var c uint8 = '0'
	for i := 0; i < len(crazy); i++ {
		c = crazy[i]
		fmt.Printf("Did you do your homework?!?!?%x!?!\n", c)

	}

}
