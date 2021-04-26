// Code of ShenZhou
// banker.c
// originally coded by xiang
// 96-02-16 YZC fixed some math problem
// wzfeng changed 2000 7. fix withdraw

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

// Function declearation:
int do_join(string arg);
int do_unjoin(string arg);
int do_yao();
int do_decide();

void create()
{
        set_name("����", ({"huang zhen", "zhen", "huang"}));
        set("nickname", "ͭ��������");
        set("long","���ǻ�ɽ��������Ĵ���ӣ�һ������ģ����\n");
        set("gender", "����");
        set("age", 55);

        set("str", 28);
        set("int", 24);
        set("dex", 28);
        set("con", 28);
        set("max_jing", 100000);
        set("jing", 100000);

        set("shen", 1000);

        set("combat_exp", 300000);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("env/wimpy", 50);

		set("inquiry", ([
                "����" : "����������Լ���(join)��ҵЭ�ᡣ\n",
                "��ҵЭ��" : "���޺�Ʋ���������ҹ�ݲ��ʣ�������ҵЭ�ᣬ�����µ�һ���̲���������������Ŀ�ꡣ\n",
        ]));

        set_skill("cuff", 80);
        set_skill("dodge", 80);
        set_skill("hammer",80);
        set_skill("huashan-shenfa",70);
        set_skill("pishi-poyu",65);
        map_skill("dodge","huashan-shenfa");
        map_skill("cuff", "pishi-poyu");
        prepare_skill("cuff", "pishi-poyu");

        create_family("��ɽ��",21,"����");
        setup();
        add_money("coin", 188);
        add_money("silver", 38);
//      add_money("gold", 1);
        carry_object("/d/forest/npc/obj/gebu-changpao")->wear();
        carry_object(__DIR__"obj/tiesuanpan")->wield();
}

void init()
{
        ::init();
        add_action("do_check", "check");
        add_action("do_check", "chazhang");
        add_action("do_convert", "convert");
        add_action("do_convert", "duihuan");
        add_action("do_deposit", "deposit");
        add_action("do_deposit", "cun");
        add_action("do_withdraw", "withdraw");
        add_action("do_withdraw", "qu");
        add_action("do_rob", "rob");

		// For trade:
		add_action("do_join","join");
        add_action("do_decide","decide");
        add_action("do_yao","yao");
        add_action("do_unjoin","unjoin");
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
//              return notify_fail("���ڱ��̺�û�д�Ǯ��\n");
                write("����Ц������Ҳ�ײ飬���ڱ��̺�û�д�Ǯ��\n");
                return 1;
        }
        write("��������㣺���ڱ��̺Ź�����" +
                MONEY_D->money_str(total) + "\n");

        if ( me->query("balance") > 100000000 )
        {
                write("��������㣺���Ľ���̫���ˣ������͵���ģ��������һЩ���ô�����ã�\n");
                me->set("balance",100000000);
      total = (int)this_player()->query("balance");
                write("��������㣺���ڱ��̺�����ֻ��" +
                        MONEY_D->money_str(total) + "\n");
                command("hehe");
        }

        return 1;
}

