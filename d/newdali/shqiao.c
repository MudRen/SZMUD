// Code of ShenZhou
// Room: /d/dali/shqiao.c

inherit ROOM;


void create()
{
	set("short", "˫����");
	set("long", @LONG
����һ����·�ڣ�����������ʯ��������˫���ţ����ſ�������Ϫ�ϣ��ű�
���Ǵ���ǣ��ɴ���ȥ��ͨ���Ϸ���ϲ�ݡ����ڵȳ���Ĺٵ�����ȥ�Ĳ�·ͨ��
������������Ϫ�ϰ����пɴ��廪¥��
LONG);
	set("exits", ([
		"southeast" : __DIR__"tulu4",
		"north" : __DIR__"southgate.c",
		"south" : __DIR__"minov62",
		"west" : __DIR__"shanlu4",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
