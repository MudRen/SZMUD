// Code of ShenZhou
// Room: /d/dali/tower4.c

inherit ROOM;

void create()
{
	set("short", "���Ĳ�");
	set("long", @LONG
���а����������Դ����ж�����������Ŀ���䣬�ݲ��ɱ档����������
�������ķ𾭡�����β�����С��ȼú���--�����ˡ�������
LONG);
	set("exits", ([
		"up" : __DIR__"tower5",
		"down" : __DIR__"tower3",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
