// Code of ShenZhou
// Room: /d/xixia/xiaolu2.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
���Ƕ����ϵ�һ���Ӳݴ�������С·��������ƽʱûʲô�˼���·�߿���
��֪����Ұ�������ߵ�������Ȼ�ߴ�ͦ�Ρ�����͸�����յ��������ǰ߲߰���
��Ӱ�ӡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"xiaolu3",
  "south" : __DIR__"xiaolu",
  "east" : __DIR__"daoguan",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
