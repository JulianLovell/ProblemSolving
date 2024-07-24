//for i = 0; i + rest; i <= branch
//if place > branch return leafEaten
//else if place / leaf = 0 -> leafEaten++

using namespace std;
 
class Inchworm
{
  public:
  int lunchtime(int branch, int rest, int leaf)
  {
    //set variables
    int leafEaten = 1;
    int place = 0;

    //for loop to do everything
    for (int i = 0; i <= branch; i + rest){
        //check if passed end of branch
        if (place > branch){
            return leafEaten;
        }

        //check if rest landed on leaf
        else if (place / leaf == 0){
            leafEaten++;
        }
    }
    //return
    return leafEaten;
  }
};