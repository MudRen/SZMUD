// Code of ShenZhou
inherit NPC;

void create()
{
        set_name("����˾", ({ "da tusi" ,"offical"}));
        set("long", 
"����˾�ǰ��������ϣ��ǲ�ɽ����ϵ�ġ������ǳ��ķ�ͷ����ģ�\n"
"ÿ˵һ�仰��ÿ��һ����飬���������Ʊ����Ƕ�����Ĳ���һ����\n"
"�����Ųʳ�ͷ�����𣬽Ų���Ь��������Ų�ͬɫ�ʵı��ǡ�ֻ�� \n"
"��������Ȼ�ظ߾��������������˿������\n");
        set("gender", "����");
        set("age", 47);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 26);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 300);
        set("max_jing", 300);
        set("jiali", 10);
        set("combat_exp", 8000);

        set_skill("force", 30+random(10));
        set_skill("dodge", 30+random(10));
        set_skill("unarmed", 30+random(10));
        set_skill("parry", 30+random(10));
        setup();


	 carry_object("/d/dali/npc/obj/shelllace")->wear();

}


