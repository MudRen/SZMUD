// by Yujie 7-30-2001
inherit BULLETIN_BOARD;

void create()
{
	set_name("�������ۣ����񱨸�", ({ "board" }) );
	set("location", "/d/wizard/sys_r");
	set("board_id", "sys_b");
              set("poster_level", "(immortal)");
        set("wizard_only", 1);
	set("long", "���ǡ����ݡ���ʦ�㱨�������̣����۹�������Ĺ������档\n" );
	
	set("capacity", 900);
	setup();
	replace_program(BULLETIN_BOARD);
}

