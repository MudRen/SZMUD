// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov63.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�˴���˵������ʱ�����������ߴ����ϻ�֮�����ϻ�Ի������������Ҳ��
��Ƚ������˲�����Ҳ�������ʴ˵���������һ����ͨ�ϱ��Ĵ�·����ȥʮ����
ϲ�ݳǣ�����Լ��ʮ��ɴ����ǡ�
LONG);
	set("exits", ([
		"north" : __DIR__"minov62",
		"south" : __DIR__"minov64",
		]));
	set("area", "ϲ�ݳ�");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
