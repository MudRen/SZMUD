// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov73.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������������ϣ�ס���ǰ�޼�������Բ�����޼����̨�ģ�������˸���
�غ�������⣬��Ҫ�Բ���Ϊ�����ٺ����������������߲�Զ�����洬�����
С��ͷ���ϱ�ɽ���в���Ұ�ޣ����Բ������Ӿ���ǰȥ���ԡ�
LONG);
	set("objects", ([
		__DIR__"npc/tyshang" : 1,
		]));
	set("exits", ([
		"northwest" : __DIR__"minov74",
		"north" : __DIR__"minov72",
		"west" : __DIR__"minov76",
		]));
	set("area", "������");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
