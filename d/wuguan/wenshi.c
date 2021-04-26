//Created by Sleep on k1-08-11
//Modified by Zyu on k1-08-11
// road: /d/wuguan/wenshi.c

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "����");
        set("long", @LONG
����һ���ܱյķ��䡣�����൱���ʣ���Χ���������ʻ���ӵ���㣬
������ժ�������ͷ�ϣ���һ������һֱ�ڸ�����ʲô(voice),��Խ��Խ
�����������ڻ������ˡ�
LONG
        );
        set("outdoors", "wuguan");
        set("item_desc", ([
                "voice" : "�����ɲ��ܿ�������(listen)��\n"
        ]));

        set("exits", ([
                "northeast" : __DIR__"gardeni",
        ]));

	set("objects", ([
		__DIR__"npc/huajiang" : 1,
	]));

        set("cost", 1);
        setup();
}

void init()
{
	add_action("do_listen", "listen");
}

int do_listen(string arg)
{
	object me = this_player();

	if ( !arg || arg=="" ) return 0;

	if ( arg!="voice" ) return notify_fail("���������ֻ��������(voice)��\n");

	message_vision(CYN"�ն�������˵������ɻ��͵����\n"NOR, me);

	return 1;
}