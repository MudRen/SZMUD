// Code of ShenZhou
// wdroad8.c ����·
// by Xiang

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
	������һ����������Ļ���·�ϣ���������ɭɭ�����֡�������һ����ɽ��
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"east" : __DIR__"wdroad7",
		"westup" : __DIR__"pine_road",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

