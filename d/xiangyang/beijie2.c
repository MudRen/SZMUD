// Code of ShenZhou
// Room: /d/xiangyang/beijie2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����������ı��֣��ӱ����������Ǵ���򶫶�ȥ����������������ԶԶ��
�����Ǹ����У��������徻��ɱȽϡ���������С�����ζԶԶ��Ʈ�˹�����
ȴ������������ƽ���ľ��㳡����
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 0, "y" : 4 ]) );
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"jzjie2",
  "south" : __DIR__"beijie1",
  "north" : __DIR__"beijie3",
  "west" : __DIR__"miao",
]));
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
