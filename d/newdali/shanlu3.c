// Code of ShenZhou
// Room: /d/dali/shanlu3.c

inherit ROOM;

void create()
{
	set("short", "�ŵ�");
	set("long", @LONG
һ��ʯ��ŵ���������ľ�Դ䣬ɽ��ƽ����������һ���޼ʵ���˫���ɴ�ɭ
�֡����������һƬ��ΰ������һ�������ĺ�ǽ������Խ��ǽͷ�ɼ�һ����¥
���������Ǵ�����ʤ�廪¥��
LONG);
	set("exits", ([
		"westup" : __DIR__"shanlu2.c",
		"east" : __DIR__"shanlu4.c",
		"north" : __DIR__"wuhua.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
