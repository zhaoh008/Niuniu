#include "Niuniu.h"

class SandBox:public Niuniu::Application
{
public:
	SandBox();
	~SandBox();

};

SandBox::SandBox()
{
}

SandBox::~SandBox()
{
}

Niuniu::Application* Niuniu::CreateApplication() {
	return new SandBox;
}