// Code of ShenZhou
// restore.c
// restore player's data
// by sdong ,  11/18/98

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
		 object obj;

		 if (!arg) return notify_fail("ָ���ʽ��restore player.\n"); 		 if(!objectp(obj = present(arg, environment(this_player())))) 					 return notify_fail("����û������ˡ�\n");  		  if (!obj) obj = present(arg, me); 		  if (!obj) obj = find_object( resolve_path(me->query("cwd"), arg) ); 		  if (!obj) return notify_fail("û���������....��\n");  		  obj->restore(); 		  message_vision(CYN"$N����$n���������$p����ӰԽ��Խ���������ո�ԭ�ˣ���\n"NOR, 							  me,obj); 		 return 1; } 

int help(object me)
{
write(@HELP
ָ���ʽ��exam player.

�����ָ��������
HELP
	 );
	 return 1;
}

