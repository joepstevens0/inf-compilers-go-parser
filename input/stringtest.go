package main

func main() {
	var x rune = 'x';
	print(x, '\n');
	print('\\', '\n');
	var s string = "teststring";
	print(s, '\n');
	s += " Q ";
	print(test(x, s), '\n')

	print("12345"[1], '\n');

	if "a" == "a"{
		print("compare", '\n');
	}
}

func test(c rune, s string) string{
	print(c, s + " concat", '\n');
	return "-----test\n\" \\ escape characters\"";
}