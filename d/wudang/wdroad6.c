// Code of ShenZhou
// wdroad6.c ����·
// by Xiang

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
������һ����������Ļ���·�ϣ���������ɭɭ�����֡������Ǻ������磬
��˵���������˳�û�����ɾ���������ȥ�������ϡ�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"west" : __DIR__"caodian",
		"northwest" : "/d/emei/emroad3",
		"south" : __DIR__"wdroad7",
		"southeast" : "/d/foshan/road1",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

