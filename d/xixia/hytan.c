// Code of ShenZhou
// Room: /d/xixia/hytan.c

inherit ROOM;

void create()
{
	set("short", "����̲");
	set("long", @LONG
��������������������Ļ���̲�������ǻƺӱߵ�һ��Ƭˮ���μ�أ��ƺ�
ˮ���ĺ���ȥ�γ���һ��Ƭ����ˮ̲������ˮ�ݷ�ʢ���������������˴�������
��Ұ��������������ˮ��Ϸ��������Ϣ����Ϊ����һ�󾰹ۡ�
LONG
	);
	set("resource/grass", 1);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"nanmen",
  "southwest" : __DIR__"xiaoba",
]));
	set("objects", ([
		__DIR__"npc/lamb" : 2,
	]));
        set("fjing", 1);
	setup();
	replace_program(ROOM);
}
