// Code of ShenZhou
// destroy.c
// destroy object
// by sdong , 11/18/98

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
		 object obj;


                 if( wizhood(me) != "(caretaker)" && wizhood(me) != "(wizard)" && wizhood(me) != "(designer)" &&
                          wizhood(me) != "(immortal)" && wizhood(me) != "(arch)" && wizhood(me) != "(admin)"
		  ) return notify_fail("ʲô��\n");

		 if (!arg) return notify_fail("ָ���ʽ��destroy object.\n");

		 if(!objectp(obj = present(arg, environment(this_player()))))
					 return notify_fail("����û������ˡ�\n");  		  if (!obj) obj = present(arg, me); 		  if (!obj) obj = find_object( resolve_path(me->query("cwd"), arg) ); 		  if (!obj) return notify_fail("û���������....��\n");  		  message_vision(CYN"$N�ͳ�һ�Ѽ���ǹ����׼$n�صĿ���һǹ����$p���һƬ������ʧ�ˣ���\n"NOR, 							  me,obj);  		  seteuid(ROOT_UID); 		  destruct(obj); 		  if(obj){ write("���޷����������ݻ١�\n"); return;}  		 return 1; } 

int help(object me)
{
write(@HELP
ָ���ʽ��destroy object.

�����������
HELP
	 );
	 return 1;
}

