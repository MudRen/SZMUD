//Cracked by Roath
// Room: /d/beijing/zijincheng/xiaohuayuan.c

inherit ROOM;

void create()
{
	set("short", "С�㳡");
	set("long", @LONG
���Ǳ��͵���һ��С�㳡��������Ǭ���ţ������Ǳ��͵
������¡���ţ����Ǿ����š��ϱ߱��͵�̨������һ��޴��ʯ
��(sculpture)����������һ��ƽ���Ǿ�������
LONG
	);
	set("exits", ([ /* sizeof() == 9 */
  "south" : __DIR__"baohedian",
  "east" : __DIR__"jingyunmen",
  "enter" : __DIR__"junjichu",
  "north" : __DIR__"qianqingmen",
  "west" : __DIR__"longzongmen",
  
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "sculpture" : "���ǹ�������һ��ʯ��ʯ�����ܿ��в�֦�����ƣ��²�Ϊ��\n"
		"ˮ�������м��������Ƴ����ž����������������������������\n"
		"��̾�ϸ��˿������\n",
]));
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
