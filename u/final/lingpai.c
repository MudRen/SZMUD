// Code by Scatter
// 令牌
//Modify by Newbe
//V. 1.02  03/31/2002 (Scatter)

#include <ansi.h>

inherit ITEM;

int do_search(string arg);
int do_dig(string arg);
int dox;

void create()
{
        set_name(HIY"挖矿令"NOR,({"ling pai", "lin", "pai"}));
        set_weight(1);
//        if (clonep())
//                set_default_object(__FILE__);
//        else {
                set("long", "这是一由这里管理员授与的挖矿令。\n");
                set("unit", "个");
                set("value", 8);
                set("no_get", 1);
                set("no_drop", 1);//Newbe   防止重复drop后再get
//        }

        setup();
}

void init()
{
        add_action("do_search", "search");
        add_action("do_dig", "dig");
        add_action("do_dig", "wa");
                
                add_action("do_err", "go");
                add_action("do_err", "east");
                add_action("do_err", "west");
                add_action("do_err", "north");
                add_action("do_err", "south");
                add_action("do_err", "e");
                add_action("do_err", "w");
                add_action("do_err", "n");
                add_action("do_err", "s");
                add_action("do_err", "northeast");
                add_action("do_err", "ne");
                add_action("do_err", "southeast");
                add_action("do_err", "se");
                add_action("do_err", "northwest");
                add_action("do_err", "nw");
                add_action("do_err", "southwest");
                add_action("do_err", "sw");
                add_action("do_err", "up");
                add_action("do_err", "u");
                add_action("do_err", "down");
                add_action("do_err", "d");
                add_action("do_err", "enter");
                add_action("do_err", "out");
}

int do_err(string arg)
{

        object me=this_player(), obj;
        if (objectp(obj = present("tin ore", me)) || objectp(obj = present("aluminium", me)) || objectp(obj = present("copper ore", me)) || objectp(obj = present("lead ore", me)) || objectp(obj = present("gold ore", me)) || objectp(obj = present("zinc ore", me)) || objectp(obj = present("silver ore", me)) || objectp(obj = present("iron ore", me)))
        {
                write("你拿着一块矿要到街上到处跑吗？\n");
                return 1;
        }
        return 0;
  
}

int do_search(string arg)
{
        int x, y;
        object weapon, me = this_player();

                if( me->query("jing") < 100 )
                                return notify_fail("你的精神不集中．\n");
                if( me->query("jingli") < 150 )
                                return notify_fail("你的精力不够．\n");


        if( !arg || arg!="here")
                return notify_fail("你要找甚么？\n");
                if(me->is_busy())
                                return notify_fail("你还正在忙耶．\n");

        if( !environment(me)->query("possearch") )
                return notify_fail("什么？\n");

        if( me->query_temp("kuang_lvl") )
        {
            write("快去挖矿吧！\n");
        }

        else
        {

        message_vision(HIW"$N东看看西看看，在努力寻找着矿\n"NOR, me);

        x = random(100);

        if( x < 70 )
        {
                         y = random(100);
                         if( y < 60 )
                         {
             message_vision(HIW"可惜什么也没找到\n"NOR, me);
             me->add("jing", -40);
             me->add("jingli", -53);
             me->start_busy( 2+random(3) );
                         }

                         else if( y < 80 )
                         {
                                 message_vision(HIR"$N一气之下运起内功向岩石打去\n"+ HIC +"只见石头一块一块的滚了下来把$N压到在地上\n"NOR, me);
                                 me->unconcious();
                         }

                         else
                         {
                                 message_vision(HIR"$N一脚站不稳摔到深渊了\n"NOR, me);
                                 me->set("jingli", 1000);
                                 command("rumor " + me->query("name") + "挖矿石摔到山谷死了");
                                 me->unconcious();
                                 me->add("qi", -100);
                                 me->add("jing", -100);
                                 me->add("jingli", -100);

                         }
                         
                         return 1;

        }

        else if( x < 85 )
        {
             message_vision(HIY"$N看见面前有一个闪闪发亮的东西，不知道是什么\n"NOR, me);
             me->add("jing", -40);
             me->add("jingli", -53);
             me->start_busy( 2+random(3) );
             dox = 1;
             me->set_temp("kuang_lvl", 1);
                         me->start_busy( 2+random(3) );
        }

        else if( x < 95 )
        {
             message_vision(HIC"$N看到一个不常看到的东西，好像看到一些有价值的原料\n"NOR, me);
             me->add("jing", -40);
             me->add("jingli", -53);
             me->start_busy( 2+random(3) );
             dox = 2;
             me->set_temp("kuang_lvl", 2);
                         me->start_busy( 2+random(3) );
        }

        else if( x < 97 )
        {
             message_vision(HIG"$N不敢相信自己的眼睛，好像看到稀有原料\n"NOR, me);
             me->add("jing", -40);
             me->add("jingli", -53);
             me->start_busy( 2+random(3) );
             dox = 3;
             me->set_temp("kuang_lvl", 3);
                         me->start_busy( 2+random(3) );
        }

        else
        {
            message_vision(HIR"$N什么都没找到，一气之下昏了过去\n"NOR, me);
            me->unconcious();
        }



        }

        return 1;
}



