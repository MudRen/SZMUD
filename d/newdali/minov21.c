// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov21.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������������ľ�Ծ����ϣ����Ǹ�������������������̡��乹�����
����¥�����濪�ţ����ݿ����£��ϸ��糵��״���в�ס�ˣ��������²㣬һ��
Ϊţ��Ȧ��
LONG);
	set("objects", ([
		__DIR__"npc/goat.c" : 2,
		]));
	set("exits", ([
		"north" : __DIR__"minov20",
		"up" : __DIR__"minov22",
		]));
	set("area", "��٤��");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
