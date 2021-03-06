// Write by fengyu
// /clone/board/project_b.c
// 2001.8.16
// Modified by Buwu

#include <ansi.h>

inherit "/inherit/misc/jboard";

void create()
{
        set_name(HIG"编程学习之藏书架"NOR, ({ "bookshelf" }) );

        set("location", "/d/wizard/guide_r");
        
        set("board_id", "mudlib_b");

        set("long", HIY"-------------------------------------"NOR+
		    HIY"-----------------------------------\n"NOR+

		    "  输入  "+HIC"project"NOR+"    添加一个新的专题。\n"+
		    "        "+HIC"report"NOR+"     充实某个专题的内容。\n"+
		    "        "+HIC"learn"NOR+"       察看藏书。        \n"+
		    "        "+HIC"terminate"NOR+"  删除藏书。      \n\n"+
		    HIC"  以下是已有的藏书列表：       \n\n"NOR+

		    HIY"--------------------------------------"NOR+
		    HIY"----------------------------------\n\n"NOR
	   );

        setup();

        replace_program("/inherit/misc/jboard");
}
