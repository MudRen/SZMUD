// Code of ShenZhou
// Room: /d/xixia/xiaoba.c

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
�����ǻƺӱߵ�һ��С֧����������ƺӻ�ϵĵط������ذ���Ϊ�˷�ֹ��
�ӵ���ɳ����������Ӷ�����������һ��СС��ʯ�ӣ�С�Ӳ��ߣ�������йɳ��
����һ�Ƚ�ʵ��ʯբ�ţ������ǽ�����������բ�ŵ�������С��ʹ�ô���������
�İ��������˻ƺ���ɳ�����š�
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"hytan",
  "southwest" : __DIR__"qtxia",
]));
	set("no_clean_up", 0);

      set("fjing", 1);
	setup();
	replace_program(ROOM);
}
