// Code of ShenZhou
// /clone/board/broker_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("���׿�̨������", ({"board" }) );
	set("location", "/d/city/kantai");
	set("board_id", "broker_b");
	set("long", "���Ǳ������׿�̨�����ӣ����������˸������飬Ѱ��,������ʾ��\n" );
	setup();
	set("capacity", 120);
	replace_program(BULLETIN_BOARD);
}

