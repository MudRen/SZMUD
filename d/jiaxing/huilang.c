// Code of ShenZhou
// Jay 8/9/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��������һ���¶���(door)���Ŷ���д�š����ġ����֣�����ɫ
�������ɣ����²Ծ�������һ�����ĵĻ�������������ʯ��������̦��
��ǰ�����߰������ز�ø�ͦ���ڵ��������������ġ�
LONG
        );
        set("exits", ([
		"west" : __DIR__"qinshi",
		"east" : __DIR__"shushi",
		"south" : __DIR__"mzqianting"
	]));

        set("item_desc", ([
		"door" : "�����ƺ���δ������\n", 
        ]));

	set("objects", ([
		"/d/city/obj/stone" : 1,
	]));
        set("no_clean_up", 0);


        create_door("west","�¶���","east", DOOR_CLOSED);

	set("cost", 1);
	setup();
        replace_program(ROOM);
}
