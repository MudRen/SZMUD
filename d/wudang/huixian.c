// Code of ShenZhou
// huixian.c ������ 
// by Fang 8/20/96

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������ƽ��һ��ɽ������������һ��խխ��ľ�ź��ڽ��ϣ�ֻ��һ��
������
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"north" : __DIR__"chaotian",
                "south" : __DIR__"toutian",
	]));
	set("cost", 1);
        set("fjing", 1);
	setup();
	replace_program(ROOM);
}

