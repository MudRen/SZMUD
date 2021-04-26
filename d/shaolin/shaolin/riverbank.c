// Code of ShenZhou
//�ӱ�
//xiaojian May 20,2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��ˮ����");
	set("long",@LONG
�����Ǻ�ˮ���ߣ���Ϊ����ƽ̹������Ե�ʣ������ˮ����
�û�������࣬��������ĺ�ˮ����ȥ�峺�ɾ��������ǵľ���
����������ˮ�ȣ����߻��м���ũ�帾Ů����ϴ�·���
LONG);
	
        set("exits", ([
        "northup" : __DIR__"shanlu",
		"east" : __DIR__"hanshui2",
        ]));

		//set("no_fight",1);
		set("no_steal",1);
		set("cost",0);
        set("outdoors", "shaolin");
        set("resource/water", 1);
		setup();
}

int init()
{
	add_action("do_yao", "yao");
	
}

int do_yao(string arg)
{

	object me, ob;
	me = this_player();
		
	if(!arg || (arg != "shui" && arg != "water"))
		return notify_fail("��ҪҨʲô��\n");	
	ob = present("shui piao", me);
        if (!ob)
		return notify_fail("������û��ˮư����ôҨˮ? \n");
        if (me->is_busy())
                return notify_fail("����æ���أ�\n");
	if (ob->query("water_filled"))
			return notify_fail("ư���Ѿ�ʢ����ˮ�ˡ�\n");
	if (!me->query("shaolin/job_asked"))
        	return notify_fail("����û�������񣬸���α����ӱ��ܣ�����������\n");
	if (random(100) ==1)
	{ 
		message_vision(HIR"$Nһ��С�ģ�����һ��,��ư���������ˡ�\n"NOR, me);
		destruct(ob);
		return 1;
	}
    message_vision("$N�����������峺�ĺ�ˮ��Ҩ��һưˮ��\n",me);
	ob->set("water_filled",1);
	me->start_busy(3+random(2));
	me->receive_damage("jingli", (8+ random(3)));
	return 1;
}
int valid_leave(object me, string dir)
{
        if( dir=="east" && !wizardp(me) &&(me->query("shaolin/job_asked") ))
                return notify_fail("��͵�������½���Ժ�����ִ���������? \n");
        return ::valid_leave(me, dir);
}

