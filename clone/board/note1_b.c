// Code of ShenZhou
// /clone/board/note1_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("��ҷ����¼��", ({ "board"}) );
	set("location", "/d/death/noteroom");
	set("board_id", "note1_b");
	set("long", "����һ�����ʦ��¼��ҷ���ԭ������԰塣\n" );
	setup();
	set("capacity", 500);
	replace_program(BULLETIN_BOARD);
}

