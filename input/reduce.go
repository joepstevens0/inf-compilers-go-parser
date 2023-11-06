package main
func main() {
	var x int = 2+2*2;
	print(x, '\n')
	x = 2*2+2
	print(x, '\n')
	x = +2+- - + + 2
	print(x, '\n')

	if false && true || true {
		print(0, '\n')
	}
	if false && (true || true) {
		print(1, '\n');
	}
}