//Written by Scatter
//Here are the team list
string *member = ({
        "buwu",
        "scatter",
        "cheap",
        "charm",
        "hopeful",
        "yujie",        
        "snowlf", 
        "lisser",
        "kglv",
        "troy",
        "newbe", 
        "keny",
        "kissme",

});

int is_member(object me)
{
        int i;

        for(i=0; i<sizeof(member); i++)
                if ( me->query("id") == member[i] )     return 1;

        return 0;
}

