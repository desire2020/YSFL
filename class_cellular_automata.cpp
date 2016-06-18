#include "class_cellular_automata.hpp"
namespace YSFL
{
    vector<cellular_automata> all_cells;
    simulated_world universe_616;

	void cellular_automata :: operate(int x, int y, simulated_world & context)
	{

	}
	void simulated_world :: evolute()
	{
		
	}
    void simulated_world :: print(QGraphicsScene &targetScene, QGraphicsView &targetView)
    {

    }
    void simulated_world :: randomize()
    {

    }

	int& simulated_world :: operator()(int x, int y)
    {
        return state[x][y];
	}
}
