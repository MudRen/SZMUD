// Write by fengyu
// /clone/board/project_b.c
// 2001.8.16

#include <ansi.h>

inherit "/inherit/misc/jboard";

void create()
{
        set_name(HIW"��Ʒ������Ƽƻ�"NOR, ({ "board" }) );

        set("location", "/d/wizard/obj_r");
        
        set("board_id", "obj_pro");

        set("long", HIY"-------------------------------------"NOR+
		    HIY"-----------------------------------\n"NOR+

		    "  ����  "+HIC"project"NOR+"    �´��µļƻ�����\n"+
		    "        "+HIC"report"NOR+"     ����������������\n"+
		    "        "+HIC"learn"NOR+"       �쿴���ԡ�        \n"+
		    "        "+HIC"terminate"NOR+"  ɾ�����ԡ�      \n\n"+
		    HIC"  �������������������Ĵ����б�       \n\n"NOR+

		    HIY"--------------------------------------"NOR+
		    HIY"----------------------------------\n\n"NOR
	   );

        setup();

        replace_program("/inherit/misc/jboard");
}
