// Code of ShenZhou
inherit NPC;

void create()
{
        set_name("��ū", ({ "e nu", "nu"}));
        set("long", 

"������ȥ������֣���üŭĿ��������⡣�������µ�Ҳ�е㹦�� ��\n");
        set("gender", "����");
        set("age", 30+random(15));
        set("combat_exp", 14000+random(4000));
        set_skill("unarmed", 50);
        set_skill("sword", 45);
        set_skill("dodge", 55);
        set_skill("ding-unarmed", 30+random(10));
	set_skill("parry", 55+random(10));
	 set_skill("san-sword", 40+random(5));
	 map_skill("sword", "san-sword");
	 map_skill("parry", "san-sword");
        map_skill("unarmed", "ding-unarmed");
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 40);
        set("shen_type", -1);
        setup();
        add_money("silver", random(30));
         carry_object("/clone/armor/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();

}

