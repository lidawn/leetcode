int addDigits(int num) {
    if(num==0)return 0;
    return num - 9*((int)(num-1)/9);
}