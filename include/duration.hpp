#ifndef DURATION_H
#define DURATION_H

class Duration
{
    private:
        int time;
        int alarm;
        bool AlarmHasBeenSet;
    public:
        Duration();//constructur
        Duration(int t);//constructur where time=t
        ~Duration();//deconstructer

        int getDuration();//returns time

        void SetAlarm(int t);//sets alarm
        bool checkAndUpdateAlarm();

        bool tick();
        bool tick(int dt);
};
#endif //duration_h