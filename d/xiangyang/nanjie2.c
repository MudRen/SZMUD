// Code of ShenZhou
// Room: /d/xiangyang/nanjie2.c

inherit ROOM;

void create()
{
	set("short", "�Ͻ�");
	set("long", @LONG
���������������ʯ����ϣ�·�ϵ�����ϡϡ���飬�����䷱������ȥ��
Զ��ɳ������ţ����������������㽫���ڣ�ƽʱ����Щʿ���ڲ����������ǳ�
���
LONG
	);
        set("coordinates", ([ "x" : 0, "y" : -7 ]) );
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"huguo",
  "east" : __DIR__"chenhou",
  "north" : __DIR__"nanjie1",
  "west" : __DIR__"djtai",
]));
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
