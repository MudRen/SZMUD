// by hongh 7-30-2001
inherit BULLETIN_BOARD;

void create()
{
	set_name("任务报告", ({ "board" }) );
	set("location", "/d/wizard/job_r");
	set("board_id", "job_b");
              set("poster_level", "(immortal)");
        set("wizard_only", 1);
	set("long", "这是【神州】巫师汇报工作进程的工作报告。\n" );
	setup();
	set("capacity", 900);
	replace_program(BULLETIN_BOARD);
}

