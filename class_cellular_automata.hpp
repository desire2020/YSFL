#ifndef CLASS_CELLULAR_AUTOMATA
#define CLASS_CELLULAR_AUTOMATA
#include <string>
#include <vector>
using std :: string;
using std :: vector;
namespace YSFL
{
	const int world_size = 100;
    class simulated_world;
    class cellular_automata;
    extern vector<cellular_automata> all_cells;
	class cellular_automata
	{
	protected:
		string DNA;
	public:
		cellular_automata(const string & src) : DNA(src) {}
		void operate(int x, int y, simulated_world & context);
	};
	class simulated_world
	{
	friend class cellular_automata;
	protected:
		int state[world_size][world_size];// 0 for dead 1 for alive(type 1)
		int succ_state[world_size][world_size];
	public:
		void evolute();
		int& operator()(int x, int y);
	};
}

#endif
