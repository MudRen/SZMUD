// jing.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
/*
����ʦ̫һ˫�������·��ɣ�ʹ
����ɽ�ɡ��쳤�Ʒ��������İ���м䷭����ȥ���������Ѯ�����ֽý�ȴ������
�ꡣ
����ʦ̫���𳤽�������
����������İ���һһ�Ŀ�����ҹ֮�У�Ψ������΢�⣬�������裬�����ö���֮
�����죬ʮ��ö���������������䡣ֻ�Ǹ�������ôһ�裬��ħ������ȴ�ӵ�Զ�ˡ�
ֻ����������˽е�������ɽ���򻨽���������ף����ս��˴��۽硣��
*/
void create()
{
        set_name("����ʦ̫", ({ "dingjing shitai", "shitai", "dingjing" }) );
        set("gender", "Ů��");
        set("class", "bonze");
        set("age", 45);
        set("attitude", "peaceful");
        set("per", 24);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 2400);
        set("max_neili", 2400);
        set("jiali", 30);
        set("max_qi",2000);
        set("max_jing",1200);
        set("combat_exp", 1000000);
        set("shen_type", 1);

        set_skill("sword", 130);
        set_skill("force", 130);
        set_skill("parry", 130);
        set_skill("dodge", 130);
        set_skill("hengshan-jian", 130);
        set_skill("lingxu-bu", 130);
        set_skill("ding-force", 130);
        map_skill("force", "ding-force");
        map_skill("sword", "hengshan-jian");
        map_skill("parry", "hengshan-jian");
        map_skill("dodge", "lingxu-bu");

        create_family("��ɽ��", 13, "����");
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

