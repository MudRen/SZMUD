// Code of ShenZhou
// Room: /d/xixia/qtxia.c

inherit ROOM;

void create()
{
	set("short", "��ͭϿ");
	set("long", @LONG
�����ǻƺӺ������ȶ������ļ�����ͭϿ���ƺ�һ·���ʵ���������ĺ�
��һ���ӱ�խ���������ͱ���һ���������˽�����Ը�ֿ����ƺ�ȴ�񲻶��µĺ�
�Ӵ���Ӳ�����������ˮ��һ���ӱ�������������������죬ˮ��¡¡��
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"xiaoba",
  "southwest" : __DIR__"mszhou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
