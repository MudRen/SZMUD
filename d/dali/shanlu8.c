// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "����Ϫ�ذ�");
	set("long", @LONG
һ���Ŀ�����·��������Ϫ�ϰ���ᶫ����һ������Ϫ����
����������һ������ɽ�����������де���ľ���������Ŷ�Ϫͨ���
������ţ���ȥ��Զ�����廪¥�ˡ�
LONG
	);

	set("exits", ([
		"west" : __DIR__"shanlu7.c",
		"east" : __DIR__"shqiao.c",
		]));

	set("cost", 2);
        set("fjing", 1);
	set("outdoors", "dali");
	setup();
}
