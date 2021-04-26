// Code of ShenZhou
// Room: /d/newdali/dian1.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������ܵ�ɽ����������ɽϵ������ɽ���Ķ�֧�������£��ܳ�����ɽ��
�д�С��ʮ��ɽ�塣���������ɽ���£�ɽ��ˮ���������Ӱ��������Ȼ��
ͼ������صġ��ᡱ�������м��Ǵ���ӣ���˾��Ǩ�ġ�ʷ�ǡ��������д���
���أ��ڹŴ�������һ���������Ĳ������ƣ�������ء�
LONG
	);
	set("cost", 1);
       set("fjing", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dian2",
  "north" : __DIR__"senlin",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
