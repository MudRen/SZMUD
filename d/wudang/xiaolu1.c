// Code of ShenZhou
// xiaolu1.c �ּ�С��
// by Xiang
// xQin 11/00

inherit ROOM;

void create()
{
	set("short", "�ּ�С��");
	set("long", @LONG
������һ��С���ϣ��������������ӣ�����ɭɭ���������أ�������Ҷ
��������������������Ķ�����
LONG
	);

	set("exits", ([
		"southwest" : __DIR__"xiaolu2",
		"northeast" : __DIR__"houyuan",
	]));
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

