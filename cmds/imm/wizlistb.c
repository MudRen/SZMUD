//Cracked by Kafei
// wizlist.c
// by rider 7-12-01

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *list, name;
	mapping wizstatus;
	object user;
	int j = 0;
	int i;

	write(MUD_NAME + "目前的巫师有：");
//	for(int i=0; i<sizeof(list); i++)
//		printf("%-15s%c", list[i],  (i%5==4) ? '\n' : ' ');

	wizstatus = SECURITY_D->query_wizstatus();
	list = keys(wizstatus);
//	write(HIW"\n\n『天帝』  "NOR);
//	for(int i=0; i<sizeof(list); i++)
//    for(i=0; i<sizeof(list); i++)
//	{
//		if( wizstatus[list[i]] == "(admin)" )
//		{
//			j++;
//			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
//		}
//	}
//
	j=0;
	write(HIW"\n『 天神 』  "NOR);
	for( i=0; i<sizeof(list); i++)
	{
		if( wizstatus[list[i]] == "(arch)" )
		{
			j++;
			user = find_player(list[i]);
			if ( !user || !interactive(user))
			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
			else
			{
			if(strlen(list[i]) == 3)
			printf("%-12s         %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 4)
			printf("%-12s        %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');			
			if(strlen(list[i]) == 5)
			printf("%-12s       %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 6)
			printf("%-12s      %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 7)
			printf("%-12s     %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 8)
			printf("%-12s    %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			}
		}
	}

	j=0;
	write(HIY"\n『 天仙 』  "NOR);
	for( i=0; i<sizeof(list); i++)
	{
		if( wizstatus[list[i]] == "(wizard)" )
		{
			j++;
			user = find_player(list[i]);
			if ( !user || !interactive(user))
			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
			else
			{
			if(strlen(list[i]) == 3)
			printf("%-12s         %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 4)
			printf("%-12s        %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');			
			if(strlen(list[i]) == 5)
			printf("%-12s       %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 6)
			printf("%-12s      %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 7)
			printf("%-12s     %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 8)
			printf("%-12s    %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			}
		}
	}

	j=0;
	write(HIG"\n『 仙人 』  "NOR);
	for( i=0; i<sizeof(list); i++)
	{
		if( wizstatus[list[i]] == "(designer)" )
		{
			j++;
			user = find_player(list[i]);
			if ( !user || !interactive(user))
			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
			else
			{
			if(strlen(list[i]) == 3)
			printf("%-12s         %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 4)
			printf("%-12s        %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');			
			if(strlen(list[i]) == 5)
			printf("%-12s       %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 6)
			printf("%-12s      %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 7)
			printf("%-12s     %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 8)
			printf("%-12s    %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			}
		}
	}

	j=0;
	write(HIC"\n『 正仙 』  "NOR);
	for( i=0; i<sizeof(list); i++)
	{
		if( wizstatus[list[i]] == "(caretaker)" )
		{
			j++;
			user = find_player(list[i]);
			if ( !user || !interactive(user))
			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
			else
			{
			if(strlen(list[i]) == 3)
			printf("%-12s         %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 4)
			printf("%-12s        %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');			
			if(strlen(list[i]) == 5)
			printf("%-12s       %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 6)
			printf("%-12s      %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 7)
			printf("%-12s     %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 8)
			printf("%-12s    %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			}
		}
	}

	j=0;
	write(HIG"\n『守护神』  "NOR);
	for( i=0; i<sizeof(list); i++)
	{
		if( wizstatus[list[i]] == "(virtuoso)" )
		{
			j++;
			user = find_player(list[i]);
			if ( !user || !interactive(user))
			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
			else
			{
			if(strlen(list[i]) == 3)
			printf("%-12s         %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 4)
			printf("%-12s        %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');			
			if(strlen(list[i]) == 5)
			printf("%-12s       %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 6)
			printf("%-12s      %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 7)
			printf("%-12s     %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 8)
			printf("%-12s    %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			}
		}
	}

	j=0;
	write(GRN"\n『 小仙 』  "NOR);
	for( i=0; i<sizeof(list); i++)
	{
		if( wizstatus[list[i]] == "(creator)" )
		{
			j++;
			user = find_player(list[i]);
			if ( !user || !interactive(user))
			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
			else
			{
			if(strlen(list[i]) == 3)
			printf("%-12s         %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 4)
			printf("%-12s        %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');			
			if(strlen(list[i]) == 5)
			printf("%-12s       %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 6)
			printf("%-12s      %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 7)
			printf("%-12s     %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 8)
			printf("%-12s    %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			}
		}
	}

	j=0;
	write(CYN"\n『 学徒 』  "NOR);
	for( i=0; i<sizeof(list); i++)
	{
		if( wizstatus[list[i]] == "(immortal)" )
		{
			j++;
			user = find_player(list[i]);
			if ( !user || !interactive(user))
			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
			else
			{
			if(strlen(list[i]) == 3)
			printf("%-12s         %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 4)
			printf("%-12s        %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');			
			if(strlen(list[i]) == 5)
			printf("%-12s       %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 6)
			printf("%-12s      %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 7)
			printf("%-12s     %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			if(strlen(list[i]) == 8)
			printf("%-12s    %c", (user->query("env/invisibility")) ? HIY + list[i] + NOR : HIR + list[i] + NOR,  (j%7==0) ? '\n' : ' ');
			}
			if(j==7)break;
		}
	}

//	j=0;
//	write(CYN"\n『 半仙 』  "NOR);
//	for(i=0; i<sizeof(list); i++)
//	{
//		if( wizstatus[list[i]] == "(immortal)" )
//		{
//			j++;
//			printf("%-12s%c", list[i],  (j%7==0) ? '\n' : ' ');
//			if(j==7)break;
//		}
//	}

	write("\n\n");

//	write("门派组：april scatter jiuer slipper chchong fengyu \n");
//	write("游戏组：hongh bdragon zyu xixi nero sleep lisser hihi \n");
//	write("技术指导组：jonah reek \n");
//	write("资深玩家组：blacko lara xzt \n");
//	write("天帝直属组：\n");
//	write("其中：wizard 级别的巫师可以随时按需要，抽调其他组的巫师协助本组工作。\n");

	return 1;
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