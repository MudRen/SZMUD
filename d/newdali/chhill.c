// Code of ShenZhou
// Room: /d/dali/chhill.c

inherit ROOM;

void create()
{
	set("short", "�軨ɽ");
	set("long", @LONG
��վ��һ��Сɽ������£�����ʢ���軨����Ʒ�ֵĲ軨��������������
��ƬСɽ��Ҳ�����˺ò衣���߲�Զ���Ǵ���ǵı����ˡ�
LONG);
	set("exits", ([
		"southwest" : __DIR__"northgate.c",
		"eastup" : __DIR__"chhill1.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
