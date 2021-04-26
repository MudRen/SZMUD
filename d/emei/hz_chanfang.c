// Code of ShenZhou
// hz_chanfang.c ����������
// Shan: 96/06/22

#include <room.h>
inherit ROOM;

string look_door();

void create()
{
        set("short", "����������");
	set("long", @LONG
������Ƕ��һ����ֵ�����������ɢ�ҵط���������ţ�ľ��ȣ��˴�
���Ǳ��ɵ��Ӵ�������֮������λ����ʦ̫���׼�Ů�����������붨��
��������������һ����ͨ����������Ϣ�ң����ߵ�����ͨ��㳡��
LONG
	);
	set("exits", ([
		"south" : __DIR__"sleeproom",
		"north" : __DIR__"hz_xilang2",
	]));

	set("jingzuo_room", 1);

        set("item_desc",([
                "door"          :       (: look_door :),
        ]));

        create_door("south", "ľ��", "north", DOOR_CLOSED);

	set("no_fight", 1);

	set("cost", 0);
	setup();
//	replace_program(ROOM);

}

string look_door()
{
        return "һ��С����ͨ��������Ϣ�ң����Ϲ��Ÿ�С���ӣ���Ϣ�ҡ�\n";

}

void init()
{
	add_action("do_jingzuo", "jingzuo");
}

int do_jingzuo(string arg)
{
	object me = this_player();
        if ( me->query("family/family_name") != "������" || me->is_busy() )
                return command("jingzuo "+arg);
	if(random(9) == 3) {
		tell_object(me, "��Ȼ���洫��һ������������ֻ���ķ����ң����ܾ���������\nֻ�ø�ȥ���������������С�\n");
		tell_room(environment(me),(string)me->query("name")+"������ȥ�����������������ˡ�\n", me);
		switch (random(3)) {
			case 0: me->move("/d/emei/chanfang_fs");
				break;
			case 1: me->move("/d/emei/chanfang_wn");
				break;
			case 2: me->move("/d/emei/chanfang_qf");
				break;
		}
		tell_room(environment(me),(string)me->query("name")+"�ӱ������������������������\n", me);
		return 1;
	}
	return command("jingzuo "+arg);
}

int valid_leave(object me, string dir)
{
	if ( me->query("gender") != "Ů��" && dir == "south" ) 
		return notify_fail("�����˶���Ů����Ϣ֮������λ" + 
			RANK_D->query_respect(me) + "����������\n");
		
	return ::valid_leave(me, dir);
}
