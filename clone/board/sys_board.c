// by Yujie 7-30-2001
inherit BULLETIN_BOARD;

void create()
{
	set_name("问题讨论，任务报告", ({ "board" }) );
	set("location", "/d/wizard/sys_r");
	set("board_id", "sys_b");
              set("poster_level", "(immortal)");
        set("wizard_only", 1);
	set("long", "这是【神州】巫师汇报工作进程，讨论工作问题的工作报告。\n" );
	
	set("capacity", 900);
	setup();
	replace_program(BULLETIN_BOARD);
}

