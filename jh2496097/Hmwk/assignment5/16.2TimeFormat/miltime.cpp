
//implementation of miltime class
#include "miltime.h"

MilTime::MilTime(int s, int m, int h, int mm, int mh){
    Time(s, m, h);
    milMins = mm;
    milHours = mh;
}
void MilTime::setTime(int s, int m, int h, int mm, int mh){
    if (s <0||s>59)
        throw BadSeconds();
    else
        setSec (s);
    if (m<0||m>59)
        throw BadSeconds();
    else
        setMin (m);
    if (h<0||h>2359)
        throw BadHours();
    else
        setHour (h);
    
    milMins = mm;
    milHours = mh;
}