//V 1.2
//3/29/2002
//同时增加匹配IP
#define ANTI_CHKIP "/newjob/tiejiang/ipcheck.c"
#include <ansi.h>

inherit ITEM;

//#include "/newjob/tiejiang/list.h"
//#define _DES 
 
void create()
{
        set_name(HIY"打铁台"NOR,( {"datie tai","datie","tai"} ));
        set_weight(3000);
        if (clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","张");
                set("long","
    这是一张很结实的打铁台，由整块的"+HIW+"花岗石"+NOR+"做的台基和很厚的铸铁台面组成
的，铁匠们就是在这上面锻造出他们的一件作品的。快看看火炉里的东西烧得怎
么样了吧，打铁要乘热哦！\n");
                set("value",10000);
                set("material","bronze");
                set("no_get",1);
        }
        setup();
}




void init()
{
        add_action("do_fang","fang"); 
                add_action("do_rong","rong"); 
                add_action("do_rong","melt");
                add_action("do_zhu","zhu"); 
                add_action("do_da","da");
}




int do_fang(string arg)
{
        object me, obj,ob;
        string item, target; 
        int maxstr, result;
		result = ANTI_CHKIP->do_chkip(this_player(), this_object());

        me = this_player();
        ob = this_object();
        if(result!=1)
        {
                return notify_fail("要那么多人打铁？");
        }
        if (!arg || sscanf(arg, "%s in %s", item, target) != 2)
            return notify_fail("你要将什么东西放进哪里？\n");
        
        if (item == "all" ) 
                return notify_fail("你这是要干什么, 浪费资源吗？\n");

        if (!objectp(obj = present(item, me)))
                return notify_fail("东西呢？\n");

                
        if (!obj->query("kuang"))
                return notify_fail("你没事放什么不相干的东西上来干麻呀。\n");


                maxstr = maxstr + obj->query("strvalue");


                me->set_temp("tiejiang/maxstr", maxstr);

        message_vision("$N把一"+obj->query("unit")+obj->query("name")+"放到打铁台上\n如果要开始溶化，请打(rong)\n",me);

                me->set_temp("tiejiang/itemadd", 1);

        destruct(obj);

        return 1;

}



int do_rong(string arg)
{
        object me;
    string item, target; 
        me = this_player();


        //Testing Condition
        if(!me->query_temp("tiejiang/itemadd"))
                return notify_fail("你要溶化什么？\n");


        //Check for Min Neili
        if(me->query("neili") < 300)
                return notify_fail("你的内力不够\n");


        //Check for Min Jingli
        if(me->query("jingli") < 400)
                return notify_fail("你的精力不够\n");


        //Check for Min Qi
        if(me->query("qi") < 100)
                return notify_fail("你都快死了，哪还有办法□铁？\n");

        //Display Message
        message_vision("\n"HIR"热热的火焰将铁一点一点的溶化中。\n"NOR,me);


        //Clear the Switch
        me->delete_temp("tiejiang/itemadd");


        //Began to call out functions.
        remove_call_out("rong");
    call_out("rong",5+random(5),me);


        return 1;
}


void rong(object me)
{
    //Define Var.
        int intQi, intJingli, intNeili, skilld, skillt;

        //Display Message
        message_vision("\n"HIY"在$N面前的铁矿被融成橘红色的铁浆了。\n"NOR,me);
        message_vision("\n"HIW"看起来是时候开始铸铁了(zhu)。\n"NOR,me);
        
       skilld = random(50) ;
       skillt = random(50) ;
        
        //Calculate the QI/Jingli/Neili Damage
        intQi = -(random(23) + 75) + skilld;
        intJingli = -(random(100) + 300) + skilld;
        intNeili = -(random(170) + 130) + skilld;

        //Apply Effect
        me->add("qi", intQi);
        me->add("jingli", intJingli);
        me->add("neili", intNeili);
        
        //Set Switch for finish rong item
        me->set_temp("tiejiang/rong", 1);

        //Give Busy time
        me->start_busy(random(5) + 2);

        return;
}


int do_zhu(string arg)
{
        //Define Varible
        object me;
    string item, target; 
        me = this_player();



        //Check if Busy
        if ( me->is_busy() )
                return notify_fail("你还在忙呀．\n");
        

        //Check if have done "RONG" process
        if ( !me->query_temp("tiejiang/rong") )
                return notify_fail("你没有□铁，你要怎么铸铁呀？\n");
        

        //Check for Min QI
        if ( me->query("qi") < 300 )
                return notify_fail("你是不要命了吗？\n");

        //Check for Min Jingli
        if ( me->query("jingli") < 300 )
                return notify_fail("你是想累死你自己吗？\n");

        //Check for Min Neili
        if ( me->query("neili") < 300 )
                return notify_fail("你的内力不够．\n");

        //Display Message
        message_vision("\n"HIC"$N将铁浆灌入剑的模型中。\n"NOR,me);


        //Stop Call Out
        remove_call_out("zhu");

        //Delete Current Temp
        me->delete_temp("tiejiang/rong");

        //Call Function with Time Limit
    call_out("zhu",10+random(6),me);


        return 1;
}


void zhu(object me)
{
        //Define Local Varible
        int intQi, intJingli, intNeili, skilld, skillt;


        skilld = random(50) / 10;
        skillt = random(50) / 10;

        //Calculate the Damage to Player
        intQi = -(random(50) + 250) + skilld;
        intJingli = -(random(100) + 200) + skilld;
        intNeili = -(random(20) + 280) + skilld;

        //Display Message
        message_vision("\n"HIM"看起来差不多可以开始打铁了。(da)\n"NOR,me);

        //Add Switch for Zhu
        me->set_temp("tiejiang/zhu", 1);

        //Apply Damage to Player
        me->add("qi", intQi);
        me->add("neili", intNeili);
        me->add("jingli", intJingli);

        //Began to make Player Busy
        me->start_busy(random(15) + 5);


        return;
}

int do_da(string arg)
{
        object me;
        int intSkill, intMaxPt, intMaxPtF;
    string item, target; 
        
        me = this_player();

        //Check if Busy
        if ( me->is_busy() )
                return notify_fail("你还在忙呀．\n");

        //Check if have done "ZHU" process
        if ( !me->query_temp("tiejiang/zhu") )
                return notify_fail("你没有铸铁，你要怎么打铁呀？\n");
        

        //Check for Min QI
        if ( me->query("qi") < 300 )
                return notify_fail("你是不要命了吗？\n");

        //Check for Min Jingli
        if ( me->query("jingli") < 300 )
                return notify_fail("你是想累死你自己吗？\n");

        //Check for Min Neili
        if ( me->query("neili") < 300 )
                return notify_fail("你的内力不够．\n");


        //Get data from Player
        intSkill = random(50);
        intMaxPt = me->query_temp("tiejiang/maxstr");

        //Calculation
        intMaxPtF = intMaxPt + (intSkill / 5);
        
        //Stop Call Out
        remove_call_out("select_menu");

        //Fake Message
        write("系统侦测可制照的物品中\n");
        me->delete_temp("tiejiang/zhu");
        
                
        //Set the Data into player
        me->set_temp("tiejiang/maxstr", intMaxPtF);

        //Call Function with Time Limit
    call_out("select_menu",1,me);

        return 1;
}

void select_menu(object me)
{
        write("\n******************************************\n");
        write("*      请选择你要做的东西 (V. 1.1)       *\n");
        write("*        最后更新日期 2/21/2002          *\n");
        write("******************************************\n");
        write("* **************                         *\n");
        write("* *   标准区   *                         *\n");
        write("* **************                         *\n");
        write("* 1) 一般菜刀                            *\n"); // 1 LVL Limit
        write("* 2) 中等菜刀                            *\n"); //10 LVL Limit
        write("* 3) 高级菜刀                            *\n"); //30 LVL Limit
        write("* ---------------------------------------*\n");
        write("* 4) 一般钢剑                            *\n"); // 1 LVL Limit
        write("* 5) 中等钢剑                            *\n"); //10 LVL Limit
        write("* 6) 高级钢剑                            *\n"); //30 LVL Limit
        write("* ---------------------------------------*\n");
        write("* 7) 一般钢刀                            *\n"); // 1 LVL Limit
        write("* 8) 中等钢刀                            *\n"); //10 LVL Limit
        write("* 9) 高级钢刀                            *\n"); //30 LVL Limit
        write("* ---------------------------------------*\n");
        write("*10) 一般护具                            *\n"); // 5 LVL Limit
        write("*11) 中等护具                            *\n"); //20 LVL Limit
        write("*12) 高级护具                            *\n"); //40 LVL Limit
        write("* ---------------------------------------*\n");
        write("* **************                         *\n");
        write("* *   自订区   *                         *\n");
        write("* **************                         *\n");
        write("*13) 刀   (目前暂时关闭)                 *\n"); // > 50 LVL Limit
        write("*14) 剑                                  *\n"); // > 50 LVL Limit
        write("*15) 护具 (目前暂时关闭)                 *\n"); // > 50 LVL Limit
        write("******************************************\n"); // > 50 LVL Limit
        write("\n enter 选项\n");

        add_action("smenu", "enter");

        return;
}


int smenu(string arg)
{
        object me = this_player();
        int uSelect, uLvl;

        uSelect = atoi(arg);
        uLvl = random(50);

        remove_action("smenu", "enter");



        switch(uSelect)
        {
                case 1:
                        {
                                if (uLvl >= 1)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("对不起，你对打铁术了解不够多，目前不能执行这个工作．\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }


                case 2:
                        {
                                if (uLvl >= 10)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("对不起，你对打铁术了解不够多，目前不能执行这个工作．\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }


                case 3:
                        {
                                if (uLvl >= 30)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("对不起，你对打铁术了解不够多，目前不能执行这个工作．\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }

                case 4:
                        {
                                if (uLvl >= 1)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("对不起，你对打铁术了解不够多，目前不能执行这个工作．\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }

                case 5:
                        {
                                if(uLvl >= 10)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("对不起，你对打铁术了解不够多，目前不能执行这个工作．\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }


                case 6:
                        {
                                if(uLvl >= 30)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }


                                else
                                {
                                        write("对不起，你对打铁术了解不够多，目前不能执行这个工作．\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }


                case 7:
                        {
                                if(uLvl >= 1)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("对不起，你对打铁术了解不够多，目前不能执行这个工作．\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }

                case 8:
                        {
                                if(uLvl >= 10)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("对不起，你对打铁术了解不够多，目前不能执行这个工作．\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }


                case 9:
                        {
                                if(uLvl >= 30)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("对不起，你对打铁术了解不够多，目前不能执行这个工作．\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }

                case 10:
                        {
                                if(uLvl >= 5)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("对不起，你对打铁术了解不够多，目前不能执行这个工作．\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }


                case 11:
                        {
                                if(uLvl >= 20)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("对不起，你对打铁术了解不够多，目前不能执行这个工作．\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }

                case 12:
                        {
                                if(uLvl >= 40)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("对不起，你对打铁术了解不够多，目前不能执行这个工作．\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }

                case 13:
                        {
                                if(uLvl >= 50)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("对不起，你对打铁术了解不够多，目前不能执行这个工作．\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }

                case 14:
                        {
                                if(uLvl >= 50)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("对不起，你对打铁术了解不够多，目前不能执行这个工作．\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }


                case 15:
                        {
                                if(uLvl >= 50)
                                {
                                        me->set_temp("tiejiang/select", uSelect);
                                }

                                else
                                {
                                        write("对不起，你对打铁术了解不够多，目前不能执行这个工作．\n");
                                        remove_call_out("select_menu");
                                        call_out("select_menu",1,me);
                                }
                                break;
                        }
        }


        remove_call_out("processm");
        call_out("processm",1,me);
        
        return 1;
}





void processm(object me)
{
        int intSel;

        intSel = me->query_temp("tiejiang/select");
        me->delete_temp("tiejiang/select");

        switch(intSel)
        {
        case 1:
                {
                        //1) 一般菜刀
                        write("资料处里中...");
                        remove_call_out("b_caidao");
                        call_out("b_caidao",1,me);
                        break;
                }
        case 2:
                {
                        //2) 中等菜刀
                        write("资料处里中...");
                        remove_call_out("m_caidao");
                        call_out("m_caidao",1,me);
                        break;
                }
        case 3:
                {
                        //3) 高级菜刀
                        write("资料处里中...");
                        remove_call_out("a_caidao");
                        call_out("a_caidao",1,me);
                        break;
                }
        case 4:
                {
                        //4) 一般钢剑
                        write("资料处里中...");
                        remove_call_out("b_gangjian");
                        call_out("b_gangjian",1,me);
                        break;
                }
        case 5:
                {
                        //5) 中等钢剑
                        write("资料处里中...");
                        remove_call_out("m_gangjian");
                        call_out("m_gangjian",1,me);
                        break;
                }
        case 6:
                {
                        //6) 高级钢剑
                        write("资料处里中...");
                        remove_call_out("a_gangjian");
                        call_out("a_gangjian",1,me);
                        break;
                }
        case 7:
                {
                        //7) 一般钢刀
                        write("资料处里中...");
                        remove_call_out("b_blade");
                        call_out("b_blade",1,me);
                        break;
                }
        case 8:
                {
                        //8) 中等钢刀
                        write("资料处里中...");
                        remove_call_out("m_blade");
                        call_out("m_blade",1,me);
                        break;
                }
        case 9:
                {
                        //9) 高级钢刀
                        write("资料处里中...");
                        remove_call_out("a_blade");
                        call_out("a_blade",1,me);
                        break;
                }
        case 10:
                {
                        //10) 一般护具
                        write("资料处里中...");
                        remove_call_out("b_armor");
                        call_out("b_armor",1,me);
                        break;
                }
        case 11:
                {
                        //11) 中等护具
                        write("资料处里中...");
                        remove_call_out("m_armor");
                        call_out("m_armor",1,me);
                        break;
                }
        case 12:
                {
                        //12) 高级护具
                        write("资料处里中...");
                        remove_call_out("a_armor");
                        call_out("a_armor",1,me);
                        break;
                }
        case 13:
                {
                        //13) 刀
                        write("资料处里中...");
                        remove_call_out("s_blade");
                        call_out("s_blade",1,me);
                        break;
                }
        case 14:
                {
                        //14) 剑
                        write("资料处里中...");
                        remove_call_out("s_jian");
                        call_out("s_jian",1,me);
                        break;
                }
        case 15:
                {
                        //15) 护具
                        write("资料处里中...");
                        remove_call_out("s_armor");
                        call_out("s_armor",1,me);
                        break;
                }
        }

        return;
}


//Basic Caidao
void b_caidao(object me)
{
        message_vision("\n"HIR"$N开始打铁了。\n"NOR,me);
        message_vision("\n"HIY"$N弄得全身都是汗。\n"NOR,me);        
        remove_call_out("b_caidaoa");
        call_out("b_caidaoa",5 + random(10),me);

        return;
}
void b_caidaoa(object me)
{
        object ob;

        message_vision("\n"HIC"终于打造好了。\n"NOR,me);
        ob = new("/newjob/tiejiang/obj/bcaidao");
        me->improve_skill("tiejiang", random(50));
        me->improve_skill("datieshu", random(50));
        ob->move(me);

        return;
}




//Medium Caidao
void m_caidao(object me)
{
        message_vision("\n"HIR"$N开始打铁了。\n"NOR,me);
        message_vision("\n"HIY"$N弄得全身都是汗。\n"NOR,me);
        
        remove_call_out("m_caidaoa");
        call_out("m_caidaoa",8 + random(10),me);

        return;
}
void m_caidaoa(object me)
{
        object ob;

        message_vision("\n"HIC"终于打造好了。\n"NOR,me);
        me->improve_skill("tiejiang", random(50));
        me->improve_skill("datieshu", random(50));        
        ob = new("/newjob/tiejiang/obj/mcaidao");
        ob->move(me);

        return;
}





//Advance Caidao
void a_caidao(object me)
{
        message_vision("\n"HIR"$N开始打铁了。\n"NOR,me);
        message_vision("\n"HIY"$N弄得全身都是汗。\n"NOR,me); 
        
        remove_call_out("a_caidaoa");
        call_out("a_caidaoa",10 + random(10),me);

        return;
}
void a_caidaoa(object me)
{
        object ob;

        message_vision("\n"HIC"$N于打造好了。\n"NOR,me);
        me->improve_skill("tiejiang", random(50));
        me->improve_skill("datieshu", random(50));
        ob = new("/newjob/tiejiang/obj/acaidao");
        ob->move(me);

        return;
}



//Basic Gangjian
void b_gangjian(object me)
{
        message_vision("\n"HIR"$N开始打铁了。\n"NOR,me);
        message_vision("\n"HIY"$N弄得全身都是汗。\n"NOR,me);        
        remove_call_out("b_gangjiana");
        call_out("b_gangjiana",5 + random(10),me);

        return;
}

void b_gangjiana(object me)
{
        object ob;

        message_vision("\n"HIC"终于打造好了。\n"NOR,me);
        ob = new("/newjob/tiejiang/obj/bgangjian");
        ob->move(me);
        me->improve_skill("tiejiang", random(50));
        me->improve_skill("datieshu", random(50));        return;
}



//Medium Gangjian
void m_gangjian(object me)
{
        message_vision("\n"HIR"$N开始打铁了。\n"NOR,me);
        message_vision("\n"HIY"$N弄得全身都是汗。\n"NOR,me);        
        remove_call_out("m_gangjiana");
        call_out("m_gangjiana",8 + random(10),me);

        return;
}

void m_gangjiana(object me)
{
        object ob;

        message_vision("\n"HIC"终于打造好了。\n"NOR,me);
        ob = new("/newjob/tiejiang/obj/mgangjian");
        ob->move(me);
                me->improve_skill("tiejiang", random(50));
        me->improve_skill("datieshu", random(50));

        return;
}



//Advance Gangjian
void a_gangjian(object me)
{
        message_vision("\n"HIR"$N开始打铁了。\n"NOR,me);
        message_vision("\n"HIY"$N弄得全身都是汗。\n"NOR,me);
        
        remove_call_out("a_gangjiana");
        call_out("a_gangjiana",10 + random(10),me);

        return;
}

void a_gangjiana(object me)
{
        object ob;

        message_vision("\n"HIC"终于打造好了。\n"NOR,me);
        me->improve_skill("tiejiang", random(50));
        me->improve_skill("datieshu", random(50));
        ob = new("/newjob/tiejiang/obj/agangjian");
        ob->move(me);

        return;
}


//Basic Blade
void b_blade(object me)
{
        message_vision("\n"HIR"$N开始打铁了。\n"NOR,me);
        message_vision("\n"HIY"$N弄得全身都是汗。\n"NOR,me);
        
        remove_call_out("b_bladea");
        call_out("b_bladea",5 + random(10),me);

        return;
}

void b_bladea(object me)
{
        object ob;

        message_vision("\n"HIC"终于打造好了。\n"NOR,me);
        me->improve_skill("tiejiang", random(50));
        me->improve_skill("datieshu", random(50));
        ob = new("/newjob/tiejiang/obj/bblade");
        ob->move(me);

        return;
}



//Medium Blade
void m_blade(object me)
{
        message_vision("\n"HIR"$N开始打铁了。\n"NOR,me);
        message_vision("\n"HIY"$N弄得全身都是汗。\n"NOR,me);
        
        remove_call_out("m_bladea");
        call_out("m_bladea",8 + random(10),me);

        return;
}

void m_bladea(object me)
{
        object ob;

        message_vision("\n"HIC"终于打造好了。\n"NOR,me);
        me->improve_skill("tiejiang", random(50));
        me->improve_skill("datieshu", random(50));
        ob = new("/newjob/tiejiang/obj/mblade");
        ob->move(me);

        return;
}



//Advance Blade
void a_blade(object me)
{
        message_vision("\n"HIR"$N开始打铁了。\n"NOR,me);
        message_vision("\n"HIY"$N弄得全身都是汗。\n"NOR,me);
        
        remove_call_out("a_bladea");
        call_out("a_bladea",10 + random(10),me);

        return;
}

void a_bladea(object me)
{
        object ob;

        message_vision("\n"HIC"终于打造好了。\n"NOR,me);
        me->improve_skill("tiejiang", random(50));
        me->improve_skill("datieshu", random(50));
        ob = new("/newjob/tiejiang/obj/ablade");
        ob->move(me);

        return;
}



//Basic Armor
void b_armor(object me)
{
        message_vision("\n"HIR"$N开始打铁了。\n"NOR,me);
        message_vision("\n"HIY"$N弄得全身都是汗。\n"NOR,me);
        
        remove_call_out("b_armora");
        call_out("b_armora",5 + random(10),me);

        return;
}

void b_armora(object me)
{
        object ob;

        message_vision("\n"HIC"终于打造好了。\n"NOR,me);
        me->improve_skill("tiejiang", random(50));
        me->improve_skill("datieshu", random(50));
        ob = new("/newjob/tiejiang/obj/barmor");
        ob->move(me);

        return;
}


//Medium Armor
void m_armor(object me)
{
        message_vision("\n"HIR"$N开始打铁了。\n"NOR,me);
        message_vision("\n"HIY"$N弄得全身都是汗。\n"NOR,me);
        
        remove_call_out("m_armora");
        call_out("m_armora",5 + random(10),me);

        return;
}

void m_armora(object me)
{
        object ob;

        message_vision("\n"HIC"终于打造好了。\n"NOR,me);
        me->improve_skill("tiejiang", random(50));
        me->improve_skill("datieshu", random(50));
        ob = new("/newjob/tiejiang/obj/marmor");
        ob->move(me);

        return;
}


//Advance Armor
void a_armor(object me)
{
        message_vision("\n"HIR"$N开始打铁了。\n"NOR,me);
        message_vision("\n"HIY"$N弄得全身都是汗。\n"NOR,me);
        
        remove_call_out("a_armora");
        call_out("a_armora",5 + random(10),me);

        return;
}

void a_armora(object me)
{
        object ob;

        message_vision("\n"HIC"终于打造好了。\n"NOR,me);
        me->improve_skill("tiejiang", random(50));
        me->improve_skill("datieshu", random(50));
        ob = new("/newjob/tiejiang/obj/aarmor");
        ob->move(me);

        return;
}










//********************************************************************
//********************************************************************
//********************** SELF MADE OBJECT START **********************
//********************************************************************
//********************************************************************

void s_blade(object me)
{
        int intMaxPtF;
                intMaxPtF = me->query_temp("tiejiang/maxstr");

                //Display Text
        write("你最多可以花费 " + intMaxPtF + " 点(不包括基本武器的性质)\n");
        write("请现在选择如何分配你所要的点数\n注意: 请先算好，打错没有可以改的机会．\n\n");
        
        //Ask Dmage Question
        write("杀伤力[20] / 耐用度[25] / 锋利度[20] / 重量(越大越轻) [10]\n");
        

        //Print how much points left
        write("请输入杀伤力: (所剩点数 " + intMaxPtF + ")[指令 - add 点数]\n");
        

        //Add new function to pass on data
        add_action("do_damageb", "add");

        return;
}



void s_jian(object me)
{
        int intMaxPtF;
        intMaxPtF = me->query_temp("tiejiang/maxstr");

        //Display Text
        write("你最多可以花费 " + intMaxPtF + " 点(不包括基本武器的性质)\n");
        write("请现在选择如何分配你所要的点数\n注意: 请先算好，打错没有可以改的机会．\n\n");
        
        //Ask Dmage Question
        write("杀伤力[20] / 耐用度[25] / 锋利度[20] / 重量(越大越轻) [10]\n");
        

        //Print how much points left
        write("请输入杀伤力: (所剩点数 " + intMaxPtF + ")[指令 - add 点数]\n");
        

        //Add new function to pass on data
        add_action("do_damage", "add");

        return;
}


void s_armor(object me)
{
        int intMaxPtF;
        intMaxPtF = me->query_temp("tiejiang/maxstr");

        //Display Text
        write("你最多可以花费 " + intMaxPtF + " 点(不包括基本武器的性质)\n");
        write("请现在选择如何分配你所要的点数\n注意: 请先算好，打错没有可以改的机会．\n\n");
        
        //Ask Dmage Question
        write("坚硬度[20] / 耐用度[25] / 纯度[20] / 重量(越大越轻) [10]\n");
        

        //Print how much points left
        write("请输入坚硬度: (所剩点数 " + intMaxPtF + ")[指令 - add 点数]\n");
        

        //Add new function to pass on data
        add_action("do_damagea", "add");

        return;
}






//***********************************************************
//***********************************************************
//******************* INPUT FOR SWORD ***********************
//***********************************************************
//***********************************************************

int do_damage(string arg)
{
        //Declear Varible
        object me;
        int intPt, intDamage, intX;
        
        //Define me
        me = this_player();

        //getting data
        intPt = me->query_temp("tiejiang/maxstr");
        
        //Convert Arg Format from String to Int
        intX = atoi(arg);

        //Calculation
        intPt = intPt - intX;

        //Error Checking
        if ( intPt < 0 )
                return notify_fail("点数超过，请再输入一次");

        //Delete action
        remove_action("do_damage", "add");


        //Calculate damage
        intDamage = 20 + intX;

        me->set_temp("tiejiang/damage", intDamage);
                
        me->set_temp("tiejiang/maxstr", intPt);
        

        write("请输入耐用度: (所剩点数 " + intPt + ")[指令 - add 点数]\n");

        add_action("do_strength", "add");       

        return 1;
}

int do_strength(string arg)
{
        object me;
        int intPt, intStr, intX;
        
        me = this_player();

        intPt = me->query_temp("tiejiang/maxstr");

        intX = atoi(arg);

        intPt = intPt - intX;


        intStr = 25 + intX;

        if ( intPt < 0 )
                return notify_fail("点数超过，请再输入一次");

        remove_action("do_strength", "add");

        me->set_temp("tiejiang/strength", intStr);
        me->set_temp("tiejiang/maxstr", intPt);

        write("请输入锋利度: (所剩点数 " + intPt + ")[指令 - add 点数]\n");

        add_action("do_sharp", "add");

        return 1;
}

int do_sharp(string arg)
{
        object me;
        int intPt, intSharp, intX;
        
        me = this_player();

        intPt = me->query_temp("tiejiang/maxstr");

        intX = atoi(arg);

        intPt = intPt - intX;

        if ( intPt < 0 )
                return notify_fail("点数超过，请再输入一次");

        remove_action("do_sharp", "add");

        intSharp = 20 + intX;

        me->set_temp("tiejiang/sharp", intSharp);
        me->set_temp("tiejiang/maxstr", intPt);

        write("请输入重量(越大越轻): (所剩点数 " + intPt + ")[指令 - add 点数]\n");

        add_action("do_weight", "add");

        return 1;
}

int do_weight(string arg)
{
        object me;
        int intPt, intWei, intSharp, intStr, intDamage, intX;
        
        me = this_player();

        intPt = me->query_temp("tiejiang/maxstr");
        intX = atoi(arg);
        intPt = intPt - intX;

        if ( intPt < 0 )
                return notify_fail("点数超过，请再输入一次");

        remove_action("do_weight", "add");

        intWei = 10 + intX;
        intSharp = me->query_temp("tiejiang/sharp");
        intStr = me->query_temp("tiejiang/strength");
        intDamage = me->query_temp("tiejiang/damage");

        me->set_temp("tiejiang/weight", intWei);
        me->set_temp("tiejiang/maxstr", intPt);
        me->delete_temp("tiejiang/zhu");

        write("杀伤力[" + intDamage + "] / 耐用度[" + intStr + "] / 锋利度[" + intSharp + "] / 重量(越大越轻) [" + intWei + "]\n");

        message_vision("\n"HIR"$N开始打铁了。\n"NOR,me);
        message_vision("\n"HIY"$N弄得全身都是汗。\n"NOR,me);
        
        
        //Stop Call Out
        remove_call_out("finish");

        //Call Function with Time Limit
    call_out("finish",20+random(6),me);



        return 1;
}

void finish(object me)
{
        int intPt, intWei, intSharp, intStr, intDamage;

        intWei = me->query_temp("tiejiang/weight");
        intSharp = me->query_temp("tiejiang/sharp");
        intStr = me->query_temp("tiejiang/strength");
        intDamage = me->query_temp("tiejiang/damage");


        message_vision("\n"HIC"武器打造好了。\n"NOR,me);
        write("请问这把武器要叫什么名字(英文)[请用 enter 名字]？\n");

        add_action("do_name", "enter");
        
        return;

}

int do_name(string arg)
{
        object me;
        me = this_player();

        remove_action("do_name", "enter");
        me->set_temp("tiejiang/wename", arg);

        write("请问这把武器要叫什么名字(中文)[请用 enter 名字]？\n");

        add_action("do_cname", "enter");
        
        return 1;
}


int do_cname(string arg)
{
        object me, ob;
        int intPt, intWei, intSharp, intStr, intDamage, intdam;
        string strEName, strCName;

        me = this_player();


        remove_action("do_cname", "enter");

        intWei = me->query_temp("tiejiang/weight");
        intSharp = me->query_temp("tiejiang/sharp");
        intStr = me->query_temp("tiejiang/strength");
        intDamage = me->query_temp("tiejiang/damage");
        strEName = me->query_temp("tiejiang/wename");
        strCName = arg;
        intdam = intDamage * 2;


        me->set("tiejiang/weight", intWei);
        me->set("tiejiang/sharp", intSharp);
        me->set("tiejiang/strength", intStr);
        me->set("tiejiang/damage", intDamage);
        me->set("tiejiang/adamage", intdam);
        me->set("tiejiang/wname", strCName);
        me->set("tiejiang/wnamee", strEName);


        ob = new("/newjob/tiejiang/obj/ssword");
//      ob->set("name", strCName);
//      ob->set("id", strEName);
        ob->set("long", "杀伤力[" + intDamage + "] / 耐用度[" + intStr + "] / 锋利度[" + intSharp + "] / 重量(越大越轻) [" + intWei + "]\n");
        ob->set("tiejiang/weight", intWei);
        ob->set("tiejiang/sharp", intSharp);
        ob->set("tiejiang/strength", intStr);
        ob->set("tiejiang/damage", intDamage);
        ob->set("tiejiang/adamage", intdam);
        ob->set("tiejiang/wname", strCName);
        ob->set("tiejiang/wnamee", strEName);
        
//      ob->set("tiejiang/weight", intWei);
//      ob->set("tiejiang/sharp", intSharp);
//      ob->set("tiejiang/strength", intStr);
//      ob->set("tiejiang/damage", intDamage);
//      ob->apply_damage(intdam);
        ob->move(me);

        message_vision("\n"HIR"$N打造完毕了，看起来$N似乎很满意。\n"NOR,me);    
        me->improve_skill("tiejiang", 5+random(5) ); 
        me->improve_skill("datieshu", 5+random(5) );

        return 1;
}





//***********************************************************
//***********************************************************
//******************* INPUT FOR BLADE ***********************
//***********************************************************
//***********************************************************

int do_damageb(string arg)
{
        //Declear Varible
        object me;
        int intPt, intDamage, intX;
        
        //Define me
        me = this_player();

        //getting data
        intPt = me->query_temp("tiejiang/maxstr");
        
        //Convert Arg Format from String to Int
        intX = atoi(arg);

        //Calculation
        intPt = intPt - intX;

        //Error Checking
        if ( intPt < 0 )
                return notify_fail("点数超过，请再输入一次");

        //Delete action
        remove_action("do_damageb", "add");


        //Calculate damage
        intDamage = 20 + intX;

        me->set_temp("tiejiang/damage", intDamage);
                
        me->set_temp("tiejiang/maxstr", intPt);
        

        write("请输入耐用度: (所剩点数 " + intPt + ")[指令 - add 点数]\n");

        add_action("do_strengthb", "add");      

        return 1;
}

int do_strengthb(string arg)
{
        object me;
        int intPt, intStr, intX;
        
        me = this_player();

        intPt = me->query_temp("tiejiang/maxstr");

        intX = atoi(arg);

        intPt = intPt - intX;


        intStr = 25 + intX;

        if ( intPt < 0 )
                return notify_fail("点数超过，请再输入一次");

        remove_action("do_strengthb", "add");

        me->set_temp("tiejiang/strength", intStr);
        me->set_temp("tiejiang/maxstr", intPt);

        write("请输入锋利度: (所剩点数 " + intPt + ")[指令 - add 点数]\n");

        add_action("do_sharpb", "add");

        return 1;
}

int do_sharpb(string arg)
{
        object me;
        int intPt, intSharp, intX;
        
        me = this_player();

        intPt = me->query_temp("tiejiang/maxstr");

        intX = atoi(arg);

        intPt = intPt - intX;

        if ( intPt < 0 )
                return notify_fail("点数超过，请再输入一次");

        remove_action("do_sharpb", "add");

        intSharp = 20 + intX;

        me->set_temp("tiejiang/sharp", intSharp);
        me->set_temp("tiejiang/maxstr", intPt);

        write("请输入重量(越大越轻): (所剩点数 " + intPt + ")[指令 - add 点数]\n");

        add_action("do_weightb", "add");

        return 1;
}

int do_weightb(string arg)
{
        object me;
        int intPt, intWei, intSharp, intStr, intDamage, intX;
        
        me = this_player();

        intPt = me->query_temp("tiejiang/maxstr");
        intX = atoi(arg);
        intPt = intPt - intX;

        if ( intPt < 0 )
                return notify_fail("点数超过，请再输入一次");

        remove_action("do_weightb", "add");

        intWei = 10 + intX;
        intSharp = me->query_temp("tiejiang/sharp");
        intStr = me->query_temp("tiejiang/strength");
        intDamage = me->query_temp("tiejiang/damage");

        me->set_temp("tiejiang/weight", intWei);
        me->set_temp("tiejiang/maxstr", intPt);
        me->delete_temp("tiejiang/zhu");

        write("杀伤力[" + intDamage + "] / 耐用度[" + intStr + "] / 锋利度[" + intSharp + "] / 重量(越大越轻) [" + intWei + "]\n");

        message_vision("\n"HIR"$N开始打铁了。\n"NOR,me);
        message_vision("\n"HIY"$N弄得全身都是汗。\n"NOR,me);
        
        
        //Stop Call Out
        remove_call_out("finish");

        //Call Function with Time Limit
    call_out("finishb",20+random(6),me);



        return 1;
}

void finishb(object me)
{
        int intPt, intWei, intSharp, intStr, intDamage;

        intWei = me->query_temp("tiejiang/weight");
        intSharp = me->query_temp("tiejiang/sharp");
        intStr = me->query_temp("tiejiang/strength");
        intDamage = me->query_temp("tiejiang/damage");


        message_vision("\n"HIC"武器打造好了。\n"NOR,me);
        write("请问这把武器要叫什么名字(英文)[请用 enter 名字]？\n");

        add_action("do_nameb", "enter");
        
        return;

}

int do_nameb(string arg)
{
        object me;
        me = this_player();

        remove_action("do_nameb", "enter");
        me->set_temp("tiejiang/wename", arg);

        write("请问这把武器要叫什么名字(中文)[请用 enter 名字]？\n");

        add_action("do_cnameb", "enter");
        
        return 1;
}


int do_cnameb(string arg)
{
        object me, ob;
        int intPt, intWei, intSharp, intStr, intDamage, intdam;
        string strEName, strCName;

        me = this_player();


        remove_action("do_cnameb", "enter");

        intWei = me->query_temp("tiejiang/weight");
        intSharp = me->query_temp("tiejiang/sharp");
        intStr = me->query_temp("tiejiang/strength");
        intDamage = me->query_temp("tiejiang/damage");
        strEName = me->query_temp("tiejiang/wename");
        strCName = arg;
        intdam = intDamage * 2;


        me->set("tiejiang/weight", intWei);
        me->set("tiejiang/sharp", intSharp);
        me->set("tiejiang/strength", intStr);
        me->set("tiejiang/damage", intDamage);
        me->set("tiejiang/adamage", intdam);
        me->set("tiejiang/wname", strCName);
        me->set("tiejiang/wnamee", strEName);


        ob = new("/newjob/tiejiang/obj/sblade");
//      ob->set("name", strCName);
//      ob->set("id", strEName);
        ob->set("long", "杀伤力[" + intDamage + "] / 耐用度[" + intStr + "] / 锋利度[" + intSharp + "] / 重量(越大越轻) [" + intWei + "]\n");
        ob->set("tiejiang/weight", intWei);
        ob->set("tiejiang/sharp", intSharp);
        ob->set("tiejiang/strength", intStr);
        ob->set("tiejiang/damage", intDamage);
        ob->set("tiejiang/adamage", intdam);
        ob->set("tiejiang/wname", strCName);
        ob->set("tiejiang/wnamee", strEName);
        
//      ob->set("tiejiang/weight", intWei);
//      ob->set("tiejiang/sharp", intSharp);
//      ob->set("tiejiang/strength", intStr);
//      ob->set("tiejiang/damage", intDamage);
//      ob->apply_damage(intdam);
        ob->move(me);

        message_vision("\n"HIR"$N打造完毕了，看起来$N似乎很满意。\n"NOR,me);    
        me->improve_skill("tiejiang", 5+random(5) ); 
        me->improve_skill("datieshu", 5+random(5) );

        return 1;
}











//***********************************************************
//***********************************************************
//******************* INPUT FOR ARMOR ***********************
//***********************************************************
//***********************************************************

int do_damagea(string arg)
{
        //Declear Varible
        object me;
        int intPt, intDamage, intX;
        
        //Define me
        me = this_player();

        //getting data
        intPt = me->query_temp("tiejiang/maxstr");
        
        //Convert Arg Format from String to Int
        intX = atoi(arg);

        //Calculation
        intPt = intPt - intX;

        //Error Checking
        if ( intPt < 0 )
                return notify_fail("点数超过，请再输入一次");

        //Delete action
        remove_action("do_damagea", "add");


        //Calculate damage
        intDamage = 20 + intX;

        me->set_temp("tiejiang/damage", intDamage);
                
        me->set_temp("tiejiang/maxstr", intPt);
        

        write("请输入耐用度: (所剩点数 " + intPt + ")[指令 - add 点数]\n");

        add_action("do_strengtha", "add");      

        return 1;
}

int do_strengtha(string arg)
{
        object me;
        int intPt, intStr, intX;
        
        me = this_player();

        intPt = me->query_temp("tiejiang/maxstr");

        intX = atoi(arg);

        intPt = intPt - intX;


        intStr = 25 + intX;

        if ( intPt < 0 )
                return notify_fail("点数超过，请再输入一次");

        remove_action("do_strengtha", "add");

        me->set_temp("tiejiang/strength", intStr);
        me->set_temp("tiejiang/maxstr", intPt);

        write("请输入纯度: (所剩点数 " + intPt + ")[指令 - add 点数]\n");

        add_action("do_sharpa", "add");

        return 1;
}

int do_sharpa(string arg)
{
        object me;
        int intPt, intSharp, intX;
        
        me = this_player();

        intPt = me->query_temp("tiejiang/maxstr");

        intX = atoi(arg);

        intPt = intPt - intX;

        if ( intPt < 0 )
                return notify_fail("点数超过，请再输入一次");

        remove_action("do_sharpa", "add");

        intSharp = 20 + intX;

        me->set_temp("tiejiang/sharp", intSharp);
        me->set_temp("tiejiang/maxstr", intPt);

        write("请输入重量(越大越轻): (所剩点数 " + intPt + ")[指令 - add 点数]\n");

        add_action("do_weighta", "add");

        return 1;
}

int do_weighta(string arg)
{
        object me;
        int intPt, intWei, intSharp, intStr, intDamage, intX;
        
        me = this_player();

        intPt = me->query_temp("tiejiang/maxstr");
        intX = atoi(arg);
        intPt = intPt - intX;

        if ( intPt < 0 )
                return notify_fail("点数超过，请再输入一次");

        remove_action("do_weighta", "add");

        intWei = 10 + intX;
        intSharp = me->query_temp("tiejiang/sharp");
        intStr = me->query_temp("tiejiang/strength");
        intDamage = me->query_temp("tiejiang/damage");

        me->set_temp("tiejiang/weight", intWei);
        me->set_temp("tiejiang/maxstr", intPt);
        me->delete_temp("tiejiang/zhu");

        write("坚硬度[" + intDamage + "] / 耐用度[" + intStr + "] / 纯度[" + intSharp + "] / 重量(越大越轻) [" + intWei + "]\n");

        message_vision("\n"HIR"$N开始打铁了。\n"NOR,me);
        message_vision("\n"HIY"$N弄得全身都是汗。\n"NOR,me);
        
        
        //Stop Call Out
        remove_call_out("finisha");

        //Call Function with Time Limit
    call_out("finisha",20+random(6),me);



        return 1;
}

void finisha(object me)
{
        int intPt, intWei, intSharp, intStr, intDamage;

        intWei = me->query_temp("tiejiang/weight");
        intSharp = me->query_temp("tiejiang/sharp");
        intStr = me->query_temp("tiejiang/strength");
        intDamage = me->query_temp("tiejiang/damage");


        message_vision("\n"HIC"防具打造好了。\n"NOR,me);
        write("请问这件防具要叫什么名字(英文)[请用 enter 名字]？\n");

        add_action("do_namea", "enter");
        
        return;

}

int do_namea(string arg)
{
        object me;
        me = this_player();

        remove_action("do_namea", "enter");
        me->set_temp("tiejiang/wename", arg);

        write("请问这件防具要叫什么名字(中文)[请用 enter 名字]？\n");

        add_action("do_cnamea", "enter");
        
        return 1;
}


int do_cnamea(string arg)
{
        object me, ob;
        int intPt, intWei, intSharp, intStr, intDamage, intdam;
        string strEName, strCName;

        me = this_player();


        remove_action("do_cnamea", "enter");

        intWei = me->query_temp("tiejiang/weight");
        intSharp = me->query_temp("tiejiang/sharp");
        intStr = me->query_temp("tiejiang/strength");
        intDamage = me->query_temp("tiejiang/damage");
        strEName = me->query_temp("tiejiang/wename");
        strCName = arg;
        intdam = intDamage * 2;


        me->set("tiejiang/weight", intWei);
        me->set("tiejiang/sharp", intSharp);
        me->set("tiejiang/strength", intStr);
//        me->set("tiejiang/damage", intDamage);
        me->set("tiejiang/adamage", intdam);
        me->set("tiejiang/wname", strCName);
        me->set("tiejiang/wnamee", strEName);


       ob = new("/newjob/tiejiang/obj/sarmor");
//      ob->set("name", strCName);
//      ob->set("id", strEName);
        ob->set("long", "坚硬度[" + intDamage + "] / 耐用度[" + intStr + "] / 纯度[" + intSharp + "] / 重量(越大越轻) [" + intWei + "]\n");
        ob->set("tiejiang/weight", intWei);
        ob->set("tiejiang/sharp", intSharp);
        ob->set("tiejiang/strength", intStr);
        ob->set("tiejiang/damage", intDamage);
        ob->set("tiejiang/adamage", intdam);
        ob->set("tiejiang/wname", strCName);
        ob->set("tiejiang/wnamee", strEName);
ob->set("tiejiang/damage", intDamage);
        
//      ob->set("tiejiang/weight", intWei);
//      ob->set("tiejiang/sharp", intSharp);
//      ob->set("tiejiang/strength", intStr);
//      ob->set("tiejiang/damage", intDamage);
//      ob->apply_damage(intdam);
        ob->move(me);

        message_vision("\n"HIR"$N打造完毕了，看起来$N似乎很满意。\n"NOR,me);    
        me->improve_skill("tiejiang", 5+random(5) ); 
        me->improve_skill("datieshu", 5+random(5) );

        return 1;
}

