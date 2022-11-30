#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "duration.hpp"


// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Add your test cases. Dont forget to include header file. 

TEST_CASE("GetDuration"){ //tests public method duration

    Duration t1;
    Duration t2 = Duration(2);
    Duration t3 = Duration(4);

    REQUIRE(t1.getDuration()==0);
    REQUIRE(t2.getDuration()==2);
    REQUIRE(t3.getDuration()==4);
}

TEST_CASE("tick"){//tests public method tick

    Duration t1;
    Duration t2 = Duration(1);
    Duration t3 = Duration(10);

    t1.tick();
    t2.tick(9);
    t3.tick(20);

    REQUIRE(t1.getDuration()==1);
    REQUIRE(t2.getDuration()==10);
    REQUIRE(t3.getDuration()==30);
}

TEST_CASE("Alarm"){//tests public method Alarm

    Duration t1;
    Duration t2 = Duration(5);
    Duration t3 = Duration(10);

    t1.SetAlarm(3);//alarm=3

    REQUIRE(t1.tick()==false);//time=0+1=1
    REQUIRE(t1.tick(2)==true);//time=1+2=3=alarm
    REQUIRE(t1.tick(5)==false);//time=3+5=8

    t2.SetAlarm(10);//alarm=10

    REQUIRE(t2.tick()==false);//time=5+1=6
    REQUIRE(t2.tick(2)==false);//time=6+2=8
    REQUIRE(t2.tick(2)==true);//time=8+2=10

    t3.SetAlarm(20);//alarm=20

    REQUIRE(t3.tick(0)==false);//time=10+0=0
    REQUIRE(t3.tick(10)==true);//time=10+10=20
    REQUIRE(t3.tick()==false);//time=20+1=21
}
