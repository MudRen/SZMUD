// ◎【神州】◎
// Yujie Sep 30

inherit F_CLEAN_UP;
#include <ansi.h>

int help();

int main(object me, string arg)
{
	string *msg_a, id,name, msg;
	int i;

	if( !arg || arg=="" ){
                msg = TOPTEN_D->query_top("",TOP_ID_NAMES);
		
                if( msg =="" ) return notify_fail("现在还没有排行榜.\n");
		
                msg_a = explode(msg,";");
		write(HIW"现在有如下排行榜:\n───────────────────────\n"NOR);
		for(i=0; i< sizeof(msg_a); i++)
                        if(sscanf(msg_a[i],"%s(%s)",id,name)==2)
                                write(HIW"top "+id+NOR"    \t\t"HIG"百大"+
                                name+"排行榜"HIW"\n───────────────────────\n"NOR);
		return 1;
	}
	
	if( (msg =TOPTEN_D->topten_query(arg)) == "")
		return notify_fail("没有这种排行榜.\n");
	write(msg);
	return 1;
	
}

int help()
{
	write("\n指令格式 : top <类型>\n巫师参考指令 tset tban topen tclose \n");
	
	return 1;
}
