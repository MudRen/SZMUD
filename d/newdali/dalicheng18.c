// Code of ShenZhou
// Room: /d/dali/dalicheng18.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
�����Ǵ����һ���壬���ɢ���ڲ�ɽ���������������������ʯ���ݳɣ�
��ַ�񡣳��������죬�Ҽһ����������Ի�ľ�����ſڣ��ڴ��һ�����ġ���
ɽ����������Ұ���������ۻ��֡�
LONG);
	set("objects", ([
		__DIR__"npc/oldman" : 1,
		__DIR__"npc/miaonu2" : 2,
		]));
	set("exits", ([
		"north" : __DIR__"dalicheng16",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
