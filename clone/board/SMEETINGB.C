// Write by Scatter
// /clone/board/smeetingb.c
// V1.0

#include <ansi.h>

inherit "/inherit/misc/jboard";

void create()
{
        set_name(HIY"【神州】开会通知和议题"NOR, ({ "board" }) );

        set("location", "/u/scatter/lobby");

        set("board_id", "meeting_b");

        set("long", HIY"-------------------------------------"NOR+
                    HIY"-----------------------------------\n"NOR+

                    "  输入  "+HIC"project"NOR+"    下达新的开会通知。\n"+
                    "        "+HIC"report"NOR+"     加入开会的讨论议题。\n"+
                    "        "+HIC"read"NOR+"       察看开会通知/议题。 \n"+
                    "        "+HIC"terminate"NOR+"  删除开会通知/议题。 \n\n"+
                    HIC"  以下是已提出来的开会通知：       \n\n"NOR+

                    HIY"--------------------------------------"NOR+
                    HIY"----------------------------------\n\n"NOR
           );

        setup();

        replace_program("/inherit/misc/jboard");
}
