// Code of ShenZhou
inherit NPC;
void create()
{
        set_name("��������", ({ "daizu shouling", "leader" }));
        set("title", "��Դ������");
        set("gender", "����");
        set("long", "����һ�������Ƥ�ĸߴ����ԡ�\n");
        set("age", 45);

        set("str", 20);
        set("int", 30);
        set("dex", 20);
        set("con", 20);
        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 1000);
        set("max_jing", 1000);
        set("shen_type", 1);

        set("combat_exp", 50000);
        set("attitude", "heroism");

        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 60);
        set_skill("blade", 80);
        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 50);

        setup();
	        carry_object("d/dali/obj/mandao")->wield();
                carry_object("d/dali/obj/hupi")->wear();
//                 add_money("gold", 1);



}

