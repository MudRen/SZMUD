// Code of ShenZhou
// Room: /d/xiangyang/guloud.c

inherit ROOM;

void create()
{
	set("short", "��¥�ײ�");
	set("long", @LONG
�㴦�ڹ�¥�ĵײ㣬һ���������ǽ�ϵĻ�ש��϶��͸��������Ҳ�������
�Ƶĳ�ľ�ݼ���ǽ�ߡ�ǽ�ǡ��ݼ��������˻ҳ���¥���������˽�ʵ��ľ¥�壬
ǽשҲ����Ϊ��ʵ��
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"gulou",
  "westdown" : __DIR__"xiaoshi",
]));

	setup();
	replace_program(ROOM);
}
