// by hongh 7-30-2001
inherit BULLETIN_BOARD;

void create()
{
	set_name("���񱨸�", ({ "board" }) );
	set("location", "/d/wizard/job_r");
	set("board_id", "job_b");
              set("poster_level", "(immortal)");
        set("wizard_only", 1);
	set("long", "���ǡ����ݡ���ʦ�㱨�������̵Ĺ������档\n" );
	setup();
	set("capacity", 900);
	replace_program(BULLETIN_BOARD);
}
