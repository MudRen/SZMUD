// Code of ShenZhou
// Room: /d/xixia/xiaolu3.c

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
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"bianmen",
  "east" : __DIR__"xiaolu2",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
