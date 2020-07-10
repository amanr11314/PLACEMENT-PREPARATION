//To check if second string is rotation of first string.
bool isRotation(string a,string b){
    //if strings are unequal in length return false
    if(a.length()!=b.length())  return false;

    //append a to itself
    a.append(a.c_str());
    //now a contains all possible rotations of itelf
    //just check whether b is in the a or not
    return    (a.find(b)!=string::npos);
}