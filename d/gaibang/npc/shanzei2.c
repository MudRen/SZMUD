// Code of ShenZhou
// shanzeitou.c

inherit NPC;

void create()
{
        set_name("ɽ��", ({ "shanzei","bandit","zei","shanzei" }) );
        set("gender", "����");
        set("age", 15 + random(15));
        set("long",
                "��һ�����ɱ����һ�������ɷ��ģ��������������η��\n");
        set("combat_exp", 500000 + random(25000));
        set("shen_type", -50+ random(25));
        set("attitude", "aggressive");

        set("str", 15 + random(5));
        set("int", 18 + random(5));
        set("con", 15 + random(5));
        set("dex", 20 + random(5));
        set("max_qi", 300 + random(50));
        set("max_jing", 300 + random(50));
        set("neili", 450 + random(50));
        set("max_neili", 450 + random(50));

        set("apply/attack",  50 + random(25));
        set("apply/defense", 50 + random(25));

        set("chat_chance", 10);
        set("chat_msg", ({
                "ɽ���ٺٵ���Ц��: ��ɽ���ҿ������������ԣ���Ҫ�Ӵ˹���������·�ƣ�\n",
        	(: random_move :)
	}) );

        set_skill("sword", 60 + random(10));
        set_skill("parry", 65 + random(10));
        set_skill("strike", 65 + random(10));
        set_skill("force", 60 + random(10));
        set_skill("dodge", 65 + random(20));

        setup();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/armor/beixin")->wear();
        add_money("silver", 10+ random(10));
}

