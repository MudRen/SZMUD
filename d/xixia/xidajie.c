// Code of ShenZhou
// Room: /d/xixia/xidajie.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������������֣��ֵ������ɾ�����ש����·�汻��ˮ��ù���
�羵���ֵ�������߷��ߴ����ΰ��˫�˺ϱ�������ʮ��һ�꣬�����
�������ߡ���ֱ���һ�Դ��������������������ԡ��������һƷ��
��̳����������м��ҵ��̣��ֵ��е����塣
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"biaoqiyin",
  "north" : __DIR__"ypgate",
  "south" : __DIR__"daodian",
  "east" : __DIR__"center",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
