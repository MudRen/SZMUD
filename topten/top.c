// 神话世界·西游记２０００　WUHEE WIZ.GROUP
// misu

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
	string *msg_a, id,name, msg;
	int i;

	if( !arg || arg=="" ){
                msg = TOPTEN_D->query_top("",TOP_ID_NAMES);
		
                if( msg =="" ) return notify_fail("现在还没有排行榜.\n");
		
                msg_a = explode(msg,";");
		write("现在有如下排行榜:\n");
		for(i=0; i< sizeof(msg_a); i++)
                        if(sscanf(msg_a[i],"%s(%s)",id,name)==2)
                        	write("topten "+id+"\t\t西游记TOP TEN十大"+
                                name+"排行榜\n");
		return 1;
	}
	
	if( (msg =TOPTEN_D->topten_query(arg)) == "")
		return notify_fail("没有这种排行榜.\n");
	write(msg);
	return 1;
	
}

int help()
{
	write("\n指令格式 : topten <类型> <玩家ID>\n");
	
	return 1;
}
