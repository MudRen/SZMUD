 //Team One Meeting Room

inherit ROOM;
#include <ansi.h>
#include "teamlist.h"

void create()
{
        set("short", "第一组铁匠秘密会议室");
        set("long", 
"如果你能到达这里，那么说明你已经得到我们的信任，成为我们中的一员。\n"
"我们的目标是建成最好的铁匠工作系统，也就是多职系统。这里所有的一切\n"
"都请严格对外保密。这里的规则也很简单──是，或者不是我们中的一员。\n"
"你可以用(teamlist)来察看其他成员。\n"
"-------------------------新闻快报-------------------------------\n"
"|"+HIM+"新闻: 工作表更新啦!!!!                                        "+NOR+" |\n"
"|"+HIW+"头条新闻: Keny 和 Kissme 成为神州创意的组员                   "+NOR+" |\n"
"|"+HIC+"公告: Keny 的 /newjob/tiejiang/ 的全现申请中                  "+NOR+" |\n"
//"|"+HIG+"如有任何误会, 请留一个 POST 谢谢                              "+NOR+" |\n"
"----------------------------------------------------------------\n"

"\n以下是你可以使用的指令\n"
"\n"+HIC+"(look joblist1)\n(look joblist2(未使用))\n(look news)\n(look announce)\n\n"+HIG+"最后更新时间:2/12/2002\n"+NOR+"\n"

);

        set("exits", ([
                "down" : "/d/wizard/wizard_room",
                "out" : "/u/snowlf/room/meeting_room"
                 ]));


        set("item_desc", ([
                "joblist1" : 
"----------------------------------------------------------------\n"
"|                           工作表                             |\n"
"----------------------------------------------------------------\n"
"| Kissme 请把 datietai.c 的描述做最后的修正                    |\n"
"----------------------------------------------------------------\n"
"| Keny 请把运送的车修好 / 重做                                 |\n"
"----------------------------------------------------------------\n",



                                "news" :
"----------------------------------------------------------------\n"
//"|"+HIW+"注意: 有任何相关的问题, 请先看看铁匠计画的 POST, 如果还是不清"+NOR+" |\n"
//"|      "+HIW+"楚, 可以问SCATTER."+NOR+"                                      |\n"
//"|"+HIM+"新闻: 我的目标是在这个礼拜把矿场和运送连起来                 "+NOR+" |\n"
"|"+HIM+"新闻: 目前无最新新闻                                         "+NOR+" |\n"
"----------------------------------------------------------------\n",





                                "announce":
"----------------------------------------------------------------\n"
"|"+HIC+"公告: 目前无任何公告                  .                      "+NOR+" |\n"
"|"+CYN+"最后更新时间: 2/12/2002                                     "+NOR+" |\n"
"----------------------------------------------------------------\n",
        ]));





        set("valid_startroom", 1);
        set("no_fight", "1");
        set("no_clean_up", 0);
        set("cost", 0);
        setup();

        "/clone/board/team_oneb.c"->foo();

}

void init()
{
        object me = this_player();

        if (wizhood(me) == "(player)") me->move("/d/death/death.c");
        else if ( !is_member(me) ) me->move("/d/wizard/wizard_room.c");
        
        add_action("teamlist","teamlist");
}

int teamlist()
{
        int i;

        for(i=0; i<sizeof(member); i++) write(member[i]+"\n");

        return 1;
}

