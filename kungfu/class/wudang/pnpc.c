              // pnpc.c ���� NPC
// CODE BY SCATTER
// 1/12/2002

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void init();

void create()
{
        set_name("�䵱����", ({ "Wudang Dizi", "Wudang", "guard" }));
        set("nickname", "�䵱����");
        set("long", "���������书�Ƿ���\n");
        set("gender", "����");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 60);
        set("combat_exp", 1000000);
        set("score", 700000);
        set("wudang/raozhi", 1);
                set("canzhenwu", 1);

        set_skill("force", 250);
        set_skill("taiji-shengong", 250);
        set_skill("dodge", 250);
        set_skill("tiyunzong",  250);
        set_skill("cuff", 250);
        set_skill("strike", 250);
        set_skill("mian-zhang",250);
        set_skill("parry", 250);
        set_skill("sword", 250);
        set_skill("taiji-jian", 250);
        set_skill("throwing", 250);
        set_skill("literate", 250);
        set_skill("taoism", 250);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("cuff", "taiji-quan");
        map_skill("strike", "mian-zhang");
        map_skill("parry", "taiji-jian");
        map_skill("sword", "taiji-jian");

        prepare_skill("cuff", "chang-quan");
        prepare_skill("strike", "mian-zhang");
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action("sword.raozhi") :),
        }) );

        create_family("�䵱��", 2, "����");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/whiterobe")->wear();
}

void init() 
{ 
    object me = this_player(); 
              
    ::init(); 

        command("say ���ˣ����������䵱�������߽���");
        
        remove_call_out("zwz"); 
    call_out("zwz", 1, me); 
} 


void zwz(object me) 
{ 
        command("zhenwu " + this_object()->query("wudang/killid") +" Dizi Dizi 2");
//        message_vision(CYN"\n�䵱���ӳֽ���Բ����·̫������ֻ�Ǵ��СС������бֱ���ָ�����ԲȦ��Ҫ˵��������˵ֻ��һ�У�Ȼ����һ��ȴ����Ӧ�����\n����������ϸ˿Խ��Խ�࣬���ǻ�����һ����˿�࣬��������������\n"NOR, me);
        this_object()->delete("wudang/killid");
        
        remove_call_out("chkzwz");
        call_out("chkzwz", 10, me);
} 

void chkzwz(object me)
{
        if ( !this_object()->is_fighting() )
        {
                destruct(this_object());
                return;
        }
        call_out("chkzwz", 10, me);
}

