//Cracked by Roath
// Room: /d/beijing/zijincheng/ningshoumen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ǰ��һ��Ӱ��(wall)��Ӱ�ں�������ٹ������ˡ�����
������Ǭ¡��ʮ��������ʮһ�꣬�´��������ߣ�ǰ�������
�������ƣ����Ͻ�������������ΰ�Ĺ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"guang4",
  "north" : __DIR__"huangjidian",
  "northwest" : __DIR__"gzxd5",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "wall" : "�������ڡ��������ž�����������ľ�����\n",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
