#include <iostream>

void fill_array_manually(int*, int);
long sum(const int*, int);
double average(const int*, int);
long sum_negative(const int*, int);
long sum_positive(const int*, int);
long sum_odd_indices(const int*, int);
long sum_even_indices(const int*, int);
void get_indices_min_max(const int*, int, int&, int&);
long multiplication_between_max_min(const int*, int);
void sort(int* array, int size, bool(*)(int, int));
void show_array(const int*, int);

bool is_greater(int a, int b)
{
	return a > b;
}

int main()
{
	const int n = 10;
	int mas[n];
	fill_array_manually(mas, n);
	int s = sum(mas, n);
	std::cout << s << std::endl;
	double a = average(mas, n);
	std::cout << a << std::endl;
	long ss = sum_negative(mas, n);
	std::cout << ss << std::endl;
	ss = sum_positive(mas, n);
	std::cout << ss << std::endl;
	ss = sum_odd_indices(mas, n);
	std::cout << ss << std::endl;
	ss = sum_even_indices(mas, n);
	std::cout << ss << std::endl;
	int min, max;
	get_indices_min_max(mas, n, min, max);
	std::cout << "min value index: " << min << std::endl;
	std::cout << "max value index: " << max << std::endl;
	ss = multiplication_between_max_min(mas, n);
	std::cout << ss << std::endl;
	sort(mas, n, is_greater);
	show_array(mas, n);
	return 0;
}

void fill_array_manually(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "mas[" << i << "]=";
		std::cin >> array[i];
	}
}

long sum(const int* array, int size)
{
	long result = 0;
	for (int i = 0; i < size; i++)
	{
		result += array[i];
	}
	return result;
}

double average(const int* array, int size)
{
	long result = sum(array, size);
	return result / size;
}

long sum_negative(const int* array, int size)
{
	long result = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] < 0)
		{
			result += array[i];
		}
	}
	return result;
}

long sum_positive(const int* array, int size)
{
	long result = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] > 0)
		{
			result += array[i];
		}
	}
	return result;
}

long sum_odd_indices(const int* array, int size)
{
	long result = 0;
	for (int i = 0; i < size; i++)
	{
		if (i % 2 != 0)
		{
			result += array[i];
		}
	}
	return result;
}

long sum_even_indices(const int* array, int size)
{
	long result = 0;
	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0)
		{
			result += array[i];
		}
	}
	return result;
}

void get_indices_min_max(const int* array, int size, int& min, int& max)
{
	int minValue = *array, maxValue = *array;
	for (int i = 0; i < size; i++)
	{
		if (minValue > array[i])
		{
			minValue = array[i];
			min = i;
		}
		if (maxValue < array[i])
		{
			maxValue = array[i];
			max = i;
		}
	}
}

long multiplication_between_max_min(const int* array, int size)
{
	int min, max;
	get_indices_min_max(array, size, min, max);
	int start = min > max ? max : min;
	int end = min > max ? min : max;
	long result = 0;
	for (int i = start + 1; i < end; i++)
	{
		result += array[i];
	}
	return result;
}

void sort(int* array, int size, bool (*functor)(int,int))
{
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if ((*functor)(array[j], array[j + 1]))
			{
				std::swap(array[j], array[j + 1]);
			}
		}
	}
}

void show_array(const int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << '\t';
	}
}