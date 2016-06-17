#include "class_cellular_automata.hpp"
namespace YSFL
{
    vector<cellular_automata> all_cells;
	void cellular_automata :: operate(int x, int y, simulated_world & context)
	{
        x = y = 0;
        context.state[0][0] = 0;
        if (x == 1) x = 1;
	}
	void simulated_world :: evolute()
	{
		
	}
	int& simulated_world :: operator()(int x, int y)
    {
        return state[x][y];
	}
}
