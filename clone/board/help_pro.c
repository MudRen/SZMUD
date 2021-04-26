// Write by fengyu
// /clone/board/project_b.c
// 2001.8.16

#include <ansi.h>

inherit "/inherit/misc/jboard";

void create()
{
        set_name(HIG"HELP文件修改计划"NOR, ({ "board" }) );

        set("location", "/d/city/guangchang");
        
        set("board_id", "help_pro");

        set("long", HIY"-------------------------------------"NOR+
		    HIY"-----------------------------------\n"NOR+

		    "        "+HIC"report"NOR+"     提交HELP文件修改建议。\n"+
		    "        "+HIC"refer"NOR+"      查看计划及修改建议。        \n"+
		    "        "+HIC"terminate"NOR+"  删除计划。      \n\n"+
		    HIC"  以下是已提出来的任务的大致列表：       \n\n"NOR+

		    HIY"--------------------------------------"NOR+
		    HIY"----------------------------------\n\n"NOR
	   );

        setup();

        replace_program("/inherit/misc/jboard");
}
