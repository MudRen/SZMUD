// Code of ShenZhou
inherit NPC;

void create()
{
           set_name("����", ({ "zhang yu", "zhang"}));
        set("long", 
"����һ��ʵ���ɵĸ��֡�\n"
 "���Ǵ�ұȽ�ϲ���ĸ���֮һ��\n");
         set("gender", "����");
        set("age", 33);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 26);
        set("int", 16);
        set("con", 22);
        set("dex", 24);

        set("max_qi", 300);
        set("max_jing", 300);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);
        set("combat_exp", 3000);

        set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("unarmed", 30);
        set_skill("parry", 30);
        setup();
        set("chat_chance", 8);
        set("chat_msg", ({
"����������ڶ�¥�Ĵ���,�ݏ�������ʱ��,ͻȻһ���Ĭ,ǧͷ����ӿ��,������������֡���\n",
"���������ָ��һ���ɶ�,������ָ����Ū,��������̫��,�Ҹ�˵�߾���,лл������������ ����\n",
"�����������������ʲô����,���������,�����������ݵ��غ򡱡�\n",
"�������Ը߸裬�����ĳ��ּ�į,�ջ��ܰ���,��͵͵����������\n",
"�������Ը߸裬��������ͷ,�����ڲŶ�,������Ҫ�����ڲ�ͬ����\n",
"�������Ը߸裬�����˷���ж�,���˱�ϲ�빲,����ȫ�İ���,���ð������þá���\n",

        }) );


carry_object("/d/quanzhou/npc/obj/guazi")->wear(); 

}


