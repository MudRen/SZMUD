// Code of ShenZhou
// wdroad1.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
	������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С��ϱ�ͨ�����ݳǡ�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
                "north" : __DIR__"road2",
		"south" : "/d/city/beimen",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

