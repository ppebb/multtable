package main

import (
	"fmt"
	"strconv"
)

func digitCount(num int64) int64 {
	return int64(len(strconv.FormatInt(num, 10)))
}

func printNTimes(n int64, str string) {
	for i := int64(0); i < n; i++ {
		fmt.Print(str)
	}
}

func main() {
	var inp string
	fmt.Print("Input the number of columns: ")
	fmt.Scanln(&inp)
	columns, err := strconv.ParseInt(inp, 10, 64)
	if err != nil {
		fmt.Println("Invalid Input for colums, please enter a number next time!")
		return
	}
	fmt.Print("Input the number of rows: ")
	fmt.Scanln(&inp)
	rows, err := strconv.ParseInt(inp, 10, 64)
	if err != nil {
		fmt.Println("Invalid Input for colums, please enter a number next time!")
		return
	}

	rowDigitsLen := int64(digitCount(rows))
	maxDigitsLen := int64(digitCount(rows * columns))

	printNTimes(rowDigitsLen+1, " ")
	fmt.Print(" |")
	for i := int64(1); i < columns+1; i++ {
		printNTimes(maxDigitsLen-digitCount(i)+1, " ")
		fmt.Print(i)
	}
	fmt.Println()

	printNTimes(3+rowDigitsLen+(columns*(maxDigitsLen+1)), "-")
	fmt.Println()

	for row := int64(1); row < rows+1; row++ {
		printNTimes(1+rowDigitsLen-digitCount(row), " ")
		fmt.Print(row)
		fmt.Print(" |")
		for column := int64(1); column < columns+1; column++ {
			val := column * row
			printNTimes(1+maxDigitsLen-digitCount(val), " ")
			fmt.Print(val)
		}
		fmt.Println()
	}
}
