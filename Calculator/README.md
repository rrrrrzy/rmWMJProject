# Calculator Using and Coding Explanation

made by *rrrrrzy*, my Ubuntu hasn't install Chinese input tool, thus the passage is in English. 

## Write in front : ==How to use it== ?

​	The calculator can be used in a very simple way : 

​		input `num1 operator num2` (space bar is must)then press Enter, results will quickly arise ! 

​		or press `num1` + `Enter` + `operator` + `Enter` + `num2` + `Enter`

​		Anyway you like is fine !

## 	First : Why we produce it ?

​		Universally acknowledged that in C++, we have type of `int` , `char` , `long` , `long long`, etc, to save numbers. However , the longest one `unsigned long long` is only stored in 8 bite(64 bit), and thus can only store max number $$2^{64}-1$$ . If we want to calculate larger numbers , it doesn't work. Therefore, we need a calculator to deal large one. And this calculator faces the world!

##  	Second : How does it worked ?

​		The most smart species in this planet is human. So when Computer way cannot work, why not try to imitate Human way? 

​		So, I use `vector` to contain the inputed number, make it back to take the unit more easily. Then add or minus each unit, judge the result to set the carry bit(another variable). Next to deal the latter unit with carry bit ... until the min number's unit has run over. And, we just need to lay the max number's rest unit to the result. There are some code explanation below.

##### 1. plus

```c++
Num operator+(Num m) {
		int n = 0;
		Num temp1;
		setA1();//A function to set variable A1,which stores arr.size()
		daoZhi1();// A function used to lay backward the vector
		m.setA1();// set parameter's A1 & lay backward its vector
		m.daoZhi1();
		int A2 = min(A1, m.A1);//We need to find whose length is shorter
		for (int i = 0; i < A2; i++) {
			int temp = _arr[i] + m._arr[i] + n;
			if (temp > 9) {
                //temp > 9 means we should plus 1 to next unit
                //and the rest is temp % 10 (temp max 18)
				temp1._arr.push_back(temp % 10); 
				n = 1;//means carry bit is 1
			}
			else {
                //if temp <= 9 , we just need to store it.
				temp1._arr.push_back(temp);
				n = 0;//no need to carry bits
			}
		}
    	//when the shorter one has run over, we need to move longer one's rest
    	//unit, but pay attension to carry bits!
		for (int i = A2; i < A1; i++) {
			int temp;
			if (A1 > m.A1)
				temp = _arr[i] + n;
			else
				temp = m._arr[i] + n;

			if (temp > 9) {
				temp1._arr.push_back(temp % 10);
				n = 1;
			}
			else {
				temp1._arr.push_back(temp);
				n = 0;
			}
		}
		temp1._arr.push_back(n);
		temp1.daoZhi2();
    	//use copy constructor to build a new case
		return temp1;
	}
```

##### 2. minus

```c++
Num operator-(Num m) {
      //we use judge sentence to assure the former num is always
      //larger than or same large with the latter one while input
		int n = 0;
		Num temp1;
		setA1();	//just as plus function
		daoZhi1();
		m.setA1();
		m.daoZhi1();
		int A2 = min(A1, m.A1);
		for (int i = 0; i < A2; i++) {
			int temp = _arr[i] - m._arr[i] - n;	//a little different
			if (temp < 0) {
               //temp < 0 means we need to minus 1 in next unit
               //attention! negative numb % 10 gets negative num
				temp1._arr.push_back(-1 * (temp % 10));
				n = 1;	//next unit will minus n
			}
			else {
                //just store it!
				temp1._arr.push_back(temp);
				n = 0;
			}
		}
    	//same as
		for (int i = A2; i < A1; i++) {
			int temp;
			if (A1 > m.A1)
				temp = _arr[i] - n;
			else
				temp = m._arr[i] - n;

			if (temp < 0) {
				temp1._arr.push_back(-1 * (temp % 10));
				n = 1;
			}
			else {
				temp1._arr.push_back(temp);
				n = 0;
			}
		}
		temp1._arr.push_back(n);
		temp1.daoZhi2();
		return temp1;
	}
```

##### 3. lay vectors backward

```c++
	//we set two function, one is to initialise the vector
	//the other is to get the result without 0 in front
	void daoZhi1() {
		for (int i = 0; i < A1; i++) {
			_arr.push_back(arr[A1 - 1 - i]);
		}
	}

	void daoZhi2() {
		while (_arr.size() > 1 && _arr[_arr.size() - 1] == 0) {
			_arr.pop_back();//delete 0
		}
        //lay result backward
		for (int i = 0; i < _arr.size(); i++) {
			arr.push_back(_arr[_arr.size() - 1 - i]);
		}
	}
```

##### ...

## End : 

​	For time limits, the calculator hasn't been done with only plus and minus. But the update will surely get meet with us ! 

​	If you have some problems or some tips, please email me on rzy1282950305@163.com 