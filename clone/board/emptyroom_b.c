// Code of ShenZhou

inherit BULLETIN_BOARD;

void create()
{
	set_name("�ڰ�", ({ "board" }) );
	set("location", "/d/death/blkbot");
	set("board_id", "emptyroom_b");
	set("long", "����һ��������������д�������԰塣\n" );
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}

