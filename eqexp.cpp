// Assignment #0, CPSC 1160
// This program reads from a file and formats the numbers into math expressions.
// It then expands and simplifies those expressions and prints them onto the console. 
// by Felipe Prudencio

#include <iostream>
#include <fstream>
#include <string>

// Function that takes the number values of the expressions and does the expanding and simplification.
// string function, takes four integer parameters and returns a string
std::string expressionExpand(int a, int b, int c, int d){
	//The expanded form of the equation (ax+by)(cx+dy) would equal (a*c)x2+(a*d+b*c)*xy+(b*d)y2.
	//Int variables will store calculations for the expansions
	// 'aTc' stands for var a Times var c (a*c).
	int aTc, aTd, bTc, bTd;
	// String variable that will be returned by the function with end expression. 'eq' stands for equation
	std::string eq = "";
	
	//Calculation of the expansion and variable assignments.
	aTc = a * c;
	aTd = a * d;
	bTc = b * c;
	bTd = b * d;


	//Check if any value is 1,0 or -1 for correct formating of string expression.
	if (aTc == 1 || aTc == 0 || aTc == -1){
		if (aTc == -1)
		{
			eq = "-x^2";
			if (bTd > 0)
			{
				eq += "+";
			}
		}else{
			eq = "";
		}
		if (aTc == 1)
		{
			eq = "x^2";
		}
		
	}else{
		//Int are converted to string and assigend to eq variable.
		eq = std::to_string(aTc);
		if((aTd + bTc) >= 0){
			eq += "x^2+";
		}else{
			eq += "x^2";
		}
	}

	if ((aTd + bTc) == 1 || (aTd + bTc) == 0){
		eq += "";
	}else{
		eq += std::to_string((aTd + bTc));
		if (bTd > 0){
			eq += "xy+";
		}else{
			eq += "xy";
		}
	}
	
	if (bTd == 1 || bTd == 0 || bTd == -1){
		if (bTd == -1)
		{
			eq += "-y^2";
		}else{
			eq += "";
		}
		if (bTd == 1)
		{
			eq += "y^2";
		}
		
	}else{
		eq += std::to_string(bTd);
		eq += "y^2";
	}
	
	if (eq == "")
	{
		eq += "0";
	}

	//Returns eq string
	return eq;
}

int main()
{
	int a,b,c,d;
	std::ifstream fin;
	std::string signX, signY;
	// MacOS may need to use an absolute path
	//fin.open("/Users/felps/Documents/Langara/Term 6/CPSC 1160/A1/EqTest.txt");// MacOs may not support a relative path
	//Windows
	fin.open("EqTest.txt");

	if (fin.is_open())
	{
		while ( !fin.eof() )
		{
			fin >> a >> b >> c >> d;
			//Checks for correct sign and assigns it to variable
			if (b >= 0){
				signX = "x+";
			}else{
				signX = "x";
			}
			if (d >= 0){
				signY = "x+";
			}else{
				signY = "x";
			}
			
			//Prints numbers read from file and formats it into expression.
			std::cout <<"(" << a << signX << b<< "y)" << "(" << c << signY << d << "y)" << std::endl;
			
			// Calls function with int read from file and prints expanded expression to console.
			std::cout <<"Expanded expression is: " << expressionExpand(a,b,c,d)<< std::endl;
		}

	}
	fin.close();

	


	return 0;
}


