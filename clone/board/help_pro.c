// Write by fengyu
// /clone/board/project_b.c
// 2001.8.16

#include <ansi.h>

inherit "/inherit/misc/jboard";

void create()
{
        set_name(HIG"HELP�ļ��޸ļƻ�"NOR, ({ "board" }) );

        set("location", "/d/city/guangchang");
        
        set("board_id", "help_pro");

        set("long", HIY"-------------------------------------"NOR+
		    HIY"-----------------------------------\n"NOR+

		    "        "+HIC"report"NOR+"     �ύHELP�ļ��޸Ľ��顣\n"+
		    "        "+HIC"refer"NOR+"      �鿴�ƻ����޸Ľ��顣        \n"+
		    "        "+HIC"terminate"NOR+"  ɾ���ƻ���      \n\n"+
		    HIC"  �������������������Ĵ����б�       \n\n"NOR+

		    HIY"--------------------------------------"NOR+
		    HIY"----------------------------------\n\n"NOR
	   );

        setup();

        replace_program("/inherit/misc/jboard");
}
