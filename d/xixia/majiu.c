// Code of ShenZhou
// Room: /d/xixia/majiu.c

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����������Ӫ����ǣ���һɫ���ɹŸ�ͷս�����ľ��ж�����
���������о���ս��ȥ��磬�������磬��������ı뺷�����ɵ���
�������в��硣����Ӫ��ս����Ǿ�ѡ�������׳��������������
����ڶ��Ͳ��ϣ�һ�����ζ�Ͳ��ϵĻ��ζ��Ʈ�˹�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"biaoqiyin",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}
