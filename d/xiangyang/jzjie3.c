// Code of ShenZhou
// Room: /d/xiangyang/jzjie3.c

inherit ROOM;

void create()
{
	set("short", "���ݽ�");
	set("long", @LONG
�������Ǿ��ݽֵ�ĩ�Σ����������ѽ�����·�������в�����Ⱥ�����Ѳ���
��������ӵ������������ȥ��ɵ������ǵ�С���š������ƺ���һ����������
��С�ꡣ
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");
        set("coordinates", ([ "x" : 3, "y" : 5 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"bingqid",
  "north" : __DIR__"beimen",
  "south" : __DIR__"jzjie2",
]));

	setup();
	replace_program(ROOM);
}
