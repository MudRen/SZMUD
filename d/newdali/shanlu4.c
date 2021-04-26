// Code of ShenZhou
// Room: /d/dali/shanlu4.c

inherit ROOM;

void create()
{
	set("short", "����Ϫ�ذ�");
	set("long", @LONG
һ���Ŀ�����·��������Ϫ�ϰ���ᶫ����һ������Ϫ���̲���������
һ������ɽ�����������де���ľ���������Ŷ�Ϫͨ���������ţ���ȥ��Զ��
���廪¥�ˡ�
LONG);
	set("exits", ([
		"west" : __DIR__"shanlu3.c",
		"east" : __DIR__"shqiao.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
