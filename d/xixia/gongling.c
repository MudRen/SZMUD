// Code of ShenZhou
// Room: /d/xixia/gongling.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������ذ�˼������Ĺ���ذ�˼�������ʵ���Ǽ���˳��̫
���������������Ϊ�����˼�����Ƴ�Ҳ�Ǽ������Ĵ󽫡������Ϊ
�����Զ������ĹҲ�����������ΰ������ȥ�е��ưܡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"deling",
]));
	set("cost", 2);
        set("fjing", 1);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
