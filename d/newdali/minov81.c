// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov81.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�˼�����¥���㣬��һ����Ĵ��ݣ�����һ����̨��ʮ����ʯΧ��һȦ��
��������һ�����ƣ��ϻ汾�������ͼ����Ȧ�����м�����С�����ƣ���������
����������ţ���̨ǰ���Ʒ������ã�ʱ������ǰ������Ĥ�ݡ�
LONG);
	set("objects", ([
		__DIR__"npc/tyjisi" : 1,
		]));
	set("exits", ([
		"down" : __DIR__"minov80",
		]));
	set("area", "³����");
	set("cost", 2);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
