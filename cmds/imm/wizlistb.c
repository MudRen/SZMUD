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

	write(MUD_NAME + "Ŀǰ����ʦ�У�");
//	for(int i=0; i<sizeof(list); i++)
//		printf("%-15s%c", list[i],  (i%5==4) ? '\n' : ' ');

	wizstatus = SECURITY_D->query_wizstatus();
	list = keys(wizstatus);
//	write(HIW"\n\n����ۡ�  "NOR);
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
	write(HIW"\n�� ���� ��  "NOR);
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
	write(HIY"\n�� ���� ��  "NOR);
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
	write(HIG"\n�� ���� ��  "NOR);
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
	write(HIC"\n�� ���� ��  "NOR);
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
	write(HIG"\n���ػ���  "NOR);
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
	write(GRN"\n�� С�� ��  "NOR);
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
	write(CYN"\n�� ѧͽ ��  "NOR);
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
//	write(CYN"\n�� ���� ��  "NOR);
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

//	write("�����飺april scatter jiuer slipper chchong fengyu \n");
//	write("��Ϸ�飺hongh bdragon zyu xixi nero sleep lisser hihi \n");
//	write("����ָ���飺jonah reek \n");
//	write("��������飺blacko lara xzt \n");
//	write("���ֱ���飺\n");
//	write("���У�wizard �������ʦ������ʱ����Ҫ��������������ʦЭ�����鹤����\n");

	return 1;
}
int help(object me)
{
write(@HELP
ָ���ʽ : wizlist

��; : �г�Ŀǰ���е���ʦ������
HELP
     );
     return 1;
}