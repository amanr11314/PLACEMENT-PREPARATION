//log(n) complexity
long fastpow(int a, int b) {
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return fastpow(a * a, b / 2);
    return a * fastpow(a, b - 1);
}