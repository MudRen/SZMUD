// Code of ShenZhou
// Room: /d/dali/feiwo.c  temp room for dali bandit

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ɽ��ǿ���Ⱦۼ��ķ��ѡ�
LONG
	);
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
