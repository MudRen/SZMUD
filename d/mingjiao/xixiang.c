// Code of ShenZhou
// Room: /d/mingjiao/xixiang.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "���᷿");
	set("long", @LONG
�������ھ�����һ����˼�С��Ĺ뷿�������ߵ���һ����ױ̨��
̨�Ϻ�����գ���ҫ�÷��л��Ž��أ��ûʸ������Ĳ����ڵ���֮�ҡ���
һ���������������ʵʹ�����ǰ������һ��Ů�ӵķۺ���Ь����������˯
�ڴ��С���뷿ֻ��һ�����ţ��������ա�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"yuanzi65",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
