// Code of ShenZhou
// Room: /d/xingxiu/xxroad1.c

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
������һ����ʯ����ϡ�����ͨ�����ݳǡ�
LONG
        );
        set("exits", ([
  "east" : "/d/city/ximen",
  "west" : __DIR__"xxroad2",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

	set("cost", 1);
        setup();
        replace_program(ROOM);
}

