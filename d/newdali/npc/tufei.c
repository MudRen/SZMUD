// Code of ShenZhou

inherit NPC;

void create()
{
        set_name("����", ({ "tu fei", "fei"}));
        set("long", 

"������ȥ������֣���üŭĿ��������⡣�������µ�Ҳ�е㹦��\n");
        set("gender", "����");
        set("age", 30+random(15));
	set("attitude", "aggressive");
        set("combat_exp", 14000+random(4000));
        set_skill("unarmed", 50);
        set_skill("blade", 45);
        set_skill("dodge", 55);
        set_skill("ding-unarmed", 30+random(10));
	set_skill("parry", 55+random(10));
	 set_skill("luan-blade", 40+random(5));
	 map_skill("blade", "luan-blade");
	 map_skill("parry", "luan-blade");
        map_skill("unarmed", "ding-unarmed");
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 40);
        set("shen_type", -1);
        setup();
        add_money("silver", random(30));
         carry_object("/clone/armor/cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();

}
/*
void die()
{
object me = this_player();
object ob = this_object();
say("���˴�һ��������Ҳ��Ҫ������Ĵ��Σ�\n"
   "ֻ�������ͳ�һ����ʬ�������Լ����˿��ϣ���һ��ͻ�����һ̲ŧˮ��\n");
destruct(ob);
if(me->query_temp("marks/����1"))
{
me->add("����done1",1);
}
}
*/
