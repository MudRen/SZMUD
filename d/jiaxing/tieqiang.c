// Code of ShenZhou
// Room: /d/quanzhou/tieqiang.c
// Date: May 21, 96   Jay
#include "ansi.h"
inherit ROOM;

int do_break(string);

void create()
{
	set("short", "��ǹ��");
	set("long", @LONG
������ƾɣ��м�����һ������(xiang)��������������������
Ⱥѻ����Ϊ������������˵��ǹ�����ѻ������񽫣�����������
��������������ֳ��Խ��Խ�ࡣ
LONG
	);

	set("no_fight", "1");

	set("item_desc", ([
                "xiang" : "�������ʱ������ǹ�����µ�����\n",
        ]));


	set("exits", ([
                "west" : __DIR__"jxnanmen",
		"north" : __DIR__"nanhu",
	]));

        set("objects", ([
		__DIR__"npc/wuya": 4]));

	set("outdoors", "quanzhou");
	set("cost", 0);
	setup();
}
void init()
{
        add_action("do_break","break");
}

int do_break(string arg)
{
    int n;
    object me = this_player();
    object gold,ring,mo;

    n = me->query("neili");
    if( !arg || arg!="xiang" ) {
        write("��Ҫ��������˵Ķ�����\n");
        return 1;
    }


    message_vision(
    "$N�Ƶ�����󣬰ݳ��������ʽ������һ������˫��ͬʱ�ĳ���\n", me);
        
    if (n>=500 && me->query_temp("qi/tangshi") && !me->query("���Ǿ�")
	&& me->query("max_neili") >= 1000) {
        message_vision(
        "ֻ��һ�����죬$N������ı���Ӳ��������һ������ӣ�\n", me);
	tell_object(me,HIR "�㷢��ԭ�������ǿ��ĵġ�\n" NOR);
	
		if(query("broken")){
		tell_object(me, "�����пտ���Ұ��ʲ��Ҳû�С�\n");
		return 1;
		}

        me->set("neili",n-200);
	ring = new ("/d/city/obj/goldring");
	mo = new ("/d/foshan/obj/huimo");
	gold = new("/clone/money/gold");
	gold->set_amount(40);
	ring -> move(me);
	mo -> move(me);
	gold->move(me);
	tell_object(me,HIR "�㷢��ԭ�������ǿ��ĵġ�\n" NOR);
	tell_object(me,HIB "������������ҵ���һ�����ָ��һ�˻�ī��\n" NOR);
	me->set("���Ǿ�",1);
	me->delete_temp("qi/tangshi");
	set("broken", 1);
    }
    else {
        message_vision(
        "$N���һ�����������������Ȼ�����ľ���ʲôҲû������\n", me);
        me->set("neili",0);
    }

    return 1;
}

