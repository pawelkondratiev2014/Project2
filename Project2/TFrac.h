#ifndef TFrac_H
#define TFrac_H

class TFrac
{
private:
	int numerator;
	int denominator;
public:

	//����������� ��� ����� ����� �����
	TFrac(int m_numerator, int m_denumerator) : numerator(m_numerator), denominator(m_denumerator)
	{
		// ��������� ����������� �� ����
		assert(m_denumerator != 0 && "denominator=0");
		// �� ��������� ����� reduce() � �����������, ����� ���������, ��� ��� �����, ������� � ��� ����, ����� ���������
		reduce();
	};

	//����������� ��� ����� ����� ������
	TFrac(std::string string)
	{
		std::string m_numerator;
		std::string m_denominator;

		int znak(1);
		if (string[0] == '-')
		{
			int i = 1;
			for (i; i < string.length(); i++)
			{
				if (string[i] == '0' || string[i] == '1' || string[i] == '2' || string[i] == '3' || string[i] == '4' || string[i] == '5' || string[i] == '6' || string[i] == '7' || string[i] == '8' || string[i] == '9')
					m_numerator = m_numerator + string[i];
				else break;
			};

			i++;
			for (i; i < string.length(); i++)
			{
				if (string[i] == '0' || string[i] == '1' || string[i] == '2' || string[i] == '3' || string[i] == '4' || string[i] == '5' || string[i] == '6' || string[i] == '7' || string[i] == '8' || string[i] == '9')
					m_denominator = m_denominator + string[i];
				else break;
			};
			znak = -1;
		}

		else
		{
			int i = 0;
			for (i; i < string.length(); i++)
			{
				if (string[i] == '0' || string[i] == '1' || string[i] == '2' || string[i] == '3' || string[i] == '4' || string[i] == '5' || string[i] == '6' || string[i] == '7' || string[i] == '8' || string[i] == '9')
					m_numerator = m_numerator + string[i];
				else break;
			};

			i++;
			for (i; i < string.length(); i++)
			{
				if (string[i] == '0' || string[i] == '1' || string[i] == '2' || string[i] == '3' || string[i] == '4' || string[i] == '5' || string[i] == '6' || string[i] == '7' || string[i] == '8' || string[i] == '9')
					m_denominator = m_denominator + string[i];
				else break;
			};
		};

		numerator = std::stoi(m_numerator) * znak;
		denominator = std::stoi(m_denominator);
		// ��������� ����������� �� ����
		assert(denominator != 0 && "denominator=0");

		// �� ��������� ����� reduce() � �����������, ����� ���������, ��� ��� �����, ������� � ��� ����, ����� ���������
		reduce();
	};

	// ����������� �����������
	TFrac(const TFrac& d) :
		numerator(d.numerator), denominator(d.denominator)
	{
	};

	// ������ ������� nod() �����������, ����� ��� ����� ���� ������ ������ TFrac �, ��� ����, ��� � ������������� ��� �� ����� ���� �� ��������� ������ ������ TFrac
	static int nod(int a, int b)
	{
		return (b == 0) ? (a > 0 ? a : -a) : nod(b, a % b);
	};

	void reduce()
	{
		int nod = TFrac::nod(numerator, denominator);
		numerator /= nod;
		denominator /= nod;
	};

	TFrac& addition(TFrac& d) //��������
	{
		numerator = numerator * d.denominator + d.numerator * denominator;
		denominator = denominator * d.denominator;
		reduce();
		return *this;
	};

	TFrac& subtraction(TFrac& d) //���������
	{
		numerator = numerator * d.denominator - d.numerator * denominator;
		denominator = denominator * d.denominator;
		reduce();
		return *this;
	};

	TFrac& multiplication(TFrac& d) //���������
	{
		numerator = numerator * d.numerator;
		denominator = denominator * d.denominator;
		reduce();
		return *this;
	};

	TFrac& division(TFrac& d) //�������
	{
		numerator = numerator * d.denominator;
		denominator = d.numerator * denominator;
		reduce();
		return *this;
	};

	TFrac& square() //�������
	{
		numerator = numerator * numerator;
		denominator = denominator * denominator;
		reduce();
		return *this;
	};

	TFrac& back() //��������
	{
		int temp = numerator;
		numerator = denominator;
		denominator = temp;
		reduce();
		return *this;
	};

	TFrac& minus() //�����
	{
		numerator = numerator * (-1);
		reduce();
		return *this;
	};

	bool equals(TFrac& d) //��������� "="
	{
		return (numerator == d.numerator) && (denominator == d.denominator);
	};

	bool larger(TFrac& d) //��������� ">"
	{
		return (numerator * d.denominator) > (d.numerator * denominator);
	};

	std::string getStringDrob() //���������� ����� � ������� string
	{
		return (std::to_string(numerator) + "/" + std::to_string(denominator));
	};

	std::string getStringNumerator() //���������� ��������� � string
	{
		return std::to_string(numerator);
	};

	std::string getStringDenominator() //���������� ��������� � string
	{
		return std::to_string(denominator);
	};

	int getIntNumerator() //���������� ��������� � int
	{
		return numerator;
	};

	int getIntDenominator() //���������� ��������� � int
	{
		return denominator;
	};

	friend bool operator> (const TFrac& d1, const TFrac& d2);
	friend bool operator< (const TFrac& d1, const TFrac& d2);

	friend std::ostream& operator<< (std::ostream& out, const TFrac& d);
	friend TFrac operator+(const TFrac& d1, const TFrac& d2);
};


#endif