//to check if string is pallindrome or not
bool isPallindrome(string s) {
    if (s.size() <= 1)
        return true;
    char b = s.front();
    char e = s.back();
    //compare first and last char of string
    cout << "Comparing " << b << "\tand\t" << e << endl;
    //remaining string between first and last char of string
    string t = s.substr(1, s.size() - 2);
    return (b == e) && isPallindrome(t);
}
