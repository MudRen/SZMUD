// Code of ShenZhou
// /d/emei/yunu.c 
// xbc, xuy: 96/07/09

inherit ROOM;

#include <ansi.h>

void create()
{
        set("short", "��Ů��");
        set("long", @LONG
���ǹ��Ƹ�ߵ���Ů�壬�嶥��һ���ĳ߼�����С�أ������ĳߣ��ļ����ݣ�
��Ϊ��Ů��ԡ֮������ʱ�ݴ�ʷ��鮣����ڴ˽�é���ӣ������ж������Ͼ�����
��ʳ�˼��̻�������Ů�·���Ϊ������ʳ�
LONG
        );
        set("exits", ([
		"northdown" : __DIR__"guiyun",
        ]));

	set("outdoors", "emei");

        set("objects", ([
                CLASS_D("emei") + "/fang" :1,
        ]));


	set("cost", 4);
        setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_wash", "wash");
}

int do_wash(string arg)
{
	object me = this_player();
	if ( !arg || arg != "face" ) return 0;

	message_vision(CYN"$N���������һЩ���֮ˮϴ��ϴ����\n"NOR, me);

	if ( me->query("gender") == "Ů��" && 
	     me->query_skill("beauty", 1) > 30 &&
	     me->query_skill("beauty", 1) < 120) {
		tell_object(me, CYN"����÷�����һЩ�µ�פ�����š�\n"NOR);
		me->improve_skill("beauty", me->query_per()*2);
		me->receive_damage("jing", 10, "����ϴ�ƣ�������");
	}
	
	return 1;
}
