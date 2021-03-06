/*
Implementati clasa Cantar. Un cantar are o
capacitate maxima admisa. Daca se încearca
cantarirea unui obiect ce depaseste cu maxim 10%
greutatea maxim? admis? se va genera excep?ia
AvertismentDepasireGreutate iar daca se depasete
si acesta limita se va genera eroarea
DepasireGreutate.
*/
#include "stdafx.h"
#include <iostream>
using namespace std;


struct AvertismentDepasireGreutate : public exception
{
	const char * what() const throw ()
	{
		return "Error:AvertismentDepasireGreutate";
	}
};

struct DepasireGreutate : public exception
{
	const char * what() const throw ()
	{
		return "Error:DepasireGreutate";
	}
};

class Cantar
{
private:
	double capMax;

public:
	Cantar(double capMax = 0)
	{
		this->capMax = capMax;
	}

	void set_capMax(double capMax)
	{
		this->capMax = capMax;
	}

	double get_capMax()
	{
		return capMax;
	}

	void cantarire(double obiect)
	{
		if (obiect > capMax && obiect <= capMax + (capMax * 10 / 100))
			throw AvertismentDepasireGreutate();
		else
			if (obiect > capMax + (capMax * 10 / 100))
				throw DepasireGreutate();
		cout << "Greutate admisa" << endl;
	}

};





int main()
{
	Cantar cantar;
	double capMaxCant, grObiect;

	cout << "Introduceti capacitatea maxima admisa a cantarului: ";
	cin >> capMaxCant;
	cantar.set_capMax(capMaxCant);

	cout << "Introduceti greutatea obiectului: ";
	cin >> grObiect;

	try
	{
		cantar.cantarire(grObiect);
	}
	catch (AvertismentDepasireGreutate& e)
	{
		cout << e.what() << endl;
	}
	catch (DepasireGreutate& err)
	{
		cout << err.what() << endl;
	}

    return 0;
}

