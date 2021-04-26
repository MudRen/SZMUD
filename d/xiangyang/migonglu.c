// Code of ShenZhou
// Room: /d/xiangyang/migonglu.c

inherit ROOM;

void create()
{
	set("short", "�׹�·");
	set("long", @LONG
��Ϊ���鷨�������Ĺʾ����⸽�������α�Ѵ˴���Ϊ�׹�·��ԭ������
��С����Ϊ�ɹŴ��ʱ�����£�����Ĵ������Ǩ����������ѳɻ�Ұ����
ȥ�����󣬱��Ͽ���������
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 0, "y" : 10 ]) );
	set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"dufugang",
  "south" : __DIR__"hanshuin",
  "eastup" : __DIR__"shanlu2",
  "southwest" : __DIR__"migongci",
]));

	setup();
	replace_program(ROOM);
}
