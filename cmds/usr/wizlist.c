//Cracked by Kafei
// wizlist.c
// by rider 7-12-01

#include <ansi.h>
inherit F_CLEAN_UP;
string blank_string = "                                    ";
string tribar_graph(int a);
int main(object me, string arg)
{
	string *list, name, class1, class2, class3, class4;
	mapping wizstatus, renwus;
	object user;
	int a = 0, b = 0, c = 0;
	int i, j;

	write(MUD_NAME + "目前的巫师有：");

	renwus = SECURITY_D->query_wiz_renwu();
	list = keys(renwus);
	class1 = "";
	class2 = "";
	class3 = "";
	class4 = "";
	for( i=0; i<sizeof(list); i++)
	{
		j = strlen(renwus[list[i]]) - 1;
		if( !objectp(user=find_player(list[i])))
			name = WHT+list[i]+NOR;
		else if(user->query("env/invisibility"))
			name = HIY+list[i]+NOR;
		else name = HIG+list[i]+NOR;
		if( explode(renwus[list[i]],"\*")[0] == "GLB" )
		{
			a++;
			class1 += (a%2?"\n":"") + name +"("+YEL+explode(renwus[list[i]],"\*")[1]+NOR+")"+tribar_graph(j);
			}
		if( explode(renwus[list[i]],"\*")[0] == "KFB" )
		{
			b++;
			class2 += (b%2?"\n":"") + name +"("+YEL+explode(renwus[list[i]],"\*")[1]+NOR+")"+tribar_graph(j);
			}			
		if( explode(renwus[list[i]],"\*")[0] == "SWB" )
		{
			c++;
			class3 += (c%2?"\n":"") + name +"("+YEL+explode(renwus[list[i]],"\*")[1]+NOR+")"+tribar_graph(j);
			}
	}
write(HIY"\n"NOR"━━━━━━━━━━━━━【"HBRED" 管理部 "NOR+"】━━━━━━━━━━━━━━"HIY"\n"NOR);
write(class1 + "\n");
write(HIY"\n"NOR"━━━━━━━━━━━━━【"HBMAG" 开发部 "NOR+"】━━━━━━━━━━━━━━"HIY"\n"NOR);
write(class2 + "\n");
write(HIY"\n"NOR"━━━━━━━━━━━━━【"HBCYN" 玩家部 "NOR+"】━━━━━━━━━━━━━━"HIY"\n"NOR);
write(class3 + "\n");
write(HIY"\n"NOR"━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"HIY"\n"NOR);
write(CYN"管理部神仙负责维护秩序，开发部神仙每天一个小时收集 BUG 资料，\n玩家部神仙整理玩家对游戏的建议与意见。\n"NOR);
write("其中"HIG"亮绿色"NOR"的表示在线。\n\n\n");

return 1;

}
string tribar_graph(int a)
{
	return blank_string[0..(30-a)] + NOR;
}
int help(object me)
{
write(@HELP
指令格式 : wizlist

用途 : 列出目前所有的巫师名单。
HELP
     );
     return 1;
}								