// Write by fengyu
// /clone/board/project_b.c
// 2001.8.16

#include <ansi.h>

inherit "/inherit/misc/jboard";

void create()
{
        set_name(HIW" ***  "HIG"重大项目公告板 "HIW"***  "NOR, ({ "board" }) );

        set("location", "/d/wizard/meeting_room");
        
        set("board_id", "project_b");

        set("long", HIY"-------------------------------------"NOR+
		    HIY"-----------------------------------\n"NOR+

		    "  输入  "+HIC"project"NOR+"    下达新的计划任务。\n"+
		    "        "+HIC"report"NOR+"     报告任务完成情况。\n"+
		    "        "+HIC"learn"NOR+"       察看留言。        \n"+
		    "        "+HIC"terminate"NOR+"  删除留言。      \n\n"+
		    HIC"  以下是已提出来的任务的大致列表：       \n\n"NOR+

		    HIY"--------------------------------------"NOR+
		    HIY"----------------------------------\n\n"NOR
	   );

        setup();

        replace_program("/inherit/misc/jboard");
}
