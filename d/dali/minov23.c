// Code of ShenZhou
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ�ô��������������ڴ˽���һ���൱��ĸ������²�����
��һ��Ȧ��ʮ��ͷţ���Աߵ�¥���޵��Ŀ����������Ǳ��ص���
���˼ҡ�
LONG
        );

	set("exits", ([
		"west" : __DIR__"minov22",
		"up" : __DIR__"minov24",
		]));

	set("objects", ([
		"/d/dali/npc/goat.c" : 3,
		"/d/dali/npc/niu.c" : 2,
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
