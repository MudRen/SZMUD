// Code of ShenZhou
// Room: /city/dayuan.c
// YZC 1996/11/13 

inherit ROOM;

void create()
{
	set("short", "��Ժ��");
	set("long", @LONG
������һ�������Χ�ɵĴ�Ժ�ӣ�Ժ��������һ���û������Ƴɵ�ʯ������
�����˼������֣�������Ϊ�˼���ʲô�˶���������ġ����Ｋ��������Զ��
������������Եø�����࣬�����ݷ����ĳ����γ���һ�������ĶԱȡ�������
�ֻص���������Զ����һƬ�����͵ĵ��
LONG
	);

	set("exits", ([
		"west" : __DIR__"xiaomiao",
	]));

	set("objects", ([
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}

