//Cracked by Roath
// Room: /d/beijing/zijincheng/nzsfang.c

inherit ROOM;

void create()
{
	set("short", "�����·�");
	set("long", @LONG
������������·������Ͻ����е��صأ�ÿ�����⳼��������
�����������´����ս�������ٴ�������ʸ����ϣ��������ٽ�
�������￴�Ƽ��ӣ�ʵ�������ڽ����ر�ɭ�ϣ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yuehuamen",
  "south" : __DIR__"nanshufang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
