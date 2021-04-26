// Code of ShenZhou
// Room: /d/xiangyang/wangcg.c

inherit ROOM;

void create()
{
	set("short", "���Ǹ�");
	set("long", @LONG
������һ���߸�֮�ϣ��Ӵ˿�������ˮ�ϱߵ������ǡ����ε��ƽϸߣ���
��һ�����Ρ��ʶ��ɹŴ���ȷ浽ʱ����פ���ڴˡ�
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 2, "y" : 11 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"fancheng",
  "southwest" : __DIR__"shanlu2",
]));

	setup();
	replace_program(ROOM);
}
