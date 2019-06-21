#include<fstream>
#include<iostream>

int main()
{
	unsigned steps = 400;
	unsigned precision = 2100;
	int symbol_count = 0;
	int space_count = 0;
	std::ofstream PWM;
	PWM.open("PWM_Values.txt", std::ios::out);
	if (!PWM.is_open())
	{
		std::cerr << "file not could be opened";
		exit(1);
	}
	for (size_t i = 0; i < steps; ++i)
	{
		int value = (int)(i*precision / steps);

		if (value < 10)
			symbol_count += 1;
		else if (value >= 10 && value < 100)
			symbol_count += 2;
		else if (value >= 100 && value < 1000)
			symbol_count += 3;
		else
			symbol_count += 4;

		PWM << value << " ";
		space_count++;
	}
	PWM << 'L';
	PWM.close();
	symbol_count += space_count;
	std::cout << "Total of symbols: " << symbol_count << std::endl;
}