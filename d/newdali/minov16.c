// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov16.c

inherit ROOM;

void create()
{
	set("short", "�سص̰�");
	set("long", @LONG
�����ǵ���ο;ۼ�֮������۷���������ʱʱ������ʤ����ˮ翰��ĵ�أ�
���͡���ɲ�ڵᲨ�����֡�������������ͣ�۹ٶɣ����Ƹ�ʫ������֮Ϊ��ͣ��
�̻ᡱ������Ķ��ֲʺ硢��ɽ���ꡢ������𸡢��ϼ���졢�鷫ԶӰ���޲���
�����������ܡ�
LONG	);
	set("objects", ([
		__DIR__"npc/gongzi" : 1,
		__DIR__"npc/enu1" : 1,
		__DIR__"npc/enu2" :1,
		]));
	set("exits", ([
		"southeast" : __DIR__"minov17",
		"west" : __DIR__"minov14",
		]));
	set("area", "��٤��");
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
