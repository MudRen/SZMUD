// Code of ShenZhou
// newjob/doctor/npc
// By Blacko

#include <ansi.h>
inherit NPC;


void create()
{
        set_name(HIY"������"NOR, ({"yue zunyu", "yue"}) );
        set("nickname", YEL"������"NOR);
        set("gender", "����" );
        set("age", 52);
        set("long",
          "���Ϻ�����ȥ��Ѱ�������̫��ķֱ���ϸ��ȥ�������沿��������\n");
	
    set("attitude", "friendly");
    set("shen_type", 1);

        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);


        set("max_qi", 1050);
        set("max_jing", 500);
        set("neili", 1000);
        set("max_neili", 1000);

        set("combat_exp", 500+random(800));
        set("score", 1000);

        set_skill("force", 20);
        set_skill("dodge", 20);
        set_skill("unarmed", 25+random(10));
        set_skill("parry", 20);
        set_skill("cuff", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 3);

        create_family("�ּ��Ϻ�", 2, "����");

        set("inquiry", ([
            "ͬ����" : "����������ͣӪҵ�����װ�޺�������ˡ�\n"
         

        ]));

        setup();
        
                carry_object("/clone/armor/jinshe-beixin")->wear();
                
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;


        say("������Ц������˵����ӭ��λ" + RANK_D->query_respect(ob)
             + "����������" + "�������Ͼ�����\n");
}
