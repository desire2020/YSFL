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
	
    
	void cellular_automata :: operate(int x, int y, simulated_world & world, int &len)
	{
		switch (getword(all_cells[state[current_state_index][x][y])
	}
	
	void simulated_world :: evolve()
	{
		for (int i = 0; i < world_size; i++)
			for (int j = 0; j < world_size; j++)
				all_cells[state[current_state_index][i][j]].operate(i, j, *this);
		current_state_index = 1 - current_state_index;
	}
	
    void simulated_world :: print(QGraphicsView &target)
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
