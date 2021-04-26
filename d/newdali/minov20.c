// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov20.c

inherit ROOM;

void create()
{
	set("short", "ũ��");
	set("long", @LONG
����һС����ͨ��ˮ��أ���گ��ů��ʪ���Թ�����������ֲˮ��Ϊ������
�����Ǵ�������ټ���ƽԭ���Σ���Ҫ�Ը���Ϊ���İ����˿�����һЩ��ũ�
��ػ��ֳ�С�飬һЩ��������������������ˮţ�������е�·����ũ���򶫶�
ȥ��
LONG);
	set("objects", ([
		__DIR__"npc/niu.c" : 1,
		__DIR__"npc/bynong.c" : 1,
		]));
	set("exits", ([
		"south" : __DIR__"minov21",
		"west" : __DIR__"minov17",
		"east" : __DIR__"minov23",
		]));
	set("area", "��٤��");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
