// Code of ShenZhou
// Room: /d/dali/xiaguan.c

inherit ROOM;

void create()
{
	set("short", "�¹س�");
	set("long", @LONG
�¹سǣ�������β�ǣ�Ϊ���޷��������ƴ��Ѽ����١������ӱ���ɽ��´��
���ˮ�Ƴ��϶������˵ķ羰�续����ȥ�ϱ߲�Զ���Ǵ���ǣ�������̫�ͳǣ�
���е�·ͨ���������˸������������ġ�̨��Ϊ����Ҳ���������ġ�
LONG);
	set("objects", ([
		__DIR__"npc/wyshang.c" : 1,
		__DIR__"npc/tyshang.c" : 1,
		]));
	set("exits", ([
		"northwest" : __DIR__"minov84",
		"northeast" : __DIR__"cangshan.c",
		"south" : __DIR__"esqiao",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
