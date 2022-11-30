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
    time=0;//time starts at 0
    AlarmHasBeenSet=false;//no alarm has been set
}
Duration::Duration(int t)//public constructor which sets time t
{
    assert(t>=0);//time must start at a value equal to or greater than 0
    time=t;//time is set to t
    AlarmHasBeenSet=false;//no alarm has been set
}

bool Duration::tick()//adds 1 to time, then checks and updates possible alarm
{
    time++;//1 is added to time
    
    return checkAndUpdateAlarm();//alarm is checked

}

bool Duration::tick(int dt)//adds input dt to time,  then checks and updates possible alarm
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
    if(AlarmHasBeenSet==false){//checks if alarm has been set
        return false;//if not false is returned
    }
    else if(time>=alarm){//checks if alarm has been set, and if time is equal to or greater than alarm
        AlarmHasBeenSet = false;//if true alarm is reset
        return true;//and true is returned
    }
    return false;//if alarm has been set, but is greater than time false is returned.
}


Duration::~Duration()//destructor
{
}