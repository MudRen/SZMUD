// Code of ShenZhou
// Room: /d/xiangyang/mihua.c

inherit ROOM;

void create()
{
	set("short", "�׻���");
	set("long", @LONG
������ƽ���Ӿӵ��׻��֣�����С�����ǵ�ſ�ڵ���Ϸˣ��·�Ե�լԺ��
�ڰ���š�����ԶԶ�����ζ�������������������������ڣ����˲���������
��·������ɵ�����֡�
LONG
	);
        set("coordinates", ([ "x" : -5, "y" : 2 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"jicang",
  "south" : __DIR__"xijie2",
  "northeast" : __DIR__"miao",
]));
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
