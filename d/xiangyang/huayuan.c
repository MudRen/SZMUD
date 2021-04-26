// Code of ShenZhou
// Room: /d/xiangyang/huayuan.c

inherit ROOM;

void create()
{
	set("short", "�Ứ԰");
	set("long", @LONG
��������԰�У������������У�¥��ͥԺ�������£���ľ����
�������˱ǡ���ɽǰС����ˮ���쾰���ģ�����̫��ʯɢ����ǰ��
����ʯС���������ߣ����Ͻ�����С·�ƹ�ɽʯ������ͨ��һ����
����
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 3, "y" : -6 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"huajing",
  "east" : __DIR__"huajing2",
  "southwest" : __DIR__"xiaolu",
]));

	setup();
	replace_program(ROOM);
}
