// Code of ShenZhou
// Room: /d/beijing/zjcheng.c

inherit ROOM;

void create()
{
        set("short", "�Ͻ��ǳ���");
	set("long", @LONG
�����Ͻ��ǳ��š���������ȥ���Ǿ������һ��Ļʵ�ס�Ĺ����ͨ����
Ҫ���ȥ�������ֱ�ȵ��컹Ҫ�ѡ��ſ�վ�˼�����������������˸о�ׯ����
�£���ʱ�ļ����д����������롣
LONG
	);
        set("exits", ([
                "north" : __DIR__"jingshan",
                "south" : __DIR__"changanjie",
                "east" : __DIR__"wangfudajie",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
