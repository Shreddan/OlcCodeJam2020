#define OLC_PGE_APPLICATION
#include "Engine.h"

int main()
{
    Engine engine;
    engine.Construct(1200, 800, 1, 1);
    engine.Start();
}
