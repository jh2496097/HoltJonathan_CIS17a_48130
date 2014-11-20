/**
 * Jonathan Holt
 * policeofficer implementation
 */
#include "policeofficer.h"
PoliceOfficer::PoliceOfficer(string n , string b){
    name = n;
    if (b.size() < 5)
        badgeNum = "INVALID";
    else
        badgeNum = b;
}
PoliceOfficer::PoliceOfficer(){
    name = "non";
    badgeNum = "non";
}
void PoliceOfficer::setName(string n){
    name = n;
}
void PoliceOfficer::setBadge(string b){
    if (b.size() < 5)
        badgeNum = "INVALID # 5 digits";
    else
        badgeNum = b;
}