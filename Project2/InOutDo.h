#ifndef InOutDo_H
#define InOutDo_H


class InOutDo
{
private:
	TFrac myfun(TFrac x, TFrac y)
	{
		return x + y;
	};

public:
	static void Input(std::list<TFrac> &m)
	{
		std::string s;
		char h;
		while (1)
		{
			std::cout << "������� ������� ������(x/y) ";
			std::cin >> s;
			m.push_back(TFrac(s));
			std::cout<<'\n' << "���������� ����(y/n) ";
			std::cin >> h;
			if (h != 'y')
				break;
		};
	};

	static void Output(std::list<TFrac> &m)
	{
		std::list<TFrac>::const_iterator it;
		it = m.begin();
		while (it != m.end()) // ���� �������� �� ��������� ���������� ��������
		{
			std::cout << *it << ' '; // ������� �������� ��������, �� ������� ��������� ��������
			++it; // � ��������� � ���������� ��������
		};
		std::cout << '\n';
	};



	static TFrac Sum(std::list<TFrac>& m)
	{
		//std::list<TFrac>::const_iterator it;
		//it = m.begin();
		//TFrac sum(*it);
		//++it;

		//while (it != m.end()) // ���� �������� �� ��������� ���������� ��������
		//{
		//	sum= sum+(*it);
		//	++it; // � ��������� � ���������� ��������
		//};

		std::list<TFrac>::const_iterator it;	
		it = m.begin();
		TFrac sum(0);

		sum=std::accumulate(m.begin(), m.end(), sum, std::plus<TFrac>());

		return sum;
	};

	static void SortUp(std::list<TFrac>& m)
	{
		m.sort();		
	};

	static void SortDown(std::list<TFrac>& m)
	{
		m.sort();
		m.reverse();
	};
};




#endif
