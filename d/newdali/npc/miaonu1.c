// Code of ShenZhou
inherit NPC;

void create()
{
        set_name("����Ů��", ({ "miaozu nuzi", "girl" }));
        set("long", 
"����һ��ͷ�����ٵ�����Ů�ӣ�ֻ������һ������Խ����£�������ϥ��\n"
"¶��һ����Բ�����С�ȡ�\n"
);
        set("gender", "Ů��");
        set("age", 20+random(15) );
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 20);
        set("int", 16);
        set("con", 22);
        set("dex", 28);

        set("max_qi", 300);
        set("max_jing", 300);
        set("max_neili", 300);
        set("combat_exp", 4000);
        set_temp("apply/attack",  random(20));
        set_temp("apply/defense", random(20));
        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 30);
        set_skill("parry", 40);
        setup();


	 carry_object("/d/city/obj/heyeli")->wear();
 
	carry_object("/d/city/obj/pink_cloth")->wear();
       

}