int do_dig(string arg)
{
//        int x;
        object newob, me = this_player(), env, tools;

        if( !objectp(tools = me->query_temp("weapon"))
        || (string)tools->query("id") != "gao"
        && (string)tools->query("id") != "qian"
        && (string)tools->query("id") != "chui")
                return notify_fail("你想用什么来挖矿?\n");//NEWBE added
                
        env = environment(me);
        if( !environment(me)->query("possearch") )
                return notify_fail("什么？\n");

        if( !me->query_temp("kuang_lvl") )
                return notify_fail("你要挖什么？\n");

//        x = me->query_temp("kuang_lvl");


        if( dox == 1 )
        {


             switch( random(2) )
             {
                 case 0:
                      newob = new("/newjob/tiejiang/obj/ore/copperore",1);
                      newob->set("no_get");
                      message_vision(HIY"$N使劲的挖，挖到全身都是汗水．\n"NOR, me);
					  newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
                 case 1:
                      newob = new("/newjob/tiejiang/obj/ore/leadore",1);
                      newob->set("no_get");
                      message_vision(HIY"$N使劲的挖，挖到全身都是汗水．\n"NOR, me);
					  newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
                 case 2:
                      newob = new("/newjob/tiejiang/obj/ore/ironore",1);
                      newob->set("no_get");
                      message_vision(HIY"$N使劲的挖，挖到全身都是汗水．\n"NOR, me);
					  newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
             }


        }

        else if ( dox == 2 )
        {
            switch( random(3) )
            {
                case 0:
                      newob = new("/newjob/tiejiang/obj/ore/tinore",1);
                      newob->set("no_get");
					  message_vision(HIY"$N使劲的挖，挖到全身都是汗水．\n"NOR, me);
                      newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
                case 1:
                      newob = new("/newjob/tiejiang/obj/ore/zinc",1);
                      newob->set("no_get");
                      message_vision(HIY"$N使劲的挖，挖到全身都是汗水．\n"NOR, me);
                      newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
                case 2:
                      newob = new("/newjob/tiejiang/obj/ore/luore",1);
                      newob->set("no_get");
                      message_vision(HIY"$N使劲的挖，挖到全身都是汗水．\n"NOR, me);
                      newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
                case 3:
                      newob = new("/newjob/tiejiang/obj/ore/silver",1);
                      newob->set("no_get");
                      message_vision(HIY"$N使劲的挖，挖到全身都是汗水．\n"NOR, me);
                      newob->set("owner", me->query("id"));
                      newob->move(me);
                      break;
            }
        }

        else if ( dox == 3 )
        {
                      newob = new("/newjob/tiejiang/obj/ore/goldore",1);
                      newob->set("no_get");
                      message_vision(HIY"$N使劲的挖，挖到全身都是汗水．\n"NOR, me);
                      newob->set("owner", me->query("id"));
                      newob->move(me);
        }

                me->delete_temp("kuang_lvl");
        return 1;
}
