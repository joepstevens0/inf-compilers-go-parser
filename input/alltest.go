package main

func main() {
	
	// types int and bool
	var b bool = true;
	var i int = 0;

	// int literals
	i = 01_2;
	i = 0b01_1
	i = 0o07;
	i = 0x_0F;

	// print
	print("1 ",i, '\n');

	// blocks
	{
		print("2 ", i);
		var i = 10;
		print("3 ", i);
	}
	print("4 ", i, '\n');

	// function call
	print("6 ", f(100, false), '\n')

	// binary operators
	b = true;
	var c = b && true;
	c = b || false;
	c = !(b && false);
	print("7 ", c, '\n');

	// decimal operators
	var a = 1;
	var d = a + 1;
	d = a + +- -1;
	d = a*2;
	d = 4/2;
	d++
	d--
	print("8 ",d, '\n');

	// relative operators
	a = 1;
	c = a > 1;
	c = a >= 1;
	c = a < 1;
	c = a <= 1;
	c = a == 1;
	c = a != 1;
	c = true == true;
	c = true != true;
	print("9 ", c, '\n')

	// assignments
	a = 1;
	a += 1;
	a -= 1;
	a *= 2;
	a /= 2;
	print("10 ", a, '\n');

	// statements
	for var i = 0; i < 3; i++ {
		print("11 ", i, '\n')
		var i = -1;
		print("12 ", i, '\n')
	}

	if true{
		print("13 ", true, '\n');
	}
	if false{
		print("14 ", false, '\n');
	}

	/* runes ands strings*/
	var char = '\\';
	var str = "String value \n \\ \t newline";
	str += " concat";
	print("15 ", char, str + " END", '\n');

	if str[2] == 'r'{
		print("16 ","str[2] == 'r'", '\n');
	}
}

func f(a int, b bool) bool{
	print("5 ", a, ' ',b, '\n');
	return true;
}