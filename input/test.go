package main
func main() {
	print(+3425 + 1 - 5, '\n');
	var a int = 3;
	a++
	var b int;
	var d bool;
	var c = 100;
	{
		c++
		var c = 2;
		c++
		print(a,b,c, '\n')
	}
	var e = 1;
	var f = false;
	print(a,c ,f, '\n');

	if a == 5{
		print(a, '\n');
	} else {
		a--;
		print(a, '\n');
	}

	for var i = 0;i < 5;{
		print(i, '\n')
		i++
	}
}
func test(a int) int{
	return a - 1;
}