#include <Helios.h>

class Ceres : public Helios::Application
{
public:
	Ceres()	{}

	~Ceres() {}
};

Helios::Application* Helios::CreateApplication()
{
	return new Ceres();
}