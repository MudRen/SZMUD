//Cracked by Roath
// Room: /d/beijing/zijincheng/qianqingmen.c

inherit ROOM;

void create()
{
	set("short", "Ǭ����");
	set("long", @LONG
   ������͢������,���峯���������ĵط�.�ܶ������
�¶�������������ʱ������.
   ��������һ������ʯͨ��,����������,ͨ���������.
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"xiaohuayuan",
  "north" : __DIR__"yard1",
  "west" : __DIR__"jingshifang",
  "east" : __DIR__"shangshufang",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