int do_convert(string arg)
{
        string from, to;
        int amount, bv1, bv2;
        object from_ob, to_ob,money_temp;
        object me;
        
        me = this_player();

        if (!arg || sscanf(arg, "%d %s to %s", amount, from, to) != 3)
        return notify_fail("�����ʽ��convert|duihuan <����> <���ҵ�λ> to <�»��ҵ�λ>\n");

//      if ( from == "cash" || from == "thousand-cash" || from == "thousand-cash_money" )
//      return notify_fail("����˵������ѽ��ǰЩʱ������˽�����Ʊ���͹�����Ʊ����α��ģ���֪��������������Ʊ���ϣ�\n");

        if ( to == "thousand-cash" || to == "cash" || to == "ten-cash" || to == "hundred-cash" || to == "thousand-cash_money" )
        return notify_fail("����˵������ѽ��ǰЩʱ������˽�����Ʊ��������Ʊ�������ˡ�\n");

        from_ob = present(from + "_money", me);
        to_ob = present(to + "_money", me);

        if (from == to)
        return notify_fail(from_ob->query("name") +"��"+to_ob->query("name")+"�������Ĳ����İ���\n");

        if (!to_ob && file_size("/clone/money/" + to + ".c") < 0)
        return notify_fail("����һ���ʲô��\n");

        if (!from_ob)
        return notify_fail("������û�д�����Ǯ��\n");

        if (amount < 1)
        return notify_fail("�����׬����\n");

        if ((int)from_ob->query_amount() < amount)
        return notify_fail("�����" + from_ob->query("name") + "������\n");
        
        bv1 = from_ob->query("base_value");
        if (!bv1)
        return notify_fail("����������ֵǮ��\n");

        bv2 = to_ob ? to_ob->query("base_value") : call_other("/clone/money/" + to, "query", "base_value" );
        
        if (bv1 < bv2)
                amount -= amount % (bv2 / bv1); 

        if (amount == 0)
        return notify_fail("��Щ" + from_ob->query("name") + "��������\n");
//      printf("����=%d\n ת�����������=%d\n",amount,amount *bv1 / bv2);


                money_temp = new("/clone/money/" + to);
/*              printf("�Լ��ĸ���=%d\nǮ������=%d\n�Լ��������=%d/t",me->query_encumbrance(),
        amount *bv1 / bv2*(money_temp->weight()),me->query_max_encumbrance());
*/

        if((me->query_encumbrance()+amount *bv1 / bv2*(money_temp->weight()))>me->query_max_encumbrance())
        {
                destruct(money_temp);
                return notify_fail("���������ô��Ǯ��̫���ˡ�\n");
        }
        destruct(money_temp);



        from_ob->add_amount(-amount);

        if (!to_ob) {
                to_ob = new("/clone/money/" + to);
                to_ob->set_amount(amount * bv1 / bv2);
                to_ob->move(me);
        }
        else
                to_ob->add_amount(amount * bv1 / bv2);
        
        message_vision(sprintf("$N������ȡ��%s%s%s��������%s%s%s��\n",
        chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
        chinese_number(amount * bv1 / bv2), to_ob->query("base_unit"), 
        to_ob->query("name")), me);

        return 1;
}

