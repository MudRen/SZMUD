// Code of ShenZhou
// Room: /d/newdali/dian4.c

inherit ROOM;

void create()
{
	set("short", "�سص̰�");
	set("long", @LONG
�����ǵ���ο;ۼ�֮������۷���������ʱʱ������ʤ����ˮ
翰��ĵ�أ����͡���ɲ�ڵᲨ�����֡�������������ͣ�۹ٶɣ���
�Ƹ�ʫ������֮Ϊ��ͣ���̻ᡱ������Ķ��ֲʺ硢��ɽ���ꡢ����
��𸡢��ϼ���졢�鷫ԶӰ���޲��������������ܡ�
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([
		"southeast" : __DIR__"minov11.c",
		"west" : __DIR__"dian3.c",
		]));

	set("objects", ([
		__DIR__"npc/gongzi" : 1,
		__DIR__"npc/enu1" : 1,
		__DIR__"npc/enu2" :1,
		]));

	set("no_clean_up", 0);

	setup();
}
