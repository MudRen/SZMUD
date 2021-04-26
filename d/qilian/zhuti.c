// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����ɽ");
        set("long", @LONG
��ɽͨɽ�ɳ������ɣ�Զ����������ñ�������Խ����ᡣ��ɽΪ������ɽ��
���һ���������Ϊ���ʲ��ã�����������Ψɽ���м����ڲݴ���֮��������˵
���о綾�����û�������ĸзѽ⡣����һ��С·��·��һ��ľ��(mupai)��
LONG
        );
        set("exits", ([
                "southwest" : __DIR__"datong-ling",
                "north" : __DIR__"yongchang",
		"east" : __DIR__"xiaolu",
        ]));

        set("item_desc", ([
                "mupai": "������ɽ������һ����\n",
	]));

	set("objects", ([
		"/d/wudang/npc/snake" : 1,
	]));
	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
