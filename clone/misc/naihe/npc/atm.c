// by �κ�(naihe) 2002-04-10  ��ï��

#include <ansi.h>
inherit NPC;
inherit F_DEALER;
// ���F_DEALER��ʲô��˼��

void create()
{
        set_name(HIW"ATM��Ա��"NOR, ({"atm","atm naihe"}));
        set("nickname", HIG"��������"NOR);
	set("title",HIC"�����˹���������Ʒ"NOR);
        set("long","����һ̨�������е�"HIW"ATM"NOR"�Զ���Ա��������ģ�������Ƚ��ġ�\n\n");
        set("gender", "����");
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
 �����⼸���������ϵ�Ǯ���·��������̡��ֱ��Ǵ��š����ź����š� */
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
                write("��Ա����ʾ����Ĵ��Ϊ�㡣\n");
                return 1;
        }
        write("��Ա����ʾ����Ĵ��Ϊ" +
                MONEY_D->money_str(total) + "��\n");

if ( me->query("balance") > 100000000 )
        {
                write("��Ա����ʾ����Ĵ���Ѿ��������ޡ�\n");
me->set("balance",100000000);
      total = (int)this_player()->query("balance");
                write("��Ա����ʾ����Ĵ��Ϊ" +
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
        return notify_fail("�����ʽ��deposit:cun <����> <���ҵ�λ>\n");

        if ( what == "cash" || what == "thousand-cash" || what == "thousand-cash_money" )
        return notify_fail("��Ա����ʾ������������α�����Ʊ����ҵ��\n");

        what_ob = present(what + "_money", me);
        if (!what_ob)
        return notify_fail("������û�д�����Ǯ��\n");

        if (amount < 1)
        return notify_fail("��������" + what_ob->query("name") + "��\n");

        if ((int)what_ob->query_amount() < amount)
        return notify_fail("�����" + what_ob->query("name") + "������\n");

if ( (me->query("balance") + amount * what_ob->query("base_value")) >= 100000000 )
        return notify_fail("��Ա����ʾ������ʺŽ�����������ܴ�Ǯ��\n");

        if (amount * what_ob->query("base_value") >= 500000)
        log_file("MONEY", sprintf("%s(%s)��%s�ڹ�Ա������%s��%s��\n",
//������һ��LOG��¼�ɣ�����
                me->query("name"), getuid(me), ctime(time()), chinese_number(amount), what_ob->query("name")));

        // Depositing the Money

        what_ob->add_amount(-amount);

        me->add("balance", what_ob->query("base_value") * amount);
        message_vision(sprintf("$N�ó�%s%s%s��С������ش���˹�Ա����\n", 
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
                return notify_fail("��Ա����æ�����Ժ�\n");

        me = this_player();
        
        if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
        return notify_fail("�����ʽ��withdraw|qu <����> <���ҵ�λ>\n");

        if (amount < 1)
        return notify_fail("�����˼��Ҫ��Ǯ������\n");

        if (amount > 200)
        return notify_fail("��ÿ���������ȡ��������\n");

        if (file_size("/clone/money/" + what + ".c") < 0)
        return notify_fail("����ȡ��ʲôǮ����Ǯ��ľǮ����Ǯ������\n");

        what = "/clone/money/" + what;
        if ((v = amount * what->query("base_value")) > me->query("balance"))
        return notify_fail("��Ա����ʾ������ʺŲ�û����ô���Ǯ��\n");

        //wight
        if((me->query_encumbrance()+amount *(what->weight()))>me->query_max_encumbrance())
                return notify_fail("��ȡ��ô��Ǯ�����ö���\n");


        me->add("balance",  -v);
        MONEY_D->pay_player(me, v);

        message_vision(sprintf("$N���ҿ���С�ĵشӹ�Ա����ȡ��%s��\n", MONEY_D->money_str(v)),
                me);

        return 1;
}
