//Cracked by Kafei
// /clone/board/lisser_mb.c

inherit "/inherit/misc/sboard";

void create()
{
	set_name("�������԰�", ({ "board" }) );
	set("location", "/u/lisser/hmsz-dy");
	set("board_id", "test_mb");
	set("long", "����һ�������õ����԰塣\n" );
	setup();
	set("capacity", 280);
	replace_program("/inherit/misc/sboard");
}

