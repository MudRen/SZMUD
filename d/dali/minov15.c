// Code of ShenZhou
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "�����в�");
	set("long", @LONG
�����Ǹ������в㣬��¥��һ�������Ǽ�������گ���Ĵ���ŷ�
�Լ��������е��������Ҽһ������������谸����в�����෿��
��Ϊ������
LONG
        );

	set("exits", ([
		"down" : __DIR__"minov14",
		]));

	set("objects", ([
		"/d/dali/npc/bykid.c" : 1,
		]));

	set("cost", 2);
	setup();
}
