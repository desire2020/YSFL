#include "class_cellular_automata.hpp"
#include <QMessageBox>
#include "identity.h"

namespace YSFL
{
    vector<cellular_automata> all_cells;
    simulated_world universe_616;
    unordered_map<string, int> dict;
    QGraphicsScene *DisplayScene;
    QGraphicsView *DisplayView;
    const int Mutate_rate = 10000; 
    const int maxsize = 100000; 
    const int maxlength = 100;

	int intdetect(int x, int y, int view) {
      //  QMessageBox::about(NULL, "", "detect");
		if (view > 10) view = 10;
        int i0 = x - view, j0 = y - view;
        if (i0 < 0) i0 = 0;
        if (j0 < 0) j0 = 0;
		int count = 0;
        for (int i = i0; i <= x + view && i < world_size; ++i)
            for (int j = j0; j <= y + view && j < world_size; ++j)
                if (universe_616(i, j) > 0) ++count;
        count -= int(universe_616(x, y) > 0);
		return count;
	}
	
	void Change_To_Next(char &c){
		if (c == 'A') c = 'C';
		else if (c == 'C') c = 'G';
		else if (c == 'G') c = 'T';
        else if(c == 'T') c = 'A';
	}
	
	void Mutate(int x, int y){

		if (all_cells.size() > maxsize) return;
		if (rand() % Mutate_rate != 0) return;
       // QMessageBox::about(NULL, "", "Mutation happens!");
		string DNA = all_cells[universe_616(x, y, 1)].DNA;
		int kind = rand() % 2;
		if (kind == 0){
			int place = rand() % DNA.length();
			int what = rand() % 4;
			for (int i = 0; i < what; ++i) Change_To_Next(DNA[place]);	
		}
		else {
			if (DNA.length() > maxlength) return;
			else DNA = DNA + DNA;
		}
		universe_616(x, y, 1) = all_cells.size();
		all_cells.push_back(cellular_automata(DNA));
	}
	
    void voidborn(int x, int y, int view = 1)
    {
       //QMessageBox::about(NULL, "", "born");
        if (universe_616(x, y) != 0)
        {
            universe_616(x, y, 1) = universe_616(x, y);
            return;
        }
		int sum = 0;
        int n = 0;
        int i0 = x - view, j0 = y - view;
        if (i0 < 0) i0 = 0;
        if (j0 < 0) j0 = 0;
        for (int i = i0; i <= x + view && i < world_size; ++i)
            for (int j = j0; j <= y + view && j < world_size; ++j)
                if (x == i && y == j) continue; else {
                    sum += universe_616(i, j);
                    n += int(universe_616(i, j) != 0);
                }
        universe_616(x, y, 1) = sum / n + 1 * int(sum % n != 0);
        Mutate(x, y);
	}
   
   int getword(string &s, int &pos){
      // QMessageBox::about(NULL, "", "getword");
     //  QMessageBox::about(NULL, "target", s.c_str());
       if (pos >= s.length())
           throw -1;
   		string ss (s, pos, 3);


        pos += 3;
     //   QMessageBox::about(NULL, "get", ss.c_str());
       // QMessageBox::about(NULL, "", (ss + " " + char(dict[ss] + '0')).c_str());
   		return dict[ss];
   }
   

	int cellular_automata :: operate(int x, int y, simulated_world & world, int &len, int flag)
	{
       // QMessageBox::about(NULL, "", "operate");
        int num;
        try {
        num = getword(all_cells[world.state[world.current_state_index][x][y]].DNA, len);
        } catch(...) {
            return -2;
        }

        //  QMessageBox::about(NULL, "", "getword end");
		switch (num) {
            case 0: {
              //  QMessageBox::about(NULL, "", "if");
				if (flag) {
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
				else{
					switch (operate(x, y, world, len, 0)) {
					case -2:case -1: return -2;
					case 0:
						if (operate(x, y, world, len, 0) == -1 && operate(x, y, world, len, 0) == -1) return -1;
						return -2;
					default:
						if (operate(x, y, world, len, 0) == -1 && operate(x, y, world, len, 0) == -1) return -1;
						return -2;
					}
				}
			}
            case 1: {
               // QMessageBox::about(NULL, "", "equals");
				if (flag) return -2;
				int tmp1 = operate(x, y, world, len, 0);
				int tmp2 = operate(x, y, world, len, 0);
				if (tmp1 >= 0 && tmp2 >= 0) return (tmp1 == tmp2);
				return -2;
			}
            case 2: {

				if (flag) return -2;
				int tmp = operate(x, y, world, len, 0);
				switch (tmp) {
					case -2:case -1:case 0: return -2;
					default:
						return intdetect(x, y, tmp);
				}
			}
            case 3: {

                if (flag) voidborn(x, y);
				return -1;
			}
            case 4: {

                if (flag) {
                  //  QMessageBox::about(NULL, "", "die");
                    world.state[1 - world.current_state_index][x][y] = 0;
                }
				return -1;
			}
            case 5: {

                if (flag) {
                    world.state[1 - world.current_state_index][x][y] = world.state[world.current_state_index][x][y];
                   // QMessageBox::about(NULL, "", "still");
                }
                return -1;
			}
			default:
				if (flag) return -2;
                return num - 5;
		}
	}

	void simulated_world :: evolve()
	{
      //  QMessageBox::about(NULL, "", "evolve");

		for (int i = 0; i < world_size; i++)
        for (int j = 0; j < world_size; j++)
        {
            int x = 0;
          //  QMessageBox::about(NULL, "", "operate");
            if (all_cells[state[current_state_index][i][j]].operate(i, j, *this, x, 1) == -2)
            {
                state[1 - current_state_index][i][j] = 0;
            }
        }
        memset(state[current_state_index], 0, sizeof(state[current_state_index]));
        current_state_index = 1 - current_state_index;
      //  QMessageBox::about(NULL, "", "print ready");
        print(*DisplayScene, *DisplayView);
	}
	
    void simulated_world :: print(QGraphicsScene & scene, QGraphicsView &view)
    {
        scene.clear();
       // scene.addRect(QRect(0, 0, 900, 900));
        for (int i = 0; i < world_size; ++i)
            for (int f = 0; f < world_size; ++f)
            {
                if (universe_616(i, f) < 0)
                    QMessageBox::about(NULL, "", "unknown error");
                if (universe_616(i, f) != 0){
                    double opacity = double ((rand() % 499) + 500) / 1000;
                  /*  Qt::GlobalColor color;
                    if (rand() % 2 == 0) color = Qt::blue;
                    else color = Qt::red;*/
                    YSFL::identity *a1;
                    if (universe_616(i, f) == 1)
                        a1 = new YSFL::identity(i * 9, f * 9);
                    else
                        a1 = new YSFL::identity(i * 9, f * 9, ":/sparkle.png");
                    a1->setOpacity(opacity);
                    scene.addItem(a1);
                }

                   //
            }
    }
    
    void simulated_world :: randomize()
    {
        for (int i = 0; i < world_size; i++)
            for (int j = 0; j < world_size; j++)
                state[0][i][j] = int(rand() % 2 == 1);
		current_state_index = 0;
        print(*DisplayScene, *DisplayView);
    }

    int& simulated_world :: operator()(int x, int y)
    {
        return state[current_state_index][x][y];
    }
    int& simulated_world :: operator()(int x, int y, int z)
    {
        if (z == 0) return state[current_state_index][x][y];
    	return state[1 - current_state_index][x][y];
	}
}
