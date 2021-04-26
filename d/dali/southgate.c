// Code of ShenZhou
// Room: /d/dali/southgate.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�˼��Ǵ����������ǵ����ţ������ʵ��������ǣ���گ�ڳ�
��������������������Ķ��ϵġ�������������Դ˳�Ϊ������ǽ��
ʯ������ݳɣ��߶����壬�����ɡ��������������������ľ�ʿ��
�����۾��۲����������������ˣ�ż�����ʼ����μ����ɷ��ӡ�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	set("cost", 1);
	
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/dalishibing" : 3,
		]));

	set("exits", ([
//		"northwest" : __DIR__"cangshan.c",
		"north" : __DIR__"crossing.c",
		"east" : __DIR__"droad4.c",
		"south" : __DIR__"shqiao.c",
//		"northeast" : __DIR__"wanrenzhong",
		]));

	setup();
}
