// by 奈何(naihe) 2002-04-10  于茂名

#include <ansi.h>
inherit NPC;
inherit F_DEALER;
// 这个F_DEALER是什么意思？

void create()
{
        set_name(HIW"ATM柜员机"NOR, ({"atm","atm naihe"}));
        set("nickname", HIG"神州银行"NOR);
	set("title",HIC"机器人工厂荣誉出品"NOR);
        set("long","这是一台神州银行的"HIW"ATM"NOR"自动柜员机，人形模样，很先进的。\n\n");
        set("gender", "铁性");
        set("age", 101);

        set("str", 60);
        set("int", 30);
        set("dex", 30);
        set("con", 30);
        set("max_jing", 100000);
        set("jing", 100000);
	set("max_qi",100000);
	set("qi",100000);
        set("shen", 1000);

	set_skill("dodge", 400);
	set_skill("force", 400);
	set_skill("ziyin-yin",400);

        set("combat_exp", 52013140);
        set("shen_type", 1);
        set("attitude", "friendly");
//      set("env/wimpy", 50);

        setup();
        add_money("coin", 1);
/*      add_money("silver", 88);
        add_money("gold", 1);
        carry_object("/d/forest/npc/obj/gebu-changpao")->wear();
        carry_object(__DIR__"obj/tiesuanpan")->wield();
 恩，这几句是他身上的钱、衣服和铁算盘。分别是带着、穿着和拿着。 */
}

void init()
{
        ::init();
        add_action("do_check", "check");
        add_action("do_check", "chazhang");
        add_action("do_deposit", "deposit");
        add_action("do_deposit", "cun");
        add_action("do_withdraw", "withdraw");
        add_action("do_withdraw", "qu");
}

int do_check()
{
        string what;
        int amount;
        object what_ob;
        object me = this_player();
        // here we use 3 units to display bank infos
        int total = (int)this_player()->query("balance");

        if (!total || total < 0) {
                this_player()->set("balance", 0);
                write("柜员机显示：你的存款为零。\n");
                return 1;
        }
        write("柜员机显示：你的存款为" +
                MONEY_D->money_str(total) + "。\n");

if ( me->query("balance") > 100000000 )
        {
                write("柜员机显示：你的存款已经超出上限。\n");
me->set("balance",100000000);
      total = (int)this_player()->query("balance");
                write("柜员机显示：你的存款为" +
                        MONEY_D->money_str(total) + "\n");
        }

        return 1;
}

int do_deposit(string arg)
{
        string what;
        int amount;
        object what_ob, me;

        me = this_player();

        if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
        return notify_fail("命令格式：deposit:cun <数量> <货币单位>\n");

        if ( what == "cash" || what == "thousand-cash" || what == "thousand-cash_money" )
        return notify_fail("柜员机显示：本机不受理伪造的银票进行业务。\n");

        what_ob = present(what + "_money", me);
        if (!what_ob)
        return notify_fail("你身上没有带这种钱。\n");

        if (amount < 1)
        return notify_fail("你想存多少" + what_ob->query("name") + "？\n");

        if ((int)what_ob->query_amount() < amount)
        return notify_fail("你带的" + what_ob->query("name") + "不够。\n");

if ( (me->query("balance") + amount * what_ob->query("base_value")) >= 100000000 )
        return notify_fail("柜员机显示：你的帐号金额已满，不能存钱。\n");

        if (amount * what_ob->query("base_value") >= 500000)
        log_file("MONEY", sprintf("%s(%s)于%s在柜员机存了%s两%s。\n",
//这里是一个LOG记录吧？？？
                me->query("name"), getuid(me), ctime(time()), chinese_number(amount), what_ob->query("name")));

        // Depositing the Money

        what_ob->add_amount(-amount);

        me->add("balance", what_ob->query("base_value") * amount);
        message_vision(sprintf("$N拿出%s%s%s，小心翼翼地存进了柜员机。\n", 
        chinese_number(amount), what_ob->query("base_unit"), 
        what_ob->query("name")), me);

        return 1;
}

int do_withdraw(string arg)
{
        int amount, v;
        string what;
        object me;

        if (query_temp("busy"))
                return notify_fail("柜员机正忙，请稍候。\n");

        me = this_player();
        
        if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
        return notify_fail("命令格式：withdraw|qu <数量> <货币单位>\n");

        if (amount < 1)
        return notify_fail("你的意思是要存钱？？？\n");

        if (amount > 200)
        return notify_fail("你每次最多允许取二百两。\n");

        if (file_size("/clone/money/" + what + ".c") < 0)
        return notify_fail("你想取出什么钱？铁钱？木钱？榆钱？……\n");

        what = "/clone/money/" + what;
        if ((v = amount * what->query("base_value")) > me->query("balance"))
        return notify_fail("柜员机显示：你的帐号并没有那么多的钱。\n");

        //wight
        if((me->query_encumbrance()+amount *(what->weight()))>me->query_max_encumbrance())
                return notify_fail("你取那么多钱，背得动吗！\n");


        me->add("balance",  -v);
        MONEY_D->pay_player(me, v);

        message_vision(sprintf("$N左看右看，小心地从柜员机里取出%s。\n", MONEY_D->money_str(v)),
                me);

        return 1;
}
