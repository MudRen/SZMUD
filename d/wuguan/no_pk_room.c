//Cracked by Kafei
// /d/xiakedao/no_pk_room.c
// by aln 5 / 98
// by Ssy 6 / 98

#include <ansi.h>

inherit ROOM;

void init()
{
        add_action("do_hit", "kill");
        add_action("do_hit", "hit");
}

int do_hit(string arg)
{
        object target, killer, me = this_player();

        if( !arg || arg = "" )  return 0;
        if( this_object()->query("no_fight") )
                return notify_fail("�����ֹս����\n");
        if( !target = present(arg, this_object()) )  return 0;
        if( !userp(target) )  return 0;
        if( me == target )
                return notify_fail("�� suicide ָ���ȽϿ�:P��\n");
	return notify_fail("����ﲻ��͵Ϯ���˺���ң�\n");
        return 0;
}


        
