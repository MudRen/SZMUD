        //Created by Scatter
// Room: /u/scatter/workroom.c

#include <ansi.h>
#include <room.h>
//int do_gall();
inherit F_CLEAN_UP;
inherit ROOM;

void create()
{
        set("short", HIW"分冥子猪的豪宅"NOR);
        set("long", "这里就是分冥子的豪宅,目前他是负责"+HIW"古墓武功"+NOR"的巫师.\n往里面走(GO MOVIE), 就是分冥子的电影院. 现在上演的片名就是\n轰动武林的"+HIY"侠客行"+NOR". 是由"+YEL"分冥子"+NOR"导演. 和"+MAG"怀石"+NOR"热情赞助\n墙壁上挂着两句他的名言\n\n  成功绝对不是偶然的      \n\n            绝对的权利导致绝对的腐化\n\n以下是他挖的地下通道\n\n------------------------------------------------------\n华山hs，泉州qz，杨州yz，泰山ts，少林sl，武当wd，神龙sn \n丐帮gb，星宿xx，峨嵋em，白驼bt，雪山xs，昆仑kl，北京bj \n西夏xi，归云gy，大理dl，杭州hz，古墓gm，巫师wr， \n\n最新功能，可以打 iget <档案位置>\n最新功能，可以打 gall <档案位置> (记得 msg 在 givemsg 设定下喔)\n\n------------------------------------------------------\n");
        set("exits", ([ /* sizeof() == 3 */
                  "hs"  : "/d/huashan/buwei1",
                  "qz"  : "/d/quanzhou/zhongxin",
                  "yz"  : "d/city/kedian",
                  "ts"  : "/d/taishan/fengchan",
                  "sl"  : "/d/shaolin/guangchang1",
                  "wd"  : "/d/wudang/shanmen",
                  "sn"  : "/d/shenlong/tingkou",
                  "gb"  : "/d/gaibang/undertre",
                  "xx"  : "/d/xingxiu/xxh2",
                  "em"  : "/d/emei/hz_guangchang",
                  "bt"  : "/d/xingxiu/btyard",
                  "xs"  : "/d/xueshan/guangchang",
                  "kl"  : "/d/shaolin/guangchang1",
                  "bj"  : "/d/beijing/changanjie",
                  "xi"  : "/d/xixia/dawu",
                  "gy"  : "/d/taihu/qianyuan",
                  "dl"  : "/d/dali/wangfu1",
                  "hz"  : "/d/hangzhou/kedian",
                        "note"  : "/u/scatter/note",
                  "gm"  : "/d/gumu/dating",
                  "wr"  : "/d/wizard/meeting_room",
                  "enter"  : "/u/scatter/lobby",
                                  "newjob" : "/u/snowlf/room/meeting_room",
                  "movie" : "/u/scatter/intromovie.c",
]));
        set("no_clean_up", 0);
        set("outdoors", "beijing");
        set("cost", 2);
    set("no_fight", "1");
    set("no_clean_up", "1");

//      set("objects", ([
//              "/clone/board/scatter_mb" : 1,
//      ]));

        setup();
        call_other("/clone/board/gumu_skill_mb", "???");
//      replace_program(ROOM);
}

void init() 
{ 
        object me=this_player();
                add_action("do_iget", "iget"); 
                                add_action("do_gall", "gall");
}

int do_iget(string arg)
{
        object me = this_player(), ob;

        if(!arg)
        {
                write("什么??\n");
                return 1;
        }

        if(me->query("id") != "scatter" && me->query("name") != "分冥子")
        {
                write("你没得到授权不能使用这个东西\n");
                return 1;
        }

        ob = new(arg);
        ob->move(me);
        write("物品产生完毕，请不要做违法用途\n");
        return 1;
}


int do_gall(string what, object me)
{
    object ob, *ob_list, ob1;
    int i;
    string str;

        if(this_player()->query("id") != "scatter" && this_player()->query("name") != "分冥子")
    {
                write("你没得到授权不能使用这个东西\n");
        return 1;
    }
    
    if(!what) return notify_fail("指令格式 gall 物品路径\n");
    
    if( sscanf(what, "%*s.c") != 1) return notify_fail("路径不合法，无法找到物品。\n");
    
    if( file_size(what) < 0 )
                return notify_fail("没有这个档案(" + what + ")。\n");    
    
    seteuid(getuid());

    ob_list = users();

    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
        ob1 = new(what);
        ob1 -> move(ob); 
        tell_object(ob, HIG "分冥子" + this_player()->query("givemsg") + "。\n" NOR);
                     
    }
    str = sprintf("共有 %d 位玩家得到了%s。\n", sizeof(ob_list), what->query("name"));    
    this_player()->start_more(str);
    return 1;
}
