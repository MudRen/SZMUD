// Code of ShenZhou
// /u/zhangchi/obj/mingjiao_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�������԰�", ({ "board" }) );
	set("location", "/u/zhangchi/workroom");
	set("board_id", "mingjiao_b");
	set("long", "����һ�����̵��ӵ����԰塣\n");
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}

