// Write by fengyu
// /clone/board/project_b.c
// 2001.8.16
// Modified by Buwu

#include <ansi.h>

inherit "/inherit/misc/jboard";

void create()
{
        set_name(HIG"���ѧϰ֮�����"NOR, ({ "bookshelf" }) );

        set("location", "/d/wizard/guide_r");
        
        set("board_id", "mudlib_b");

        set("long", HIY"-------------------------------------"NOR+
		    HIY"-----------------------------------\n"NOR+

		    "  ����  "+HIC"project"NOR+"    ���һ���µ�ר�⡣\n"+
		    "        "+HIC"report"NOR+"     ��ʵĳ��ר������ݡ�\n"+
		    "        "+HIC"learn"NOR+"       �쿴���顣        \n"+
		    "        "+HIC"terminate"NOR+"  ɾ�����顣      \n\n"+
		    HIC"  ���������еĲ����б�       \n\n"NOR+

		    HIY"--------------------------------------"NOR+
		    HIY"----------------------------------\n\n"NOR
	   );

        setup();

        replace_program("/inherit/misc/jboard");
}
