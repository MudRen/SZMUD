//Cracked by Roath
// Room: /d/beijing/zijincheng/tongdao1.c

inherit ROOM;

void create()
{
	set("short", "ͨ��");
	set("long", @LONG
����һ������ʯ�̳ɵĿ�ͨ��,�ɹ����г���ͨ��,��������
�ɸߵ�Χǽ,���˸е�ׯ������.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"yongshougong",
  "north" : __DIR__"tongdao2",
  "south" : __DIR__"neiyoumen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
