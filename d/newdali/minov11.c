// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov11.c

inherit ROOM;

void create()
{
	set("short", "����̶");
	set("long", @LONG
����̶��Ȫ�羵����ǰ����أ�����һ�������һȪˮ�壬��Լ��Ķ��ˮ��
��ʮ���ɣ������ɫ��һȪˮ�ǣ���ԼһĶ��ˮɫ΢�ơ���Ȫ������������ˮɫ
���죬һ��һ�ƣ��Ա�������������ҵ�̫��ͼ�����˶�����ء����ؽ�Χ����
��ʯ������ˮ���������û������Χ�����ͣ���Ȼ�Եá�
LONG);
	set("objects", ([
		__DIR__"npc/youke1.c" : 2,
		]));
	set("exits", ([
		"northwest" : __DIR__"minov10",
		"south" : __DIR__"maze1",
		]));
	set("area", "������");
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
