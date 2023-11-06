package main

func f(n int) int{
	if n <= 0{
		return 1;
	}
	return n*f(n-1);
}

func main() {
	print(f(5));
}