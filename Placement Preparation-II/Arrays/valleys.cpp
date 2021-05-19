int countingValleys(int steps, string path)
{
    int vc = 0;

    int pos = 0;
    bool belowSeaLevel = 0;

    for (char s : path)
    {
        int lpos = pos;

        if (s == 'U')
            pos++;
        else if (s == 'D')
            pos--;
        //entering valley
        if (lpos == 0 && s == 'D')
        {
            belowSeaLevel = true;
        }
        //left valley and reached
        else if (belowSeaLevel && pos == 0)
        {
            vc++;
            belowSeaLevel = false;
        }
    }

    return vc;
}