// Code of ShenZhou
// Room: /d/mingjiao/shuyuan.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
���в��õ�һ����Ⱦ�����ǳ����ıڳ¹Ҽ����ֻ��������ľã���
�����ǲ��ס���ǰ��һ�鰸�������īֽ�⣬��һ��ȫ������¯������δ
Ъ��Ҳ��֪�ٵ�ʲô�㣬ʱ��һ����ܰ���ٸ��Ŀ�������
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"shijie51",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
