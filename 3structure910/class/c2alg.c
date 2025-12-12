int binsearch(int list[], int searchnum, int left, int right) {
    int middle;
    while(left <= right)  {
        switch(CPMPARE(list[middle], searchnum)) {
            case -1:left =middle +1
                break;
            case 0 : return middle;
            case 1 : right = middle -1;
        }
    }
    return -1;
}