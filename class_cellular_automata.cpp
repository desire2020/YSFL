#include "class_cellular_automata.hpp"
namespace YSFL
{
    vector<cellular_automata> all_cells;
    simulated_world universe_616;
    unordered_map<string, int> dict;
	int getword(string &str, int &pos) {}
	
	int voidif() {return -1;}
	int boolequals() {}
	int intdetect() {}
	int voidborn() {}
	int boiddie() {}
	int voidstill() {}
	
    
	int cellular_automata :: operate(int &x, int &y, simulated_world & world, int &len, int flag)
	{
		switch (getword(all_cells[state[current_state_index][x][y]].DNA) {
			case 11: {
				switch (operate(x, y, world, len, 0)) {
					case -2:case -1: return -2;
					case 0:
						if (operate(x, y, world, len, 0) == -1 && operate(x, y, world, len, 1) == -1) return -1;
						return -2;
					default:
						if (operate(x, y, world, len, 1) == -1 && operate(x, y, world, len, 0) == -1) return -1;
						return -2;
				}
			}
			case 12: {
				int tmp1 = operate(x, y, world, len, 0);
				int tmp2 = operate(x, y, world, len, 0);
				if (tmp1 >= 0 && tmp2 >= 0) return (tmp1 == tmp2);
				return -2;
			}
			case 13: {
				
			}
			break;
		}
	}
	
	void simulated_world :: evolve()
	{
		for (int i = 0; i < world_size; i++)
        for (int j = 0; j < world_size; j++)
        {
            int x = 0;
            all_cells[state[current_state_index][i][j]].operate(i, j, *this, x);
        }
		current_state_index = 1 - current_state_index;
	}
	
    void simulated_world :: print(QGraphicsScene & target_scene, QGraphicsView &target_view)
    {
		
    }
    
    void simulated_world :: randomize()
    {
		for (int i = 0; i < world_size; i++)
			for (int j = 0; j < world_size; j++)
				state[0][i][j] = rand() % 2;
		current_state_index = 0;
    }

	int& simulated_world :: operator()(int x, int y)
    {
        return state[current_state_index][x][y];
	}
}
