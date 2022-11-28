#ifdef _DURATION_H_
#define _DURATION_H_

class duration
{
    private:
        int time;
    public:
        Duration();//constructur
        Duration(int t);//constructur where time=t
        ~Duration();//deconstructer
        getDuration();//returns time
        SetAlarm(int t);
};
#endif //duration_h