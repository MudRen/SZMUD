//Cracked by Roath
// Room: /d/beijing/zijincheng/guang1.c

inherit ROOM;

void create()
{
	set("short", "��ǰ�㳡");
	set("long", @LONG
����̫�͵�ǰ�Ĵ�㳡���м�һ������ʯ·ͨ��̫�͵���߸�
��һ��ʯʨ��ӵ������������·��ÿһ��ʯʨ���϶�վ��һ��������
����Ŀ��б�ӣ���˿������
LONG
	);
	set("exits", ([ /* sizeof() == 10 */
   "northeast" : __DIR__"zhongzuomen",
  "south" : __DIR__"taihemen",
  "east" : __DIR__"zuoyimen",
  "northwest" : __DIR__"zhongyoumen",
   "west" : __DIR__"youyimen",
  "north" : __DIR__"taihedian",
   
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
