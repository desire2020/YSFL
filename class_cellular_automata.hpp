#ifndef CLASS_CELLULAR_AUTOMATA
#define CLASS_CELLULAR_AUTOMATA
#include <string>
#include <vector>
#include <unordered_map>
#include <QGraphicsView>
using std :: string;
using std :: vector;
using std :: unordered_map;
namespace YSFL
{
	const int world_size = 100;
    class simulated_world;
    class cellular_automata;
    extern vector<cellular_automata> all_cells;
    extern simulated_world universe_616; //I'm a super Marvel fan! :)
    extern unordered_map<string, int> dict;
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
		int state[2][world_size][world_size];// 0 for dead 1 for alive(type 1)
		int current_state_index;
	public:
		void evolute();
        void print(QGraphicsScene & targetScene, QGraphicsView & targetView);
        void randomize();
		int& operator()(int x, int y);
	};
}

#endif
