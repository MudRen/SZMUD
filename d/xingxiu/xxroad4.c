// Code of ShenZhou
// Room: /d/xingxiu/xxroad4.c

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
������һ����ɽ�����˹����������᫵�С·�ϣ������������������
���������׵����
LONG
        );
        set("exits", ([
  "southdown" : __DIR__"tianroad3",
  "north" : __DIR__"xxroad5",
]));
	set("objects", ([
                "/d/qilian/npc/tuying": 2,
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

	set("bing_can", 20);
	set("cost", 1);
        setup();
        replace_program(ROOM);
}
