package main
 
import (
    "fmt"
)
 
func main() {
    fmt.Print(" x |")
    for i := 1; i <= 22; i++ {
        fmt.Printf("%4d", i)
    }
    fmt.Print("\n---+")
    for i := 1; i <= 22; i++ {
        fmt.Print("----")
    }
    for j := 1; j <= 2; j++ {
        fmt.Printf("\n%2d |", j)
        for i := 1; i <= 22; i++ {
            if i >= j {
                fmt.Printf("%4d", i*j)
            } else {
                fmt.Print("    ")
            }
        }
    }
    fmt.Println("")
}
 
