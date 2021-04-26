// Code of ShenZhou
// rename.c
 
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	string id, name;

	if (!arg || sscanf(arg, "%s %s", id, name) != 2) 
		return notify_fail("ָ���ʽ: rename <id> <new chinese name>\n");
	
	ob = present(id, environment(me));
	if (!ob) return notify_fail("�Ҳ����������.\n");
	
	message_vision("$N��$n�����ָ�Ϊ"+name+"��\n",me,ob);
	ob -> set("name",name);
	return 1;
}
 
int help(object me)
{
   write(@HELP
ָ���ʽ: rename <id> <��������>
 
�����������������

HELP
   );
   return 1;
}
