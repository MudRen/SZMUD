// Code of ShenZhou
// /d/huanghe/tcxiaolu.c

inherit ROOM;

void create()
{
        set("short", "С·");
        set("long", @LONG
����һ��������С��壬�м�һ������·�������м��������෿����
�������������һЩ�����ҳ�����ߺ��������������Ѿ��ܾ�û���ڴ˾�
ס�����ˡ�
LONG );

        set("exits", ([
		"west"  : __DIR__"tckitchen",
		"east"  : __DIR__"tctuwu",
                "north" : __DIR__"tccunko", 
        ]));

    	set("cost", 1);

        set("outdoors", "huanghe");

        setup();
        replace_program(ROOM);
}
