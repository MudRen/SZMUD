inherit NPC;
#include <ansi.h>;
void create()
{
set_name("С��", ({"shizhe" }));
                 set("nickname", HIR "����ʹ��" NOR);
        set("gender", "���");
        set("title", "����");
        set("age", 14);
        set("no_get", 1);
        set("long", "���ǵ����Ŀ����ߣ����ǵ������𡣻�������ô����������������\n");
        set("combat_exp", 2000000);
        set("shen_type", -10000);
        set("attitude", "heroism");
        set("str", 30);
set("canuse_cixin", 1);
set("canuse_guimei", 1);
        set("con", 3000);
        set("int", 5000);
set("dex", 30);
        set("max_jing", 600000);
        set("jing", 60000);
        set("max_qi", 312000);
        set("qi", 31200);
        set("max_jingli", 120000);
        set("jingli", 12000);
        set("max_neili", 1600000);
        set("neili", 160000);
        set_temp("apply/attack", 80000);
        set_temp("apply/defense", 80000);
        set_skill("dodge", 440);
        set_skill("parry", 440);
        set_skill("sword", 440);
        set_skill("force", 440);
        set_skill("strike", 440);        
        set_skill("whip", 440);
        set_skill("pixie-jian", 500);
        set_skill("huagong-dafa", 500); 
        map_skill("dodge", "pixie-jian");        
        map_skill("parry", "pixie-jian");
        map_skill("force", "huagong-dafa");
        map_skill("sword", "pixie-jian");
        set("chat_chance_combat", 80);
        set("chat_msg_combat",
({
                (: command("perform cizu") :),
                (: command("perform ciwan") :),
                (: command("perform cixin") :),
                (: command("perform guimei") :),
}) );
        set("inquiry",([
                 "�����" : "�����������ˣ�������ʲô��ɣ�\n",
                 "����" : "�����ҵĴ������! \n",]));
        setup();
        carry_object("/d/city/obj/tiejia")->wear();
        carry_object("/clone/weapon/qinggang-jian")->wield();
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;


        say("С����аа��Ц��Ц����˵����ӭ��λ" + RANK_D->query_respect(ob)
             + "�����" + "���˾������档\n");
}

