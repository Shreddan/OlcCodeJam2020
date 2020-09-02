#define OLC_PGE_APPLICATION
#include "Engine.h"

int main()
{
    Engine engine;
    engine.Construct(600, 400, 2, 2);
    engine.Start();
}
