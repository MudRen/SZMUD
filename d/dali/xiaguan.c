// Code of ShenZhou
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "�¹س�");
	set("long", @LONG
�¹سǣ�������β�ǣ�Ϊ���޷��������ƴ��Ѽ����١������ӱ�
��ɽ��´�����ˮ�Ƴ��϶������˵ķ羰�续����ȥ�ϱ߲�Զ����
����ǣ�������̫�ͳǣ����е�·ͨ���������˸������������ġ�̨
��Ϊ����Ҳ���������ġ�
LONG
        );

	set("exits", ([
		"northwest" : __DIR__"minov90",
		"south" : __DIR__"esqiao",
		"northeast" : __DIR__"cangshan.c",
		]));

	set("objects", ([
		"/d/dali/npc/wyshang.c" : 1,
		"/d/dali/npc/tyshang.c" : 1,
		]));

	set("outdoors","dali");
       set("fjing", 1);
	set("cost", 2);
	setup();
}
