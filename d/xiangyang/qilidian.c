// Code of ShenZhou
// Room: /d/xiangyang/qilidian.c

inherit ROOM;

void create()
{
	set("short", "���ε�");
	set("long", @LONG
̴Ϫ�ɴ������ƹ����������������ˮʻ��������������з����Σ��޷���
ʮ�Ρ������������ǣ�죬Ω�ӷ�Ϊ����Ҳ��������ͨ�˴Ϊ�������η�����
�ۣ��������εꡣ�Ӵ�������Զ���������ǣ����������䵱ɽ��
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("coordinates", ([ "x" : -14, "y" : -2 ]) );
	set("exits", ([ /* sizeof() == 4 */
  "southwest" : __DIR__"guangde",
  "northeast" : __DIR__"shanlu",
  "northwest" : __DIR__"wjiejing",
  "east" : __DIR__"xushuzai",
]));

	setup();
	replace_program(ROOM);
}
