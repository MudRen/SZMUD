// Code of ShenZhou
// Room: /d/xixia/chiling.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������ǰ��ƽ�Ĳ�����֮���ذϳ�ǵ���Ĺ����Ϊ�����Զ����
��ȥ�е��ưܣ������ʯ�Ʒ�ͷ������С�ݴ�ʯ�������ͷ�������㣬
��ǰ�������ɰص����÷ǳ��ߴ󡣱Ͼ��Ǽ�����ǰ�ֵ�ѽ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"wangling",
  "north" : __DIR__"deling",
]));
	set("cost", 2);
        set("fjing", 1);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