int do_deposit(string arg)
{
        string what;
        int amount;
        object what_ob, me;

        me = this_player();

//SKIP BY SCATTER
//        if (me->query("family/family_name") == "ؤ��")
//        return notify_fail("����˵����ؤ����ֵܰﴳ�������£��㻹�ǰ�Ǯ���Խ�������Ӫ�аɣ�\n");

        if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
        return notify_fail("�����ʽ��deposit:cun <����> <���ҵ�λ>\n");

        if ( what == "cash" || what == "thousand-cash" || what == "thousand-cash_money" )
        return notify_fail("����˵������ѽ��ǰЩʱ������˽�����Ʊ���͹�����Ʊ����α��ģ���֪��������������Ʊ���ϣ�\n");

        what_ob = present(what + "_money", me);
        if (!what_ob)
        return notify_fail("������û�д�����Ǯ��\n");

        if (amount < 1)
        return notify_fail("��������" + what_ob->query("name") + "��\n");

        if ((int)what_ob->query_amount() < amount)
        return notify_fail("�����" + what_ob->query("name") + "������\n");

        if ( (me->query("balance") + amount * what_ob->query("base_value")) >= 100000000 )
        return notify_fail("���Ǯ��ô�࣬Ī����ʯ���¼ұ����ˣ���\n");

        if (amount * what_ob->query("base_value") >= 500000)
        log_file("MONEY", sprintf("%s(%s)��%s��Ǯׯ����%s��%s��\n",
                me->query("name"), getuid(me), ctime(time()), chinese_number(amount), what_ob->query("name")));

        // Depositing the Money

        what_ob->add_amount(-amount);

        me->add("balance", what_ob->query("base_value") * amount);
        message_vision(sprintf("$N�ó�%s%s%s����������š�\n", 
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
                return notify_fail("Ӵ����Ǹ�����������æ���ء��������Ժ�\n");

        me = this_player();
        
        if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
        return notify_fail("�����ʽ��withdraw|qu <����> <���ҵ�λ>\n");

        if (amount < 1)
        return notify_fail("�㷢������ȡ������\n");

        if (amount > 1000)
        return notify_fail("��ÿ���������ȡһǧ����\n");

        if (file_size("/clone/money/" + what + ".c") < 0)
        return notify_fail("����ȡ��ʲôǮ��\n");

        what = "/clone/money/" + what;
        if ((v = amount * what->query("base_value")) > me->query("balance"))
        return notify_fail("����Ǯ����ȡ��\n");

        //wight
//      printf("�Լ��ĸ���=%d\nǮ������=%d\n�Լ��������=%d/t",me->query_encumbrance(),
//      amount *(what->weight()),me->query_max_encumbrance());
        if((me->query_encumbrance()+amount *(what->weight()))>me->query_max_encumbrance())
                return notify_fail("���������ô��Ǯ��̫���ˡ�\n");


        me->add("balance",  -v);
//      MONEY_D->pay_player(me, v = v * 9 / 10);
// Disable bank charge.
        MONEY_D->pay_player(me, v);

        message_vision(sprintf("$N��������ȡ��%s��\n", MONEY_D->money_str(v)),
                me);

        return 1;
}

int do_rob(string arg)
{
                  int amount, v;
        string what, victim, item;
        object me, ob;

        me = this_player();

        if (!arg || sscanf(arg, "%s %s", victim, item) != 2)
                  return notify_fail("�����ʽ��rob <����> <����> <���ҵ�λ>\n");

        if ( victim == me->query("id") ) return notify_fail("�αض��һ�٣�\n");

        if(!objectp(ob = present(victim, environment(me))) || !living(ob))
                return notify_fail("����û������ˡ�\n");

    if( ob->query_condition("xs_necromancy") < 0 || !ob->query_temp("block_msg/all", 1) 
                || (me->query("id") != ob->query("xueshan/necromancy_singer")) )
//      if (!ob->query_temp("cursed", 1) || !ob->query_temp("block_msg/all", 1))
                return notify_fail("���˲���ԹԵ����㻰ȡǮ���㣡\n");

        if ( me->query_skill("necromancy", 1) < 60)
                return notify_fail("�㽵������򲻹���\n");

        if(sscanf(item, "%d %s", amount, what)==2) {
                  if (amount < 1)
                  return notify_fail("�����ô���ȡ������Ǯ��\n");
                  if (file_size("/clone/money/" + what + ".c") < 0)
                  return notify_fail("�����ô���ȡ��ʲôǮ��\n");

        if (amount > 1000)
        return notify_fail("����ÿ���������ȡһǧ����\n");

                  what = "/clone/money/" + what;
        if ((v = amount * what->query("base_value")) > ob->query("balance"))
        return notify_fail("���˴��Ǯ����ȡ��\n");

                if((me->query_encumbrance()+amount *(what->weight()))>me->query_max_encumbrance())
                return notify_fail("���������ô��Ǯ��̫���ˡ�\n");


        ob->add("balance",  -v);
// Disable bank charge
      //  MONEY_D->pay_player(me, v = v * 9 / 10);
                  MONEY_D->pay_player(me, v);
        message_vision(HIR"$N��Ц�е���ͷ��" +ob->query("name") +"�����������˼������䡣\n" NOR,  me);
                  message_vision(sprintf(ob->query("name") +"��������ȡ��%s�ԹԵؽ���$N��\n", MONEY_D->money_str(v)), me);

                  return 1;
        }
}
void unconcious()
{
                  message_vision("\nͻȻ��ֻ��$N����������̨��һ�����ţ����˽�ȥ���������
�߰��������ˡ�\n",
                                         this_object());
        destruct(this_object());
}

void attempt_apprentice(object ob)
{
        command("haha");
        command("say ���ѧ����ʴ�������ҿɲ�����");
        return;
}

int do_join(string arg)
{
        object me;
        me = this_player();
        if (!arg || arg != "��ҵЭ��") return notify_fail("������ֵĶ���˵������Ҫ����ʲô������������ҵЭ�ᡣ��\n");
        if (me->query("is_vendor")) return notify_fail("������ֵĶ���˵�������Ѿ��������˰�����\n");
        if (me->query("bad_vendor")) return notify_fail("����̾Ϣ���������ȥ��Ȼ�Ѿ���������ҵЭ�ᣬ���ھͲ�Ҫ���뵱�����ˣ���\n");
        tell_object(me,HIY"��������Ķ���˵����һ����ֻ����һ�λ��������ҵЭ�ᣬ���Ҫ�ú����룬����(decide)�ٸ����ҡ���\n");
        me->set_temp("want_join",1);
        return 1;
}

int do_unjoin(string arg)
{
        object me;
        me = this_player();
        if (!arg || arg != "��ҵЭ��") return notify_fail("������ֵĶ���˵������Ҫ����ʲô������������ҵЭ�ᡣ��\n");
        if (!me->query("is_vendor")) return notify_fail("������ֵĶ���˵���������ڲ����������˰�����\n");
        tell_object(me,HIY"��������Ķ���˵������һ������������ҵЭ�ᣬ����Զ���ܵ������ˣ����Ҫ�ú����룬����(decide)�ٸ����ҡ���\n");
        me->set_temp("want_tuoli",1);
        return 1;
}

int do_decide()
{
	 object ob,me;
        me = this_player();
        if (me->query_temp("want_join"))
        {
                message_vision(HIY"$N����$n���ͷ���ܺã�Ǯ������֮��������������ף���úøɣ����ճ���ͷ�أ�\n"+NOR,this_object(),me);
                me->set("is_vendor",1);
                me->delete_temp("want_join");
                ob = new("/clone/misc/zhizhao");
                ob->move(me);
                message_vision(HIY"$N��һ��" + NOR + ob->name(1) + HIY + "�䷢��$n��\n"+NOR,this_object(),me);
                return 1;
         }
        if (me->query_temp("want_tuoli"))
        {
                message_vision(HIY"$N����$n���ͷ���ðɣ��˸���־���Ӵ��Ժ��������޹ϸ�\n"+NOR,this_object(),me);
                me->delete("is_vendor");
                me->set("bad_vendor",1);
                me->delete_temp("want_tuoli");
                if (ob = present("shangye zhizhao",me));
                message_vision(HIY"$N��$n��" + NOR + ob->name(1) + HIY + "ע���ˡ�\n"+NOR,this_object(),me);
                destruct(ob);
                return 1;
         }
         return notify_fail("���澪�ȵ��ʣ�����Ҫ����ʲôѽ����\n");
}

int do_yao()
{
        object ob,me = this_player();
        if (!me->query("is_vendor")) return notify_fail("����Ц�Ŷ���˵�������ֲ������ˣ�����������Ҫʲô��Ҫ������\n");
        if (present("shangye zhizhao",me)) return notify_fail("����������Ʋ��Ʋ�죺����ҵִ�ղ��Ǻúõ��������ϣ���ô��������Ҫ����\n");
        // if (HEIDIAN_D->is_owner(me->query("id"))) return notify_fail("����Ǻ�Ц��˵�����������Ǵ��ϰ壬��Ҫʲô��ҵִ���أ���\n");

        ob = new("/clone/misc/zhizhao");
        ob->move(me);
        message_vision(HIY"$N��һ��" + NOR + ob->name(1) + HIY + "������$n��\n"+NOR,this_object(),me);
        return 1;
}