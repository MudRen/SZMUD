// Code of ShenZhou
// /clone/board/wudang_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("����ׯ���°�",({"board"}));
	set("location", "/d/taihu/qianyuan");
	set("board_id", "guiyun_b");
	set("long", "���ǹ�����ׯ�������Եİ���.\n");
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

