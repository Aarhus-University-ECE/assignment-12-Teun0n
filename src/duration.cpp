#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "duration.hpp"

int Duration::getDuration()//returns private integer time to public
{
return time;
}

void Duration::Duration()//public constructor
{
    time=0;
}

void Duration::Duration(int t)//public constructor which sets time t
{
    assert(t>=0);
    time=t;
    t=0;
}

bool Duration::tick()//adds 1 to time, doesn't return any value
{
    time++;
    if(time<=t){
        return true;
        t=0;
        AlarmHasBeenSet=False;
    }
    else{
        return false;
    }
}

void Duration::tick(int dt)//adds input dt to time, doesn't return any value
{
    assert(t>=0);
    time+=dt;
}

void Duration::SetAlarm(int t)//Sets alarm
{
    assert(t>=time);

    bool AlarmHasBeenSet=true;
}
