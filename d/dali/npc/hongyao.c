// Code of ShenZhou
// He hongyao, �κ�ҩ 
// Ryu
#include <ansi.h>
inherit NPC;
//inherit F_VENDOR;
inherit F_DEALER;

void create()
{
	set_name("�κ�ҩ", ({ "he hongyao", "he", "hongyao" }));
        set_color("$YEL$");
	set("title", "�嶾������");
	set("shen_type", 0);

	set("gender", "Ů��");
	set_max_encumbrance(100000000);
	set("age", 45);
	set("long",
		"��Ů�˾���������ţ���ͷ���棬ͷ���ҵ����ѣ�ʮָ����\n"
		"��צ������������ֵ��˺ۣ������Ǳ�����˺ҧ���£��˺���ڲ�\n"
		"����Ŀ��\n");
	set("no_get_from", 1);

      set("no_steal", 1); 
	set("max_jing", 5000);
	set("jing", 5000);
	set("max_jingli", 500);
	set("jingli", 500);
        set("max_qi", 600);
        set("per", 15);
	set("qi", 500);
	set("PKS", 1000000);

	set("vendor_goods", ({
		 DRUG_D("jinchuang"),
		 DRUG_D("sheyao"),
	 }) );


	set_skill("force", 100);
	set_skill("parry", 100);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_temp("apply/attack", 120);
	set_temp("apply/attack", 120);
	set_temp("apply/damage", 50);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	
	setup();
	carry_object(DRUG_D("guiyuan"))->set("quantity", 3);
	carry_object(DRUG_D("yangxin"))->set("quantity", 3);
	carry_object("/d/dali/obj/shedu.c")->set("quantity", 3);
}

void init()
{
	::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
}

void unconcious()
{
	message_vision("\nͻȻ��ֻ��$N����������̨��һ�����ţ����˽�ȥ���������߰��������ˡ�\n",
		this_object());
	destruct(this_object());
}

void die()
{
	message_vision("\n$N���ˡ�\n", this_object());
	destruct(this_object());
}
int do_sell(string arg)
{
        object ob;
        int value;

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("��Ҫ��ʲô��\n");

        if (ob->query("money_id"))
                return notify_fail("��������Ǯ������\n");

        if (is_vendor_good(arg) != "")
                return notify_fail("������ò��ã�\n");

        if (ob->query("medicine") < 1)
                return notify_fail("�ⶫ���㻹���Լ����Űɡ�\n");

		if (ob->query("no_sell") == 1)
				return notify_fail("�ⶫ��С�Ŀɲ��չ���\n");

        value = ob->query("value");
        if (value < 30)
                write(ob->query("name") + "һ�Ĳ�ֵ��\n");
        else if (value > 1000000 )
	return notify_fail("����������С�Ŀ�����\n");
        else {
                message_vision("$N������һ" + ob->query("unit") +
                ob->query("name") + "��$n��\n", this_player(), this_object());
                MONEY_D->pay_player(this_player(), value * 70 / 100);
                if (value < 50)
                        destruct(ob);
                else
                        ob->move(this_object());
			ob->set("quantity", 1);
        }
        return 1;
}
int do_list()
{
        string *goods;
        object *inv;
        int i;

        inv = all_inventory(this_object());

        if (!sizeof(inv) && !arrayp(goods = query("vendor_goods")))
                return notify_fail("Ŀǰû�п������Ķ�����\n");
	printf("�������%s����������Ʒ��\n", query("name"));
        for (i = 0; i < sizeof(inv); i++)
                if (!inv[i]->query("equipped") && !inv[i]->query("money_id"))
                printf("%30-s��%s\n", inv[i]->short(),
                MONEY_D->price_str(inv[i]->query("value") * 6 / 5));
        if (arrayp(goods = query("vendor_goods")))
                for (i = 0; i < sizeof(goods); i++)
                        printf("%30-s��%s\n", goods[i]->short(),
                        MONEY_D->price_str(goods[i]->query("value")));
        return 1;
}
