// Code of ShenZhou
// Room: /d/xiangyang/bingqiku.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����������Ǵ�������ı����⡣��һ�����ڣ�������������������������
�����ҡ��ֵ����ֽ����ְ������ȣ���ǹ�����ޣ�ͷ�������ס������ģ���ɫ��
���ı�������Ӧ�о��У��Ը��ɹ��������ǷǾ������������Ե�֮��
LONG
	);
	set("no_clean_up", 0);
	set("coordinates", ([ "x" : -3, "y" : -3 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"lianwuc",
]));

	setup();
	replace_program(ROOM);
}
