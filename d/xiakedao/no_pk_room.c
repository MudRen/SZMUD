//Cracked by Roath
// /d/xiakedao/no_pk_room.c
// by aln 5 / 98
// by Ssy 6 / 98

#include <ansi.h>

inherit ROOM;

void init()
{
 //       add_action("do_kill", "kill");
        add_action("do_hit", "hit");
}

/*
int do_kill(string arg)
{
 	object target, killer, me = this_player();


        if( !arg || arg = "" )  return 0;

        if( this_object()->query("no_fight") )
                return notify_fail("�����ֹս����\n");

	if( !target = present(arg, this_object()) )  return 0;

        if( !userp(target) )  return 0;

	if( me == target )
                return notify_fail("�� suicide ָ���ȽϿ�:P��\n");

	killer = new(__DIR__"npc/dizi");
	killer->set("xkd/killer", me->query("id"));
	killer->move(this_object());
	message_vision("$N���˹�����\n" NOR, killer);
	return 0;
}
*/

int do_hit(string arg)
{
        object target, killer, me = this_player();

        if( !arg || arg = "" )  return 0;
        if( this_object()->query("no_fight") )
                return notify_fail("�����ֹս����\n");
        if( !target = present(arg, this_object()) )  return 0;
        if( !userp(target) )  return 0;
        if( me == target )
                return notify_fail("���Լ�������ô�벻������\n");
	return notify_fail("���ϲ��ô���ң�\n");
        return 0;
}


        
