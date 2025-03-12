char* longestCommonPrefix(char** strs, int strsSize) {
    char* common = strs[0];

    int common_last = strlen(common);

    for(int i = 1; i<strsSize; i++)
    {
        char* compare = strs[i];

        int common_current =0;
        int compare_current =0;

        while(common_current<common_last && compare_current <common_last)
        {
            if(common[common_current]==compare[compare_current])
            {
                common_current++;
                compare_current++;
            }else{
                if(common_last>common_current)
                    common_last = common_current;
                break;
            }

        }  
    }
    char* res = (char *)malloc(sizeof(char) * (common_last+1));
    strncpy(res,common,common_last);
    res[common_last]='\0';;
    return res;
}