// Code of ShenZhou
// wdroad2.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����ϱ���Լ�ɼ������ݳǵĳ�ǽ��
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"west" : __DIR__"wdroad3",
		"southeast" : "/d/xingxiu/xxroad2",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

