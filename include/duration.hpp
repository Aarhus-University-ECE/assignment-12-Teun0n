#ifdef _DURATION_H_
#define _DURATION_H_
#include <stdbool.h>

class duration
{
    private:
        int time;
        
    public:
        Duration();//constructur
        Duration(int t);//constructur where time=t
        ~Duration();//deconstructer
        getDuration();//returns time
};
#endif //duration_h