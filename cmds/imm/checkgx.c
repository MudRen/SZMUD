void create()
{
        seteuid(getuid());
}


int main(object me, string arg)
{

        object ob; 
        string file;
        int chkvalue; 
        string outmsg; 
        
        file = "/log/awards/gxadd.c";

        if(arg == "" || !arg)
        {
        tail(file);
        return 1;
        }

        ob = find_player(arg);
	if ( !objectp( ob ) ) return notify_fail( "No such guy online.\n" );

    if( !this_player()->visible(ob) && (arg=="mariner" || arg == "buwu" ) )
		return notify_fail( "No such guy online.\n" );
        if(!ob->query("shenzhou/pts")) 
        { 
                write("这个玩家没有　神州 贡献度．\n"); 
                return 1; 
        } 

        chkvalue = ob->query("shenzhou/pts"); 
        outmsg = ob->name(1) + " 的 神州 贡献度为 " + chkvalue + " 点．\n"; 
        write(outmsg); 
        return 1; 
 

}

