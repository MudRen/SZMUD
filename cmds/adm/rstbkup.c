// Code of ShenZhou
// restorebackup.c
// restore player's data from backup
// by sdong , 11/18/98

#include <ansi.h>
#include <combat.h>
#ifndef QUEUEDIR
#define QUEUEDIR "/queue/" #endif #define RESTOREDATA QUEUEDIR + "restore" #define LOCKDATA QUEUEDIR + "restore.lock"  inherit F_DBASE; inherit F_CLEAN_UP;  
int main(object me, string arg)
{
		 object obj;
       string name,number;

		 if( wizhood(me) != "(caretaker)" && wizhood(me) != "(wizard)" &&
			  wizhood(me) != "(arch)" && wizhood(me) != "(admin)"
		  ) return notify_fail("ʲô��\n");

		 if (!arg) return notify_fail("ָ���ʽ��rstbkup player #backup.\n");
		 if(sscanf(arg, "%s %s", name, number) != 2)return notify_fail("ָ���ʽ��rstbkup player #backup.\n");

		  seteuid(ROOT_UID);
		  write_file(RESTOREDATA, name + ":" + number + "\n");


        tell_object(me,"�ָ�"+name+"����"+number+"ָ��ִ���ˡ�\n");
		 return 1; } 

int help(object me)
{
write(@HELP
ָ���ʽ��rstbkup player #bakcup

�����ӱ����лָ��������
HELP
	 );
	 return 1;
}

