// Code of ShenZhou
// Room: /d/xiangyang/genglou.c

inherit ROOM;

void create()
{
	set("short", "��¥");
	set("long", @LONG
�����¥֮�����濿ǽ�����ź�ľ̴�������Ϸ��Ÿ���ʱ�õĸ�©��������
������©���������¥�ϣ�����֮�˱�Ͷ����춽�ʯ�ϣ�������Ȼ��������¥��
��ҹ�ø���������˯����Ҳ�ᾪ��������֮��������Ÿ��ɸ��ģ����������
����ȥ������֪���ġ�����¥�������۵ס�һ����紵�棬��������������
LONG
	);
        set("coordinates", ([ "x" : 1, "y" : 1 ]) );
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "northdown" : __DIR__"gengloux",
]));
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
