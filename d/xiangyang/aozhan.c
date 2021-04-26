// Code of ShenZhou
// Room: /d/xiangyang/aozhangang.c

inherit ROOM;

void create()
{
	set("short", "��ս��");
	set("long", @LONG
���μ���������������ˮ���߾��Ĺ�ս������һ��Ϊ�ź�ˮ�Ӵ��ٻ��ز�
��ԭ��춺�ˮ�ʵ����ݵ�������ɣ�ޱ䣬��ˮ�ĵ������ѱ������ǧ�ꡣ���
���ɹ����ﳣ�������ᣬ����һƬ��Ұ��
LONG
	);
        set("coordinates", ([ "x" : -1, "y" : 12 ]) );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"dufugang",
  "westdown" : __DIR__"dengc",
]));

	setup();
	replace_program(ROOM);
}
