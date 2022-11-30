#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "duration.hpp"

int Duration::getDuration()//returns private integer time to public
{
return time;//time is returned
}

Duration::Duration()//public constructor
{
    time=0;
    AlarmHasBeenSet=false;
}
Duration::Duration(int t)//public constructor which sets time t
{
    assert(t>=0);
    time=t;
    AlarmHasBeenSet=false;
}

bool Duration::tick()//adds 1 to time, doesn't return any value
{
    time++;//1 is added to time
    
    return checkAndUpdateAlarm();//Alarm is checked

}

bool Duration::tick(int dt)//adds input dt to time, doesn't return any value
{
    assert(dt>=0);//dt must be greater than or equal to zero
    time+=dt;//dt is added to time
    
    return checkAndUpdateAlarm();//alarm is checked and updated

}

void Duration::SetAlarm(int t)//Sets alarm and sets boolean AlarmHasBeenSet to true.
{
    assert(t>=time);//alarm can't be in the past therefor t must be greater than or equal to time.
    alarm=t;
    AlarmHasBeenSet=true;
}

bool Duration::checkAndUpdateAlarm(){ //checks if alarm has been set, and if so if time is equal to or greater than time.
    if(AlarmHasBeenSet==false){
        return false;
    }
    else if(time>=alarm){
        AlarmHasBeenSet = false;
        return true;
    }
    return false;
}


Duration::~Duration()//destructor
{
}