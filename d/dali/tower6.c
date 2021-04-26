// Code of ShenZhou
// Room: /d/newdali/tower6.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������������е��з��񸡵�����������������ܣ���η�����
������죬����Э���������Ⱦ����������ɣ���������������������
�����ǵ���ʯ����������Ʒ���������ļҽ��ޡ������������˼�ƷҲ
����
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tower7",
  "down" : __DIR__"tower5",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
