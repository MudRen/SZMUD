// Code of ShenZhou
// chaotian.c ���칬 
// by Fang 8/19/96

inherit ROOM;

void create()
{
	set("short", "���칬");
	set("long", @LONG
�����ѽ��䵱������ֻ��ʯ��ֱ�ʣ�Σ�Ÿ��������Ը���������������
����
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"hutouyan",
                "south" : __DIR__"huixian",
	]));
        set("objects", ([
                CLASS_D("wudang") + "/qingxu" : 1]));
	set("cost", 3);
	setup();
	replace_program(ROOM);
}

