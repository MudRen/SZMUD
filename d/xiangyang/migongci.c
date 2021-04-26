// Code of ShenZhou
// Room: /d/xiangyang/migongci.c

inherit ROOM;

void create()
{
	set("short", "�׹���");
	set("long", @LONG
�����Ǳ������黭�������������Ժ�ٽ��������ͷ��˳Ǹ�����������
���б��̵Ĳ�ƺ���徻��ͥԺ����������ӡ��滨��ݣ�����ֵ���̣��޲�
�������ˣ������Խࡢ�����ġ���֮�С�
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -2, "y" : 9 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"migonglu",
  "enter" : __DIR__"jieting",
]));

	setup();
	replace_program(ROOM);
}
