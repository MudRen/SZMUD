// Code of ShenZhou
// Room: /d/xixia/qingcheng.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
���λ�ھ�Զ�������ٶ�ʮ����ϰ�ʮ��������ݣ���Ϊ��ǣ���
ʵֻ�Ǹ�С����Ϊ�ش���ȥ���ĵ�Ҫ�壬����������ĺʹ��ε����ö�
���뾭����������������������֡�
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"desert4",
  "east" : "/d/huanghe/hetao",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
