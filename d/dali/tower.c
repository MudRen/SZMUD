// Code of ShenZhou

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ΪԲ���Σ��ܵ����������Ϊһ�飬������Ϸ���ɡ�������
����̬֮��
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
