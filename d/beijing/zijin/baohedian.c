//Cracked by Roath
// Room: /d/beijing/zijincheng/baohedian.c

inherit ROOM;

void create()
{
	set("short", "���͵�");
	set("long", @LONG
�ֳƽ���������ʵ�������̫��ʱ���ڴ���װ���ٵ�̫
�͵��ܺء�ÿ����Ϧ�����������������󳼵ĵط��������ĵ�������
�˾��С�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zhonghedian",
  "north" : __DIR__"xiaohuayuan",
]));

	setup();
	replace_program(ROOM);
}
