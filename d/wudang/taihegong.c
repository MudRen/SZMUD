// Code of ShenZhou
// taihegong.c ̫�͹����۵� 
// by Fang 8/20/96

inherit ROOM;

void create()
{
	set("short", "̫�͹����۵�");
	set("long", @LONG
	���۵�����ߣ���һ�ɰ˳ߣ���ͭ���������Իƽ��������ɣ�������ۼ
�����й������������ϵ۵Ľ����ˮ���������ͯ��Ů�ĵ������������һ�塣
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"north" : __DIR__"jinding",
	]));
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

